/*
  This file is part of EDWP
  (Energy dispatcher work place)
  Copyright (c) 2021 by Volodymyr Nerovnia
  License: Apache 2.0
*/

#ifndef MENU_H_
#define MENU_H_

#include <curses.h> 
#include "key.h" 
#include "box.h"
#include "decorate.h"

struct menu_item {
  wchar_t* name;  
};

struct menu {
  wchar_t* header;
  struct menu_item* mi;
  int size;
  int sel_it;
};

int create_menu(struct menu, struct box_char, int, int);
int paint_menu(WINDOW*, int*, int*, int, int, int, int, struct menu, struct box_char, int, int);

#endif /* MENU_H_ */