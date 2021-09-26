/*
  This file is part of EDWP
  (Energy dispatcher work place)
  Copyright (c) 2021 by Volodymyr Nerovnia
  License: Apache 2.0
*/

#ifndef ARRAY_H_
#define ARRAY_H_

#include "../zd/zd.h"

enum uz { uch, eche, psk, echk, echs, rrd, echc, aur};

union uArray {
  struct uch  arruch;
  struct eche arreche;
  struct psk  arrpsk;
  struct echk arrechk;
  struct echs arrechs;
  struct rrd  arrrrd;
  struct echc arrechc;
  struct aur  arraur;
};

struct Array {
  enum uz struct_type;
  unsigned int max_size;
  unsigned int now_size;
  union uArray *uArr;
};

void getArrItem(int, union uArray);

void init(void);
void init_arr_uch(void);
void init_arr_eche(void);
void init_arr_psk(void);
void init_arr_echk(void);
void init_arr_echs(void);
void init_arr_rrd(void);
void init_arr_echc(void);
void init_arr_aur(void);

#endif /* ARRAY_H_ */