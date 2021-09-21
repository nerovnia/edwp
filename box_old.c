/*
  This file is part of EDWP
  (Energy dispatcher work place)
  Copyright (c) 2021 by Volodymyr Nerovnia
  License: Apache 2.0
*/

#include "include/box.h"

/*********************************************************************** 
  Function: box_header - Show box header
  win : window object
  y : y position
  x : x position
  width  : width place
  str : string of text
**************************/
int box_header(WINDOW *win, int y, int x, int width, wchar_t* str) {
  int x_pos = x + ceil(width/2 - wcslen(str)/2);
  attron(A_BOLD);
  mvwaddwstr(win, y, x_pos, str);
  attroff(A_BOLD);
  return 0;
}

/*********************************************************************** 
  Function: paint_box - Paint wondow box
  win : window object
  s_y : start y position
  s_x : start x position
  height : height box
  width  : width box
  str_header : header string
  bc :  chars to pain box
  color_pair : color decorate pair
**************************/
int paint_box(WINDOW *win, int s_y, int s_x, int height, int width, wchar_t* str_header, struct box_char bc, int color_pair) {
  attron(COLOR_PAIR(color_pair));
  for(int y = 0; y < height; y++) {
    for(int x = 0; x < width; x++) {
      if (( x != 0) || ( y !=0) || ( x != (width -1)) || (y != (height -1)))
        mvwaddwstr(win, y + s_y, x + s_x, bc.sp);
      if ( x == 0 ) {
        if ( y == 0) {
          mvwaddwstr(win, y + s_y, x + s_x, bc.lt);
        } else if ( y == (height-1)) {
          mvwaddwstr(win, y + s_y, x + s_x, bc.lb);
        } else {
          mvwaddwstr(win, y + s_y, x + s_x, bc.vl);
        }
      }

      if ( x == (width-1) ) {
        if ( y == 0) {
          mvwaddwstr(win, y + s_y, x + s_x, bc.rt);
        } else if ( y == (height-1)) {
          mvwaddwstr(win, y + s_y, x + s_x, bc.rb);
        } else {
          mvwaddwstr(win, y + s_y, x + s_x, bc.vl);
        }
      }

      if (((y == 0) || (y == (height-1))) && ( x !=0 ) && ( x != (width-1))) {
          mvwaddwstr(win, y + s_y, x + s_x, bc.hl);
      }
      box_header(win, s_y, s_x, width, str_header);
    }
  }
  return 0;
}