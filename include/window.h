/*
  This file is part of EDWP
  (Energy dispatcher work place)
  Copyright (c) 2021 by Volodymyr Nerovnia
  License: Apache 2.0
*/

#ifndef WINDOW_H_
#define WINDOW_H_

#include <curses.h> 

void win(void);
WINDOW *create_newwin(int height, int width, int starty, int startx);

#endif /* WINDOW_H_ */