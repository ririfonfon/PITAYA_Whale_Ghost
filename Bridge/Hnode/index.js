var dgram = require('dgram');
const EventEmitter = require('events');

var PORT_SERVER = 3738;          // Working UDP port

var TIME_TICK = 100;      // Watchdog timer ms
var TIME_OFFLINE = 2000;  // Offline Time
var TIME_GONE = 3000;     // Gone Time

var NLEDS_STRIPS = 110;    // N leds per strips
var NSTRIPS_CLIENT = 6;   // N strips per client

var NLEDS = NLEDS_STRIPS * NSTRIPS_CLIENT;

function log(msg) {
  console.log(msg);
}

class Worker extends EventEmitter {
  constructor() {
    super();

    this.isRunning  = false;
    this.timer      = null;
    this.timerate   = TIME_TICK;
    this.allowRateChange = true;
  }

  start() {
    if (this.isRunning) this.stop();
    this.isRunning  = true;
    this.emit('start');
    this.next();
  }

  next() {
    var that = this;
    this.timer = setTimeout( function() {
      if (!that.isRunning) return;
      that.emit('tick');
      that.next();
    }, that.timerate);
  }

  stop()  {
    if (this.timer != null) {
      clearTimeout(this.timer);
      this.timer = null;
    }
    this.isRunning  = false;
    this.emit('stop');
  }

  setRate(tr) {
    if (!this.allowRateChange) return;
    this.timerate = Math.round(tr);
    this.emit('fps', Math.round(100000/tr)/100);
    //log('FPS: '+ Math.round(100000/tr)/100);
    //this.timerate = 50;
  }

  lockRate(tr) {
    this.allowRateChange = true;
    this.setRate(tr);
    this.allowRateChange = false;
  }

  unlockRate() {
    this.allowRateChange = true;
  }

}

class Client extends Worker {
  constructor(ip, info) {
    super();
    var that = this;

    this.name = info["name"];

    this.ip = ip;
    this.port = info["port"];

    this.noNews = 0;
    this.udp = null;
    this.infoCounter = 0;
    this.payload = []
    for (var s=0; s<NSTRIPS_CLIENT; s ++)
      this.payload[s] = Buffer.alloc(NLEDS_STRIPS*3, 0);

    this.setRate(1000/40);

    // send payload at every ticks
    this.on('tick', this.send);

    // stop udp
    this.on('stop', function() {
      if (that.udp != null) {
        that.udp.close();
        that.udp = null;
      }
      that.infoCounter = 0;
    });

  }

  _set(strip, buffer) {
    this.payload[strip] = buffer;
  }

  //
  // args:  [ [ [r,g,b], [r,g,b], ... ], ... ]
  //
  setAll(rgbs) {
    for (var strip = 0; strip <rgbs.length; strip += 1)
      this.setStrip(strip, rgbs[strip]);

  }

  //
  // args: strip n°, [ [r,g,b], [r,g,b], ... ]
  //
  setStrip(strip, rgbs) {
    for (var led = 0; led < rgbs.length; led += 1) {
      this.setLed(strip, led, rgbs[led])
    }
  }

  //
  // args: strip n°, led n°, [r,g,b]
  //
  setLed(strip, led, rgb) {
    var key = led * 3;
    if (rgb[0] == 0) rgb[0] = 1;
    if (rgb[1] == 0) rgb[1] = 1;
    if (rgb[2] == 0) rgb[2] = 1;
    this.payload[strip][key + 0] = rgb[0];
    this.payload[strip][key + 1] = rgb[1];
    this.payload[strip][key + 2] = rgb[2];
  }

  update(ip, info) {

    // re-store info
    this.ip = ip
    this.id = info["id"]
    this.port = info["port"]
    this.version = info["version"]

    // update received: should be running
    if (!this.isRunning) this.start();

    // first info received (since last reset)
    if (this.infoCounter == 0) this.emit('online');

    // state record
    this.infoCounter += 1;
    this.noNews = 0;

    // inform data received
    this.emit('received', info);
  }

