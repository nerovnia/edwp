/*
  This file is part of EDWP
  (Energy dispatcher work place)
  Copyright (c) 2021 by Volodymyr Nerovnia
  License: Apache 2.0
*/

#ifndef MAIN_H_
#define MAIN_H_

#include "decorate.h"
#include "menu.h"

int max_row;
int max_col;

wchar_t* b_str_header;

struct menu m;
struct wdecorate wd;

void init_ncurses(void);
void end_ncurses(void);
void init_headers(void);
void init_color_pairs(void);
void init_main_menu(void);

#endif /* MAIN_H_ */