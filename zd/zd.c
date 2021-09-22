#include<stdio.h>
#include<conio.h>

struct type_struct {
  char* name;
};

struct uchastok {
  int num;
  char *name;
};

struct eche {
  struct uchastok *uch;
  int num;
  int km;
  int pk;
};

struct psk {
  char *name;
  int km;
  int pk;
};

void test(void);

struct uchastok uch[3];
struct eche eche[7];

void main(void) {
  uch[0].num = 0;
  uch[0].name = "Держ. кордон (РФ) - ст. Ніжин";
  uch[1].num = 1;
  uch[1].name = "ст. Конотоп - ст. Ворожба";
  uch[2].num = 2;
  uch[2].name = "ст. Бахмач - Пас - Держ. кордон (Білорусь)";

  eche[0].uch = &uch[0];
  eche[0].num = 14;
  eche[0].km = 519;
  eche[0].pk = 3;

  eche[1].uch = &uch[0];
  eche[1].num = 15;
  eche[1].km = 564;
  eche[1].pk = 7;

  eche[2].uch = &uch[0];
  eche[2].num = 16;
  eche[2].km = 616;
  eche[2].pk = 95;

  eche[3].uch = &uch[0];
  eche[3].num = 17;
  eche[3].km = 659;
  eche[3].pk = 2;

  eche[4].uch = &uch[0];
  eche[4].num = 18;
  eche[4].km = 711;
  eche[4].pk = 6;

  eche[5].uch = &uch[1];
  eche[5].num = 38;
  eche[5].km = 72;
  eche[5].pk = 8;
  test();
  printf("Press any key!");
  getch();
}

void test(void) {
  for(int i = 0; i < sizeof(uch)/sizeof(uch[0]); i++) {
    printf("%s\n", uch[i].name);
  }
}