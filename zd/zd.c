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
#include <wchar.h>

#include "../include/zd/zd.h"
#include "../include/zd/init.h"

void test(void);

char* t_locale;

void terminal_init() {
  t_locale = setlocale(LC_ALL, NULL);
  setlocale(LC_ALL, "uk_UA.UTF-8");
}

void terminal_close() {
  setlocale(LC_CTYPE, t_locale);
}

int main(void) {
  terminal_init();

  init();
  test();

  wprintf(L"Press any key!\n");
  getch();

  terminal_close();
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