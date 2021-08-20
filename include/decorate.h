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
#include "main.h"

struct wdecorate {
  wchar_t* header;  
  wchar_t* cellar;  
};

int decorate(void);
int decorate_screen(void);
int print_fill_string(int, wchar_t*, int);

#endif /* DECORATE_H_ */