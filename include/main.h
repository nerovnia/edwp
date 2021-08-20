/*
  This file is part of EDWP
  (Energy dispatcher work place)
  Copyright (c) 2021 by Volodymyr Nerovnia
  License: Apache 2.0
*/

#ifndef MAIN_H_
#define MAIN_H_

#include "menu.h"

int max_row;
int max_col;

wchar_t* b_str_header;
//wchar_t b_str_header[] = L"Про програму...";

struct menu_item m_mi[9];
struct menu m;

struct box_char B_SINGLE;
struct box_char B_DOUBLE;

struct wdecorate wd;

#endif /* MAIN_H_ */