/*
  This file is part of EDWP
  (Energy dispatcher work place)
  Copyright (c) 2021 by Volodymyr Nerovnia
  License: Apache 2.0
*/

#include <locale.h>
#include <curses.h> 
#include <stdlib.h> 
#include <math.h> 
#include <wchar.h> 

#include "include/box.h"
#include "include/menu.h"
#include "include/form.h"
#include "include/decorate.h"
#include "include/main.h"
#include "include/window.h"
#include "include/init.h"

int data_init(void);

//wchar_t str_header[] = L"Про програму...";

int main() {
  //WINDOW *form;

  init_ncurses();
  data_init();

  decorate(max_col, max_row, wd);

  //create_form(WATER_PAIR);
  //win();
  create_menu(m, B_DOUBLE, SELECT_ITEM, WATER_PAIR);
  //touchwin(stdscr);
  //refresh();
  getch();
  end_ncurses();
  return 0;
}

/* Init data */
int data_init(void) {
  init_headers();
  init_color_pairs();  
  init_main_menu();
  return 0;
}

void init_headers(void) {
  //b_str_header = str_header;

  /* Init header/cellar to decorate main window */
  wd.header = L"-= Energy dispatcher work place =-";
  wd.cellar = L"Copyright (c) 2021 by Volodymyr Nerovnia";
}

void init_color_pairs(void) {
  /* Init color pairs */
  init_pair(WATER_PAIR, COLOR_CYAN, COLOR_BLUE);
  init_pair(SELECT_ITEM, COLOR_YELLOW, COLOR_GREEN);

  init_pair(HEADER_LINE, COLOR_WHITE, COLOR_BLUE);
  init_pair(CELLAR_LINE, COLOR_BLUE, COLOR_CYAN);

  init_pair(BG_COLOR_PAIR, COLOR_CYAN, COLOR_BLUE);
}

void init_ncurses(void) {
  initscr();
  getmaxyx(stdscr, max_row, max_col);  	
  setlocale(LC_ALL, "");
  mousemask( ALL_MOUSE_EVENTS, NULL); 
  noecho();
  curs_set(FALSE);
  keypad (stdscr, TRUE);
  cbreak();
  start_color();
}

void end_ncurses(void) {
  nocbreak();
  curs_set(TRUE);
  endwin();
}



