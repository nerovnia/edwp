/*
  This file is part of EDWP
  (Energy dispatcher work place)
  Copyright (c) 2021 by Volodymyr Nerovnia
  License: Apache 2.0
*/

#ifndef ZD_H_
#define ZD_H_

#include <wchar.h>

struct type_struct {
  wchar_t* name;
};

struct uchastok {
  unsigned int num;
  wchar_t* name;
} uch[3];

struct eche {
  struct uchastok *uch;
  unsigned int num;
  unsigned int km;
  unsigned int pk;
} eche[6];

struct psk {
  struct uchastok *uch;
  wchar_t* name;
  unsigned int km;
  unsigned int pk;
} psk[5];

#endif /* ZD_H_ */