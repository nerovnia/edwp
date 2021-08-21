#all:
#	gcc -Wall $(ncursesw6-config --cflags --libs) ed.c box.c form.c decorate.c -lncursesw -o ed.out


all: ed.out

ed.out: ed.o box.o form.o decorate.o
	gcc ed.o box.o form.o decorate.o -lncursesw -o ed.out

ed.o: ed.c
	gcc -c -Wall $(ncursesw6-config --cflags --libs) ed.c

box.o: box.c
	gcc -c -Wall $(ncursesw6-config --cflags --libs) box.c

form.o: form.c
	gcc -c -Wall $(ncursesw6-config --cflags --libs) form.c

decorate.o: decorate.c
	gcc -c -Wall $(ncursesw6-config --cflags --libs) decorate.c


clean:
	rm -rf *.o ed.out