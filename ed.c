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

/* define color pair */ 
#define WATER_PAIR     1
#define SELECT_ITEM    2
#define HEADER_LINE    3
#define CELLAR_LINE    4

#define KEY_ESC       27

struct box_char {
  const int* lt;
  const int* rt;
  const int* lb;
  const int* rb;
  const int* hl;
  const int* vl;
  const int* sp;
};

struct wdecorate {
  wchar_t* header;  
  wchar_t* cellar;  
};

struct menu_item {
  wchar_t* name;  
};

struct menu {
  wchar_t* header;
  struct menu_item* mi;
  int size;
  int sel_it;
};

int data_init(void);
int paint_box(int, int, int, int, wchar_t*, struct box_char, int);
int box_header(int, int, int, wchar_t*);
int create_menu(struct menu, struct box_char, int, int);
int paint_menu(int*, int*, int, int, struct menu, struct box_char, int, int);
int decorate(void);
int print_fill_string(int, wchar_t*, int);

struct wdecorate wd;

struct box_char B_SINGLE;
struct box_char B_DOUBLE;

int max_row;
int max_col;

wchar_t b_str_header[] = L"Про програму...";

struct menu_item m_mi[9];
struct menu m;

int main() {
  initscr();
  getmaxyx(stdscr, max_row, max_col);  	
  setlocale(LC_ALL, "");
  noecho();
  curs_set(FALSE);
  keypad (stdscr, TRUE);
  start_color();

  data_init();
  decorate();
  create_menu(m, B_DOUBLE, WATER_PAIR, SELECT_ITEM);

  refresh();
  curs_set(TRUE);
  endwin();
  return 0;
}

/* Init data */
int data_init(void) {
  /* Init header/cellar to decorate main window */
  wd.header = L"-= Energy dispatcher work place =-";
  wd.cellar = L"Copyright (c) 2021 by Volodymyr Nerovnia";
  
  /* Init color pairs */
  init_pair(WATER_PAIR, COLOR_CYAN, COLOR_BLUE);
  init_pair(SELECT_ITEM, COLOR_YELLOW, COLOR_GREEN);

  init_pair(HEADER_LINE, COLOR_WHITE, COLOR_BLUE);
  init_pair(CELLAR_LINE, COLOR_BLUE, COLOR_CYAN);

  /* Init menu */
  m.mi = m_mi;
  m.size = 9;
  m.header = L"Пошкодження";
  m.sel_it = 0;

  m_mi[0].name = L"... на к/м      ";
  m_mi[1].name = L"... на АБ       ";
  m_mi[2].name = L"... на ПЕ       ";
  m_mi[3].name = L"... на ПЛ-10кВ  ";
  m_mi[4].name = L"... на ПЛ-0.4кВ ";
  m_mi[5].name = L"... на ПЛ-0.23кВ";
  m_mi[6].name = L"... на КЛ-10кВ  ";
  m_mi[7].name = L"... на КЛ-0.4кВ ";
  m_mi[8].name = L"... на КЛ-0.23кВ";

  /* Init structure B_SINGLE */
  B_SINGLE.lt = L"\u250C";
  B_SINGLE.rt = L"\u2510";
  B_SINGLE.lb = L"\u2514";
  B_SINGLE.rb = L"\u2518";
  B_SINGLE.hl = L"\u2500";
  B_SINGLE.vl = L"\u2502";
  B_SINGLE.sp = L"\x20";

  /* Init structure B_DOUBLE */
  B_DOUBLE.lt = L"\u2554";
  B_DOUBLE.rt = L"\u2557";
  B_DOUBLE.lb = L"\u255A";
  B_DOUBLE.rb = L"\u255D";
  B_DOUBLE.hl = L"\u2550";
  B_DOUBLE.vl = L"\u2551";
  B_DOUBLE.sp = L"\x20";
  return 0;
}

/* Create menu */
int create_menu(struct menu m, struct box_char box_type, int cp_unselected, int cp_selected) {
  int xb = 0;
  int yb = 0;
  int tm = 1;
  int lm = 2;
  paint_menu(&yb, &xb, tm, lm, m, box_type, cp_unselected, cp_selected);
  int ch = 0;
  while( ch != KEY_ESC ) {
    int t_mr = 0;
    int t_mc = 0;
    getmaxyx(stdscr, t_mr, t_mc);
    if((max_row != t_mr)||(max_col != t_mc)) {
      getmaxyx(stdscr, max_row, max_col);
      clear();
      decorate();
      paint_menu(&yb, &xb, tm, lm, m, box_type, cp_unselected, cp_selected);
    }
    ch = getch();
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
  }  
  return 0;
}

int paint_menu(int* yb, int* xb, int tm, int lm, struct menu m, struct box_char box_type, int cp_unselected, int cp_selected) {
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

/* Show box header */
int box_header(int y, int x, int width, wchar_t* str) {
  int x_pos = x + ceil(width/2 - wcslen(str)/2);
  mvaddwstr(y, x_pos, str);
  return 0;
}

/* Show header and cellar with name of application and copyright*/
int decorate(void) {
  print_fill_string(0, wd.header, HEADER_LINE);
  print_fill_string(max_row-1, wd.cellar, CELLAR_LINE);
  return 0;
}

/* Show string on all width screen */
int print_fill_string(int y, wchar_t* str, int color_pair) {
  if (wcslen(str) < max_col) {
    wchar_t* header_str = (wchar_t *) malloc((max_col + 1 )* sizeof(wchar_t));
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
    for(int i = lsp_and_str; i < (max_col); i++) {
      *(header_str + i)  = L' ';
    }
    *(header_str + max_col)  = L'\0';
    attron(COLOR_PAIR(color_pair));
    mvaddwstr(y, 0, header_str);
    free(header_str);
  } 
  return 0;
}
