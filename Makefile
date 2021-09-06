#all:
#	gcc -Wall $(ncursesw6-config --cflags --libs) ed.c box.c form.c decorate.c -lncursesw -o ed.out


all: ed.out

ed.out: box.o form.o decorate.o menu.o ed.o
	gcc box.o form.o decorate.o menu.o ed.o -lform -lncursesw -o ed.out

ed.o: ed.c
	gcc -c -Wall $(ncursesw6-config --cflags --libs) ed.c

box.o: box.c
	gcc -c -Wall $(ncursesw6-config --cflags --libs) box.c

form.o: form.c
	gcc -c -Wall $(ncursesw6-config --cflags --libs) form.c

decorate.o: decorate.c
	gcc -c -Wall $(ncursesw6-config --cflags --libs) decorate.c

menu.o: menu.c
	gcc -c -Wall $(ncursesw6-config --cflags --libs) menu.c


clean:
	rm -rf *.o ed.out


test: test.out

test.o: test/test.c
	gcc -c -Wall $(ncursesw6-config --cflags --libs) test/test.c

test.out: test.o
	gcc test.o -lncursesw -lform -o test.out
