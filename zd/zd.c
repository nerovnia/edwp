/*
  This file is part of EDWP
  (Energy dispatcher work place)
  Copyright (c) 2021 by Volodymyr Nerovnia
  License: Apache 2.0
*/ 

/*
  gcc zd/zd.c -lncursesw -o zd.out
*/

#include <stdio.h>
#include <locale.h>
#include <curses.h>
//#include <stddef.h>
#include <wchar.h>

#include "../include/zd/zd.h"
#include "../include/zd/init.h"

void test(void);

void curses_init()
{
    initscr();                      // Start ncurses mode
    noecho();                       // Don't echo keystrokes
    cbreak();                       // Disable line buffering
    keypad(stdscr, true);           // Enable special keys to be recorded
}


//struct uchastok uch[3];
//struct eche eche[6];
//struct psk psk[5];

int main(void) {
  char* t_locale = setlocale(LC_ALL, NULL);
  //curses_init();
  setlocale(LC_ALL, "uk_UA.UTF-8");

  init();


  test();
  getch();
  setlocale(LC_CTYPE, t_locale);
  //refresh();                      // Refresh display
  //endwin(); 
  printf("Press any key!\n");
  getch();
  return 0;
}

void test(void) {
  for(int i = 0; i < sizeof(uch)/sizeof(uch[0]); i++) {
    wprintf(L"%ls\n", uch[i].name);
  }
  for(int i = 0; i < sizeof(eche)/sizeof(eche[0]); i++) {
    wprintf(L"ЕЧЕ-%d, дільниця: %ls\n", eche[i].num, eche[i].uch -> name);
  }
}