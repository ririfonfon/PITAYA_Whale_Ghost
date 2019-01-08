//          part 2
//int RList2[Cue]   = {R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//                     R_lo, R_lo, R_lo, R_lo,
//
//                     R_hi, R_l1, R_m2, R_hi, R_lo, R_l1,
//
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//
//
//                     R_l1, R_lo, R_m1, R_lo, R_l1, R_l1, R_lo, R_m1, R_lo, R_l1,
//                     R_l1, R_lo, R_l1, R_lo, R_m1, R_l1, R_lo,
//
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//
//                     R_l1, R_lo, R_l1, R_l1, R_lo, R_l1,
//
//
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//
//                     R_m2, R_l1, R_m2, R_l1, R_lo, R_lo, R_hi, R_m1, R_l1,
//
//
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//                     R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo, R_lo,
//
//                     R_l1, R_lo, R_l1, R_lo, R_l1, R_l1, R_lo, R_l1,
//                     R_l1, R_lo, R_l1, R_lo, R_l1
//
//
//
//                    };
//
//int GList2[Cue]   = {G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//                     G_lo, G_lo, G_lo, G_lo,
//
//                     G_hi, G_l1, G_m2, G_hi, G_lo, G_l1,
//
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//
//
//                     G_l1, G_lo, G_m1, G_lo, G_l1, G_l1, G_lo, G_m1, G_lo, G_l1,
//                     G_l1, G_lo, G_l1, G_lo, G_m1, G_l1, G_lo,
//
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//
//                     G_l1, G_lo, G_l1, G_l1, G_lo, G_l1,
//
//
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//
//                     G_m2, G_l1, G_m2, G_l1, G_lo, G_lo, G_hi, G_m1, G_l1,
//
//
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//                     G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo, G_lo,
//
//                     G_l1, G_lo, G_l1, G_lo, G_l1, G_l1, G_lo, G_l1,
//                     G_l1, G_lo, G_l1, G_lo, G_l1
//
//
//
//                    };
