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
  int num;
  wchar_t* name;
};

struct eche {
  struct uchastok *uch;
  int num;
  int km;
  int pk;
};

struct psk {
  wchar_t* name;
  int km;
  int pk;
};

#endif /* ZD_H_ */