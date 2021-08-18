#include <locale.h>
#include <curses.h>   
  
int main() {
  initscr();
  setlocale(LC_ALL, "");
  noecho();
  curs_set(FALSE);
  start_color();

  
  refresh();
  getchar();
  curs_set(TRUE);
  endwin();
  return 0;
}