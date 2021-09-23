/*
  This file is part of EDWP
  (Energy dispatcher work place)
  Copyright (c) 2021 by Volodymyr Nerovnia
  License: Apache 2.0
*/ 

/*
  gcc zd/zd.c -lncursesw -o zd.out
*/

#include<stdio.h>
#include <locale.h>
#include<curses.h>
//#include <stddef.h>
#include <wchar.h>

#include"include/zd/zd.h"

void test(void);

void curses_init()
{
    initscr();                      // Start ncurses mode
    noecho();                       // Don't echo keystrokes
    cbreak();                       // Disable line buffering
    keypad(stdscr, true);           // Enable special keys to be recorded
}

struct uchastok uch[3];
struct eche eche[7];

void main(void) {
  uch[0].num = 0;
  uch[0].name = L"Державний кордон (РФ) - Ніжин";
  uch[1].num = 1;
  uch[1].name = L"Конотоп - Ворожба";
  uch[2].num = 2;
  uch[2].name = L"Бахмач-Пас. - Державний кордон (БР)";

  eche[0].uch = &uch[0];
  eche[0].num = 14;
  eche[0].km = 519;
  eche[0].pk = 3;

  eche[1].uch = &uch[0];
  eche[1].num = 15;
  eche[1].km = 564;
  eche[1].pk = 7;

  eche[2].uch = &uch[0];
  eche[2].num = 16;
  eche[2].km = 616;
  eche[2].pk = 95;

  eche[3].uch = &uch[0];
  eche[3].num = 17;
  eche[3].km = 659;
  eche[3].pk = 2;

  eche[4].uch = &uch[0];
  eche[4].num = 18;
  eche[4].km = 711;
  eche[4].pk = 6;

  eche[5].uch = &uch[1];
  eche[5].num = 38;
  eche[5].km = 72;
  eche[5].pk = 8;
  test();
  printf("Press any key!\n");
  getch();
}

void test(void) {
  char* t_locale = setlocale(LC_ALL, NULL);
  //curses_init();
  //setlocale(LC_CTYPE, "uk_UA.CP1251");
  setlocale(LC_ALL, "uk_UA.UTF-8");
  for(int i = 0; i < sizeof(uch)/sizeof(uch[0]); i++) {
    wprintf(L"%ls\n", uch[i].name);
  }
  getch();
  setlocale(LC_CTYPE, t_locale);
  //refresh();                      // Refresh display
  //endwin(); 
}