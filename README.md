# WHALE GHOST

## Arduino ESP32

L'iD et le NODE_SUBNET sont enregistrés dans la mémoire Flash.
Pour les changer il faut décommeneter les #define correspondant.

Si le SUBNET est à 0, l'ESP32 se connectera au wifi "whale" sans mot de passe (ssid défini dans wifi.ino)
Son IP sera 192.168.0.(100+ID)
Le Server devra avoir l'IP 192.168.0.200

Si le SUBNET est > 0, par exemple 2, l'ESP32 se connectera au wifi "whale2" sans mot de passe
Son IP sera 192.168.2.(100+ID)
Le Server devra avoir l'IP 192.168.2.200  


## Antenne

Config Ubiquity:

- Onglet UBNT (le 1er) : 
    - airMAX : DISABLE
    
- Onglet Wireless:
    - Wireless Mode: Access Point
    - SSID: whale (SUBNET 0) // whale1 (SUBNET 1) // whale2 (SUBNET 2)
    - Channel Width: 20Mhz
    - Frequency: à choisir en fonction du lieu (par exemple 2437)
                        ecarter chaque subnet d'au moins 3 frequences.
                        attention: ne pas utiliser la dernière fréquence: elle est incompatible avec ESP32 !!
                        ne pas choisir auto, qui risque d'utiliser la dernière fréquence incompatible avec ESP32 !!
    
    - Output Power: à fond ?
    - Data Rate Module: Default
    - Max TX Rate, Mbps: MCS 15 / auto
    - Security: none
    - RADIUS MAC: disable
    - MAC ACL: disable
    
- Onglet Network:
    - Network Mode: Bridge
    - Disable Network: None
    - Config Mode: Simple
    - Management: Static
    - IP Address: 192.168.SUBNET.20     (SUBNET is 0, 1 or 2)
    - Netmask: 255.255.255.0
    - Gateway IP: 192.168.SUBNET.1
    
- Onglet Advanced:
    - RTS Threshold: 2346 / Off
    - Distance: Auto Adjust
    - Aggregation: DISABLE
    - Multicast Data: Allow
    - Multicast Enhancement: Enable
    - Installer EIRP Control: Disable
    - Extra Reporting: Enable
    - Client Isolation: Disable
    - Sensitivity Threshold, dBm: Off

    
    
    

