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

#window.o: window.c
#	gcc -c -Wall $(ncursesw6-config --cflags --libs) window.c

clean:
	rm -rf *.o *.out


test: test.out

test.o: test/test.c
	gcc -c -Wall $(ncursesw6-config --cflags --libs) test/test.c

test.out: test.o
	gcc test.o -lncursesw -lform -o test.out


zd.out: zd.o init.o
	gcc init.o zd.o -lncursesw -o zd.out

init.o: zd/init.c
	gcc -c -Wall $(ncursesw6-config --cflags --libs) zd/init.c

zd.o: zd/zd.c
	gcc -c -Wall $(ncursesw6-config --cflags --libs) zd/zd.c
