#include <locale.h>
#include <curses.h> 
#include <stdlib.h> 
#include <math.h> 

#include <wchar.h> 

#include "convert.h"

struct box_char {
  const int* lt;
  const int* rt;
  const int* lb;
  const int* rb;
  const int* hl;
  const int* vl;
};

struct box_char B_SINGLE;
struct box_char B_DOUBLE;

int max_row;
int max_col;

wchar_t b_str_header[] = L"Про програму...";

int data_init(void);
int paint_box(int, int, int, int, wchar_t*, struct box_char);
int box_header(int, int, int, wchar_t*);

int main() {
  data_init();
  initscr();

  getmaxyx(stdscr, max_row, max_col);  	
  setlocale(LC_ALL, "");

  noecho();
  curs_set(FALSE);

  start_color();
  init_pair(1, COLOR_YELLOW, COLOR_GREEN);

  paint_box(15, 40, 25, 50, b_str_header, B_DOUBLE);

  refresh();
  getchar();
  curs_set(TRUE);
  endwin();
  return 0;
}


int data_init(void) {
  /* Init structure B_SINGLE */
  B_SINGLE.lt = L"\u250C";
  B_SINGLE.rt = L"\u2510";
  B_SINGLE.lb = L"\u2514";
  B_SINGLE.rb = L"\u2518";
  B_SINGLE.hl = L"\u2500";
  B_SINGLE.vl = L"\u2502";

  /* Init structure B_DOUBLE */
  B_DOUBLE.lt = L"\u2554";
  B_DOUBLE.rt = L"\u2557";
  B_DOUBLE.lb = L"\u255A";
  B_DOUBLE.rb = L"\u255D";
  B_DOUBLE.hl = L"\u2550";
  B_DOUBLE.vl = L"\u2551";
  return 0;
}

int paint_box(int s_y, int s_x, int height, int width, wchar_t* str_header, struct box_char bc) {
  for(int y = 0; y < height; y++) {
    for(int x = 0; x < width; x++) {
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

int box_header(int y, int x, int width, wchar_t* str) {
  int x_pos = x + ceil(width/2 - wcslen(str)/2);
  mvaddwstr(y, x_pos, str);
  return 0;
}