  check( ticksOffline, ticksGone) {
    this.noNews += 1;

    // state control
    if (this.noNews == ticksOffline) {
      this.infoCounter = 0;
      this.emit('offline');
    }
    if (this.noNews == ticksGone) this.stop();

  }

  send() {
    var that = this;
    if (this.udp == null) this.udp = dgram.createSocket('udp4');
    for (var s=0; s<NSTRIPS_CLIENT; s++)
      if (this.payload[s] != null) {
        var header = Buffer.alloc(2,0)
        header[0] = this.id
        header[1] = s+1
        var packet = Buffer.concat([header ,this.payload[s]]);
        this.udp.send(packet, 0, packet.length, this.port, this.ip, function(err, bytes) {
            if (err) {
              if (err.code == 'ENETUNREACH' || err.code == 'EADDRNOTAVAIL') {
                console.log('\nWarning: the server lost connection to the network');
                that.stop();
              }
              else if (err.code == 'ECANCELED') {
                console.log('\nWarning: Node comm error ECANCELED');
                that.stop();
              }
              else throw err;
            }
            else that.emit('sent', packet);
        });
      }
  }

  randomize() {
    // random payload
    for (var s=0; s<NSTRIPS_CLIENT; s++) {
      var data = Buffer.alloc(NLEDS*3 );
      for (var k = 0; k<NLEDS*3; k+=1)
        data[k] = Math.floor(Math.random() * 255)
      this._set(s, data);
    }
  }

}

class Server extends Worker {
  constructor() {
    super();
    var that = this;
    this.clients = {};

    this.on('start', function() {
      that.udpSocket.bind(PORT_SERVER);
    });

    this.on('stop', function() {
      that.udpSocket.close();
      for (var name in that.clients) that.clients[name].stop();
    });

    this.on('tick', function() {
      var TICK_OFFLINE = Math.round(TIME_OFFLINE/that.timerate);
      var TICK_GONE = Math.round(TIME_GONE/that.timerate);
      for (var name in that.clients) that.clients[name].check(TICK_OFFLINE, TICK_GONE);
    });

    this.configureUDP();
  }

  configureUDP() {
    var that = this;

    this.udpSocket = dgram.createSocket('udp4');

    this.udpSocket.on('error', (err) => {
      console.log(`socket error:\n${err.stack}`);
      that.udpSocket.close();
    });

    this.udpSocket.on('listening', function () {
        var address = that.udpSocket.address();
        console.log('UDP Server listening on port ' + address.port);
    });

    // Message received from client
    this.udpSocket.on('message', function (message, remote) {
        var ip = remote.address;
        //var info = JSON.parse(message.toString('UTF-8'));
        var msg = message.toString('UTF-8').split(' ')
        var info = {
          'name': msg[0]+'-'+msg[1],
          'port': 3737,
          'id': msg[1],
          'version': msg[2]
        }
        var name = info['name'];

        // Create client if new
        if (that.clients[name] == null) {
          that.clients[name] = new Client(ip, info);
          that.emit('newnode', that.clients[name]);
          // console.log(ip, info)
        }

        // Update client
        that.clients[name].update(ip, info);
    });
  }

  getNodeByIP(ip) {
    for (var name in this.clients)
      if (this.clients[name].ip == ip) return this.clients[name];
  }

  getNodeByName(name) {
    return this.clients[name];
  }

  getAllNodes() {
    var nodes = [];
    for (var name in this.clients) nodes.push(this.clients[name]);
    return nodes;
  }

  setAll(rgb) {
    for (var name in this.clients)
      for(var strip=0; strip < NSTRIPS_CLIENT; strip += 1)
        for(var led=0; led < NLEDS_STRIPS; led += 1)
          this.clients[name].setLed(strip, led, rgb);
  }

  blackout() {
    this.setAll([0,0,0]);
  }

}

// Export as module
exports.Server = Server;
