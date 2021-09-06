/*
  This file is part of EDWP
  (Energy dispatcher work place)
  Copyright (c) 2021 by Volodymyr Nerovnia
  License: Apache 2.0
*/

#include "include/form.h"

/* Create form */
int create_form(struct form m, struct box_char box_type, int cp_unselected, int cp_selected) {
  int xb = 0;
  int yb = 0;
  int tm = 1;
  int lm = 2;
  //paint_form(&yb, &xb, tm, lm, m, box_type, cp_unselected, cp_selected);
  int ch = 0;
  while( ch != KEY_ESC ) {
    int t_mr = 0;
    int t_mc = 0;
    getmaxyx(stdscr, t_mr, t_mc);
    if((max_row != t_mr)||(max_col != t_mc)) {
      getmaxyx(stdscr, max_row, max_col);
      clear();
      //decorate(int max_col, int max_row, struct wdecorate wd);
      //paint_form(&yb, &xb, tm, lm, m, box_type, cp_unselected, cp_selected);
    }
    ch = getch();
    /*
    switch (ch) {
      case KEY_UP:
        attron(COLOR_PAIR(cp_unselected));
        mvaddwstr(m.sel_it + yb + tm, xb + lm, m.mi[m.sel_it].name);
        if ( m.sel_it != 0) {
          m.sel_it--;
        } else {
          m.sel_it = m.size-1;
        }
        attron(COLOR_PAIR(cp_selected));
        mvaddwstr(m.sel_it + yb + tm, xb + lm, m.mi[m.sel_it].name);
        break;
      case KEY_DOWN:
        attron(COLOR_PAIR(cp_unselected));
        mvaddwstr(m.sel_it + yb + tm, xb + lm, m.mi[m.sel_it].name);
        if ( m.sel_it != (m.size-1)) {
          m.sel_it++;
        } else {
          m.sel_it = 0;
        }
        attron(COLOR_PAIR(cp_selected));
        mvaddwstr(m.sel_it + yb + tm, xb + lm, m.mi[m.sel_it].name);
        break;
      case KEY_LEFT:
      case KEY_HOME:
      case KEY_PPAGE:
        attron(COLOR_PAIR(cp_unselected));
        mvaddwstr(m.sel_it + yb + tm, xb + lm, m.mi[m.sel_it].name);
        m.sel_it = 0;
        attron(COLOR_PAIR(cp_selected));
        mvaddwstr(m.sel_it + yb + tm, xb + lm, m.mi[m.sel_it].name);
        break;
      case KEY_RIGHT:
      case KEY_END:
      case KEY_NPAGE:
        attron(COLOR_PAIR(cp_unselected));
        mvaddwstr(m.sel_it + yb + tm, xb + lm, m.mi[m.sel_it].name);
        m.sel_it = m.size-1;
        attron(COLOR_PAIR(cp_selected));
        mvaddwstr(m.sel_it + yb + tm, xb + lm, m.mi[m.sel_it].name);
        break;
    }
    */
  }  
  return 0;
}
/*
int paint_form(int* yb, int* xb, int tm, int lm, struct form m, struct box_char box_type, int cp_unselected, int cp_selected) {
  size_t max_len = wcslen(m.header);
  int width = 0;
  int height = m.size + tm * 2;
  for (int i = 0; i < m.size; i++) {
    int t = wcslen(m.mi[i].name);
    if( t > max_len) {
      max_len = t;
    }
  }
  width = max_len + lm * 2;
  *(xb) = ceil((max_col - width) / 2);
  *(yb) = ceil((max_row - height) / 2);
  paint_box(*(yb), *(xb), height, width, m.header, box_type, cp_unselected);
  for (int i = 0; i < m.size; i++) {
    (i == m.sel_it) ? attron(COLOR_PAIR(cp_selected)) : attron(COLOR_PAIR(cp_unselected));
    mvaddwstr(i + *(yb) + tm, *(xb) + lm, m.mi[i].name);
  }
  refresh();
  return 0;
}

*/

