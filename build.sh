#!/bin/sh
gcc -Wall $(ncursesw6-config --cflags --libs) ed.c -lncursesw -o ed.out

#gcc -Wall $(ncursesw6-config --cflags --libs) test/test.c -lncursesw -o ed.out
#gcc -Wall $(ncursesw6-config --cflags --libs) test/test3.c -lncursesw -o ed.out


#gcc -Wall $(ncursesw6-config --cflags --libs) test/test.c test/convert.c -lncursesw -o test.out
#gcc -Wall $(ncursesw6-config --cflags --libs) test/test2.c -lncursesw -o test.out



#gcc test.c -lncurses -o test
#gcc -std=c99 test.c -lncurses -o test
#gcc -o test -std=c99 $(ncursesw6-config --cflags --libs) test.c

#-ldialog -lncursesw -lm
# gcc $(dialog-config --cflags) file ... $(dialog-config --libs)