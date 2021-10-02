CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=box.c form.c decorate.c init.c menu.c ed.c
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ed.out

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -lform -lncursesw -o ed.out

.cpp.o:
	$(CC) $(CFLAGS) $(ncursesw6-config --cflags --libs) $< -o $@


clean:
	rm -rf *.o *.out


test: test.out

test.o: test/test.c
	$(CC) $(CFLAGS) $(ncursesw6-config --cflags --libs) test/test.c

test.out: test.o
	$(CC) test.o -lncursesw -lform -o test.out


zd.out: zd.o init.o
	$(CC) init.o zd.o -lncursesw -o zd.out

init.o: zd/init.c
	$(CC) $(CFLAGS) $(ncursesw6-config --cflags --libs) zd/init.c

zd.o: zd/zd.c
	$(CC) $(CFLAGS) $(ncursesw6-config --cflags --libs) zd/zd.c

#t_mariadb.out: t_mariadb.o
#	$(CC) t_mariadb.o -o t_mariadb.out `mysql_config --libs`

#t_mariadb.o: test/t_mariadb.c
#	$(CC) $(CFLAGS) `mysql-config --cflags` test/t_mariadb.c

t_mariadb.out: t_mariadb.o
	$(CC) t_mariadb.o -lmariadb  -ldl -lm -lpthread -o t_mariadb.out $(mariadb_config --include --libs)

t_mariadb.o: test/t_mariadb.c
	$(CC) $(CFLAGS) test/t_mariadb.c	$(mariadb_config --include --libs)
