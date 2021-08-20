/*
  This file is part of EDWP
  (Energy dispatcher work place)
  Copyright (c) 2021 by Volodymyr Nerovnia
  License: Apache 2.0
*/

#include "include/box.h"

/* Show box header */
int box_header(int y, int x, int width, wchar_t* str) {
  int x_pos = x + ceil(width/2 - wcslen(str)/2);
  mvaddwstr(y, x_pos, str);
  return 0;
}

/* Paint wondow box */
int paint_box(int s_y, int s_x, int height, int width, wchar_t* str_header, struct box_char bc, int color_pair) {
  attron(COLOR_PAIR(color_pair));
  for(int y = 0; y < height; y++) {
    for(int x = 0; x < width; x++) {
      if (( x != 0) || ( y !=0) || ( x != (width -1)) || (y != (height -1)))
        mvaddwstr(y + s_y, x + s_x, bc.sp);
      if ( x == 0 ) {
        if ( y == 0) {
          mvaddwstr(y + s_y, x + s_x, bc.lt);
        } else if ( y == (height-1)) {
          mvaddwstr(y + s_y, x + s_x, bc.lb);
        } else {
          mvaddwstr(y + s_y, x + s_x, bc.vl);
        }
      }

      if ( x == (width-1) ) {
        if ( y == 0) {
          mvaddwstr(y + s_y, x + s_x, bc.rt);
        } else if ( y == (height-1)) {
          mvaddwstr(y + s_y, x + s_x, bc.rb);
        } else {
          mvaddwstr(y + s_y, x + s_x, bc.vl);
        }
      }

      if (((y == 0) || (y == (height-1))) && ( x !=0 ) && ( x != (width-1))) {
          mvaddwstr(y + s_y, x + s_x, bc.hl);
      }

      box_header(s_y, s_x, width, str_header);
    }
  }
  return 0;
}