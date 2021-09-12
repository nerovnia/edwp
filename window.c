#include "include/window.h"


void win(void) {
  WINDOW *my_win;
	int startx, starty, width, height;
	int ch;

	height = 3;
	width = 10;
	starty = (LINES - height) / 2;	/* Calculating for a center placement */
	startx = (COLS - width) / 2;	/* of the window		*/
	printw("Press F1 to exit");
	refresh();
	my_win = create_newwin(height, width, starty, startx);

	while((ch = getch()) != KEY_F(1))
	{	switch(ch)
		{	case KEY_LEFT:
 		 	  delwin(my_win);
				touchwin(stdscr);
      	refresh();
				my_win = create_newwin(height, width, starty,--startx);
				break;
			case KEY_RIGHT:
 		 	  delwin(my_win);
				touchwin(stdscr);
      	refresh();
				my_win = create_newwin(height, width, starty,++startx);
				break;
			case KEY_UP:
 		 	  delwin(my_win);
				touchwin(stdscr);
      	refresh();
				my_win = create_newwin(height, width, --starty,startx);
				break;
			case KEY_DOWN:
 		 	  delwin(my_win);
				touchwin(stdscr);
      	refresh();
				my_win = create_newwin(height, width, ++starty,startx);
				break;	
		}
	}
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters 
					 * for the vertical and horizontal
					 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/
	return local_win;
}
