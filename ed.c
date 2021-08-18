#include <locale.h>
#include <curses.h> 
#include <stdlib.h> 
#include <math.h> 
#include <wchar.h> 

/* define color pair */ 
#define WATER_PAIR     1
#define SELECT_ITEM    2

struct box_char {
  const int* lt;
  const int* rt;
  const int* lb;
  const int* rb;
  const int* hl;
  const int* vl;
  const int* sp;
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

struct box_char B_SINGLE;
struct box_char B_DOUBLE;

int max_row;
int max_col;

wchar_t b_str_header[] = L"Про програму...";

int data_init(void);
int paint_box(int, int, int, int, wchar_t*, struct box_char);
int box_header(int, int, int, wchar_t*);
int create_menu(struct menu);


struct menu_item m_mi[9];
struct menu m;

int main() {
  initscr();

  getmaxyx(stdscr, max_row, max_col);  	
  setlocale(LC_ALL, "");

  noecho();
  curs_set(FALSE);

  start_color();
  data_init();

  attron(COLOR_PAIR(WATER_PAIR));

  create_menu(m);

  refresh();
  getchar();
  curs_set(TRUE);
  endwin();
  return 0;
}


int data_init(void) {
  /* Init color pairs */
  init_pair(WATER_PAIR, COLOR_CYAN, COLOR_BLUE);
  init_pair(SELECT_ITEM, COLOR_YELLOW, COLOR_GREEN);

  /* Init menu */
  m.mi = m_mi;
  m.size = 9;
  m.header = L"Пошкодження";
  m.sel_it = 0;

  m_mi[0].name = L"... на к/м";
  m_mi[1].name = L"... на АБ";
  m_mi[2].name = L"... на ПЕ";
  m_mi[3].name = L"... на ПЛ-10кВ";
  m_mi[4].name = L"... на ПЛ-0.4кВ";
  m_mi[5].name = L"... на ПЛ-0.23кВ";
  m_mi[6].name = L"... на КЛ-10кВ";
  m_mi[7].name = L"... на КЛ-0.4кВ";
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
int create_menu(struct menu m) {
  int xb = 0;
  int yb = 0;
  /* Top and left merging */
  int tm = 1;
  int lm = 2;
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
  xb = ceil((max_col - width) / 2);
  yb = ceil((max_row - height) / 2);
  paint_box(yb, xb, height, width, m.header, B_DOUBLE);
  for (int i = 0; i < m.size; i++) {
    (i == 0) ? attron(COLOR_PAIR(SELECT_ITEM)) : attron(COLOR_PAIR(WATER_PAIR));
    mvaddwstr(i + yb + tm, xb + lm, m.mi[i].name);
  }
  
  return 0;
}

int paint_box(int s_y, int s_x, int height, int width, wchar_t* str_header, struct box_char bc) {
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

int box_header(int y, int x, int width, wchar_t* str) {
  int x_pos = x + ceil(width/2 - wcslen(str)/2);
  mvaddwstr(y, x_pos, str);
  return 0;
}

