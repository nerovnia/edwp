


#include <locale.h>
#include <curses.h>   
  
int main() {
  initscr();
  setlocale(LC_ALL, "");

  noecho();
  curs_set(FALSE);

  start_color();
  init_pair(1, COLOR_YELLOW, COLOR_GREEN);


  init_pair(1, COLOR_BLACK, COLOR_RED);
  init_pair(2, COLOR_YELLOW, COLOR_GREEN);
  attron(COLOR_PAIR(1));
  printw("This should be printed in black with a red background!\n");
  attron(COLOR_PAIR(2));
  printw("And this in a green background!\n");
  
  refresh();
  getchar();
  curs_set(TRUE);
  endwin();
  return 0;
}