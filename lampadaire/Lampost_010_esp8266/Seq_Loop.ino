
const long Cue = 294;// 30 cue = 1 sec 15 60 cue = 2 sec 30 donc 3.8 100° de seconde par cue

int BList1[Cue];
int BList2[Cue];
int BList3[Cue];

//int lo = 0;
//int B_lo = 0;

int R_lo = 0;
int G_lo = 0;

int R_l1 = 70;
int G_l1 = 40;

int R_m1 = 100;
int G_m1 = 70;

int R_m2 = 180;
int G_m2 = 130;

int R_hi = 200;
int G_hi = 150;

//          part 1
int RList1[Cue]   = {R_m1, R_l1, R_m1, R_lo, R_lo, R_l1, R_m1, R_l1, R_m1, R_l1,
                     R_m1, R_l1,

                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,

                     R_l1, R_lo, R_m1, R_l1, R_m1, R_l1, R_m1,

                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,


                     R_l1, R_m1, R_l1, R_m1, R_l1,

                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,

                     R_l1, R_m1, R_m2, R_hi, R_m1, R_m2, R_hi, R_m1, R_m2, R_lo,
                     R_lo, R_l1, R_m1, R_m2, R_m1, R_l1,

                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo,

                     R_m2, R_l1, R_m2, R_l1, R_m2, R_l1, R_m2, R_l1, R_m2, R_l1,


                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo,

                     R_m1, R_l1, R_m1,

                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,

                     R_hi, R_l1, R_m2, R_hi, R_m1, R_m2, R_hi, R_m1, R_m2, R_hi,
                     R_m1, R_m2, R_hi, R_m1, R_m2, R_hi, R_m1, R_m2

                    };


int GList1[Cue]   = {G_m1, G_l1, G_m1, G_lo, G_lo, G_l1, G_m1, G_l1, G_m1, G_l1,
                     G_m1, G_l1,

                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,

                     G_l1, G_lo, G_m1, G_l1, G_m1, G_l1, G_m1,

                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,

                     G_l1, G_m1, G_l1, G_m1, G_l1,

                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,

                     G_l1, G_m1, G_m2, G_hi, G_m1, G_m2, G_hi, G_m1, G_m2, G_lo,
                     G_lo, G_l1, G_m1, G_m2, G_m1, G_l1,

                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo,

                     G_m2, G_l1, G_m2, G_l1, G_m2, G_l1, G_m2, G_l1, G_m2, G_l1,


                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo,

                     G_m1, G_l1, G_m1,

                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,

                     G_hi, G_l1, G_m2, G_hi, G_m1, G_m2, G_hi, G_m1, G_m2, G_hi,
                     G_m1, G_m2, G_hi, G_m1, G_m2, G_hi, G_m1, G_m2

                    };

// part 3
int RList2[Cue]   = {R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,

                     R_m2, R_l1, R_hi, R_l1, R_m2, R_hi, R_m2, R_m2, R_m1, R_m1,
                     R_l1, R_l1,

                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,

                     R_hi, R_hi, R_l1, R_m2, R_m1, R_l1, R_m2, R_m1, R_l1, R_m2,
                     R_lo, R_l1, R_lo,

                     R_lo, R_lo, R_lo, R_lo, R_lo,

                     R_hi, R_hi, R_l1, R_m2, R_m1, R_l1, R_m2, R_m1, R_l1, R_m2,
                     R_lo, R_l1, R_lo, R_l1,

                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo,

                     R_m2, R_lo, R_m1, R_lo, R_m2, R_lo, R_m1, R_lo, R_m2,

                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo,

                     R_hi, R_l1, R_m2, R_l1, R_m1, R_hi, R_l1, R_m2, R_l1, R_m1,
                     R_hi,

                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo,

                     R_hi, R_l1, R_hi, R_l1, R_hi, R_l1, R_m2, R_hi, R_l1, R_m2,
                     R_hi, R_m2, R_hi, R_lo, R_hi

                    };

int GList2[Cue]   = {G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,

                     G_m2, G_l1, G_hi, G_l1, G_m2, G_hi, G_m2, G_m2, G_m1, G_m1,
                     G_l1, G_l1,

                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,

                     G_hi, G_hi, G_l1, G_m2, G_m1, G_l1, G_m2, G_m1, G_l1, G_m2,
                     G_lo, G_l1, G_lo,

                     G_lo, G_lo, G_lo, G_lo, G_lo,

                     G_hi, G_hi, G_l1, G_m2, G_m1, G_l1, G_m2, G_m1, G_l1, G_m2,
                     G_lo, G_l1, G_lo, G_l1,

                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo,

                     G_m2, G_lo, G_m1, G_lo, G_m2, G_lo, G_m1, G_lo, G_m2,

                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo,

                     G_hi, G_l1, G_m2, G_l1, G_m1, G_hi, G_l1, G_m2, G_l1, G_m1,
                     G_hi,

                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo,

                     G_hi, G_l1, G_hi, G_l1, G_hi, G_l1, G_m2, G_hi, G_l1, G_m2,
                     G_hi, G_m2, G_hi, G_lo, G_hi

                    };


//          part 2
int RList3[Cue]   = {R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo,

                     R_hi, R_l1, R_m2, R_hi, R_lo, R_l1,

                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,

                     R_l1, R_lo, R_m1, R_lo, R_l1, R_l1, R_lo, R_m1, R_lo, R_l1,
                     R_l1, R_lo, R_l1, R_lo, R_m1, R_l1, R_lo,

                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,

                     R_l1, R_lo, R_l1, R_l1, R_lo, R_l1,

                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo,

                     R_m2, R_l1, R_m2, R_l1, R_lo, R_lo, R_hi, R_m1, R_l1,

                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,

                     R_l1, R_lo, R_l1, R_lo, R_l1, R_l1, R_lo, R_l1,
                     R_l1, R_lo, R_l1, R_lo, R_l1

                    };

int GList3[Cue]   = {G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo,

                     G_hi, G_l1, G_m2, G_hi, G_lo, G_l1,

                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,

                     G_l1, G_lo, G_m1, G_lo, G_l1, G_l1, G_lo, G_m1, G_lo, G_l1,
                     G_l1, G_lo, G_l1, G_lo, G_m1, G_l1, G_lo,

                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,

                     G_l1, G_lo, G_l1, G_l1, G_lo, G_l1,

                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo,

                     G_m2, G_l1, G_m2, G_l1, G_lo, G_lo, G_hi, G_m1, G_l1,

                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, 

                     G_l1, G_lo, G_l1, G_lo, G_l1, G_l1, G_lo, G_l1,
                     G_l1, G_lo, G_l1, G_lo, G_l1

                    };

