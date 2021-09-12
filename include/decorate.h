/*
  This file is part of EDWP
  (Energy dispatcher work place)
  Copyright (c) 2021 by Volodymyr Nerovnia
  License: Apache 2.0
*/

#ifndef DECORATE_H_
#define DECORATE_H_

#include <curses.h> 
#include <wchar.h> 
#include <stdlib.h> 
#include <math.h> 
#include "box.h"


struct box_char B_SINGLE;
struct box_char B_DOUBLE;

struct wdecorate {
  wchar_t* header;  
  wchar_t* cellar;  
};

int decorate(int, int, struct wdecorate);
int decorate_screen(int, int);
int print_fill_string(int, int, wchar_t*, int);
WINDOW *create_newwin(int, int, int, int);

#endif /* DECORATE_H_ */