/*
  This file is part of EDWP
  (Energy dispatcher work place)
  Copyright (c) 2021 by Volodymyr Nerovnia
  License: Apache 2.0
*/

#include "include/menu.h"

/*********************************************************************** 
  Function: create_menu - Create menu
  ----------------------------------------------------------------------
  m : menu structure
  box_type : structure box decorate
  cp_unselected : unselected
  cp_selected : selected
**************************/
int create_menu(struct menu m, struct box_char box_type, int cp_unselected, int cp_selected) {
  WINDOW *win;
  
  int xb = 0;
  int yb = 0;
  int tm = 1;
  int lm = 2;

  int mr = 0;
  int mc = 0;

  getmaxyx(stdscr, mr, mc);
  paint_menu(win, &yb, &xb, tm, lm, mr, mc, m, box_type, cp_unselected, cp_selected);
  int ch = 0;
  while( ch != KEY_ESC ) {
    int t_mr = 0;
    int t_mc = 0;
    getmaxyx(stdscr, t_mr, t_mc);
    if((mr != t_mr)||(mc != t_mc)) {
      getmaxyx(stdscr, mr, mc);
      //clear();
      //decorate(mc, mr, wd);
      paint_menu(win, &yb, &xb, tm, lm, mr, mc, m, box_type, cp_unselected, cp_selected);
    }
    ch = getch();
    switch (ch) {
      case KEY_UP:
        attron(COLOR_PAIR(cp_unselected));
//        mvwaddwstr(win, m.sel_it + yb + tm, xb + lm, m.mi[m.sel_it].name);
        mvwaddwstr(win, m.sel_it + yb + tm, lm, m.mi[m.sel_it].name);
        if ( m.sel_it != 0) {
          m.sel_it--;
        } else {
          m.sel_it = m.size-1;
        }
        attron(COLOR_PAIR(cp_selected));
        attron(A_BOLD);
//        mvwaddwstr(win, m.sel_it + yb + tm, xb + lm, m.mi[m.sel_it].name);
        mvwaddwstr(win, m.sel_it + yb + tm, lm, m.mi[m.sel_it].name);
        attroff(A_BOLD);
        break;
      case KEY_DOWN:
        attron(COLOR_PAIR(cp_unselected));
//        mvwaddwstr(win, m.sel_it + yb + tm, xb + lm, m.mi[m.sel_it].name);
        mvwaddwstr(win, m.sel_it + yb + tm, lm, m.mi[m.sel_it].name);
        if ( m.sel_it != (m.size-1)) {
          m.sel_it++;
        } else {
          m.sel_it = 0;
        }
        attron(COLOR_PAIR(cp_selected));
        attron(A_BOLD);
//        mvwaddwstr(win, m.sel_it + yb + tm, xb + lm, m.mi[m.sel_it].name);
        mvwaddwstr(win, m.sel_it + yb + tm, lm, m.mi[m.sel_it].name);
        attroff(A_BOLD);
        break;
      case KEY_LEFT:
      case KEY_HOME:
      case KEY_PPAGE:
        attron(COLOR_PAIR(cp_unselected));
//        mvwaddwstr(win, m.sel_it + yb + tm, xb + lm, m.mi[m.sel_it].name);
        mvwaddwstr(win, m.sel_it + yb + tm, lm, m.mi[m.sel_it].name);
        m.sel_it = 0;
        attron(COLOR_PAIR(cp_selected));
        attron(A_BOLD);
//        mvwaddwstr(win, m.sel_it + yb + tm, xb + lm, m.mi[m.sel_it].name);
        mvwaddwstr(win, m.sel_it + yb + tm, lm, m.mi[m.sel_it].name);
        attroff(A_BOLD);
        break;
      case KEY_RIGHT:
      case KEY_END:
      case KEY_NPAGE:
        attron(COLOR_PAIR(cp_unselected));
//        mvwaddwstr(win, m.sel_it + yb + tm, xb + lm, m.mi[m.sel_it].name);
        mvwaddwstr(win, m.sel_it + yb + tm, lm, m.mi[m.sel_it].name);
        m.sel_it = m.size-1;
        attron(COLOR_PAIR(cp_selected));
        attron(A_BOLD);
//        mvwaddwstr(win, m.sel_it + yb + tm, xb + lm, m.mi[m.sel_it].name);
        mvwaddwstr(win, m.sel_it + yb + tm, lm, m.mi[m.sel_it].name);
        attroff(A_BOLD);
        break;
    }
  }
  //delwin(win);
	//touchwin(stdscr);
  //refresh();

  return 0;
}

/*********************************************************************** 
  Function: paint_menu - Paint menu
  ----------------------------------------------------------------------
  win : 
  yb : 
  xb : 
  tm : 
  lm : 
  mr : 
  mc : 
  m : 
  box_type :
  cp_unselected : unselected
  cp_selected : selected
**************************/
int paint_menu(WINDOW *win, int* yb, int* xb, int tm, int lm, int mr, int mc, struct menu m, struct box_char box_type, int cp_unselected, int cp_selected) {
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
  *(xb) = ceil((mc - width) / 2);
  *(yb) = ceil((mr - height) / 2);
  win = create_newwin(height, width, *(yb), *(xb));
//  paint_box(win, *(yb), *(xb), height, width, m.header, box_type, cp_unselected);
  paint_box(win, *(yb), *(xb), height, width, m.header, box_type, cp_unselected);
  for (int i = 0; i < m.size; i++) {
    if (i == m.sel_it) {
      attron(COLOR_PAIR(cp_selected) | A_BOLD);
    } else { 
      attron(COLOR_PAIR(cp_unselected)); 
      attroff(A_BOLD);
    }
//    mvwaddwstr(win, i + *(yb) + tm, *(xb) + lm, m.mi[i].name);
    mvwaddwstr(win, i + tm, lm, m.mi[i].name);
  }
  wrefresh(win);
  return 0;
}

