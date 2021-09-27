#include <stdio.h>

//  gcc zd/zd.c -lncursesw -o zd.out

int get_int_pointer(void*);


int main(void) {
  int i = -9;
  int* p = &i;
  get_int_pointer(p);
  return 0;
}

int get_int_pointer(void* i_p) {
  int *p = i_p;
  //int i = ;
  printf("%d\n", (int*)i_p);
  return 0;
}