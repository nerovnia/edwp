/*
  This file is part of EDWP
  (Energy dispatcher work place)
  Copyright (c) 2021 by Volodymyr Nerovnia
  License: Apache 2.0
*/

#ifndef FORM_H_
#define FORM_H_

#include <curses.h> 
#include <wchar.h> 
#include "box.h"
#include "control.h"
#include "main.h"

struct form {
  wchar_t* header;
  struct control* ct;
  int size;
  int sel_ct;
};

int create_form(struct form, struct box_char, int, int);
int paint_form(int*, int*, int, int, struct menu, struct box_char, int, int);

#endif /* FORM_H_ */