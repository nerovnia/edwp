/*
  This file is part of EDWP
  (Energy dispatcher work place)
  Copyright (c) 2021 by Volodymyr Nerovnia
  License: Apache 2.0
*/

#ifndef BOX_H_
#define BOX_H_

#include <curses.h> 
#include <math.h> 
#include <wchar.h> 

/* define color pair */ 
#define WATER_PAIR     1
#define SELECT_ITEM    2
#define HEADER_LINE    3
#define CELLAR_LINE    4
#define BG_COLOR_PAIR  5

struct box_char {
  const int* lt;
  const int* rt;
  const int* lb;
  const int* rb;
  const int* hl;
  const int* vl;
  const int* sp;
};


int paint_box(WINDOW*, int, int, int, int, wchar_t*, struct box_char, int);
int box_header(WINDOW*, int, int, int, wchar_t*);

#endif /* BOX_H_ */