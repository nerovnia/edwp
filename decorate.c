/*
  This file is part of EDWP
  (Energy dispatcher work place)
  Copyright (c) 2021 by Volodymyr Nerovnia
  License: Apache 2.0
*/

#include "include/decorate.h" 


/* Show header and cellar with name of application and copyright*/
int decorate(void) {
  attron(A_BOLD);
  print_fill_string(0, wd.header, HEADER_LINE);
  attroff(A_BOLD);
  print_fill_string(max_row-1, wd.cellar, CELLAR_LINE);
  decorate_screen();
  return 0;
}

/* Show string on all width screen */
int print_fill_string(int y, wchar_t* str, int color_pair) {
  if (wcslen(str) < max_col) {
    wchar_t* header_str = (wchar_t *) malloc((max_col + 1 ) * sizeof(wchar_t));
    int l_sp = abs(ceil(max_col / 2 - wcslen(str)/2));
    for(int i = 0; i < l_sp; i++) {
      *(header_str + i) = L' ';
    }
    int lsp_and_str = (l_sp + wcslen(str));
    int k=0;
    for(int i = l_sp; i < lsp_and_str; i++) {
      *(header_str + i) = str[k];
      k++;
    }
    for(int i = lsp_and_str; i < max_col; i++) {
      *(header_str + i)  = L' ';
    }
    *(header_str + max_col)  = L'\0';
    attron(COLOR_PAIR(color_pair));
    mvaddwstr(y, 0, header_str);
    free(header_str);
  } 
  return 0;
}

int decorate_screen(void) {
    wchar_t* fill_str = (wchar_t *) malloc((max_col + 1 ) * sizeof(wchar_t));
    for(int i = 0; i < max_col; i++) {
      *(fill_str + i) = 0x2591;
    }
    *(fill_str + max_col)  = L'\0';
    attron(COLOR_PAIR(BG_COLOR_PAIR));
    for(int i = 1; i < (max_row - 1); i++) {
      mvaddwstr(i, 0, fill_str);
    }
    free(fill_str);
  return 0;  
}