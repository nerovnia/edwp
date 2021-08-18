#include <stdio.h>

struct data {
  int num;
  int month;
  int year;
};
int check_data(int num, int month, int year); 
int get_string(char *str, long unsigned int size);

struct data cn_data; 

int inp_data(struct data mydata, int num, int month, int year) {
  if ( check_data(num, month, year) < 1 ) {
    mydata.num = num;
    mydata.month = month;
    mydata.year = year;
  } else 
    return 1;
  return 0;
}

int check_data(int num, int month, int year) {
  if ((( num > 29 ) && ( month !=1 )) && ((num < 31) && ( num >= 0 )) && (( month < 12) && ( month >=0 )) && (( year > 2020 ) && ( year < 3000 ))) {
    return 0;
  }
  return 1;
}

int main(void) {
  const char *str1 = "Циркулярний наказ\n";
  const char *str2 = "Пошкодження\n";
  const char *str[2];
  char m_str[2];
  str[0] = "Циркулярний наказ";
  str[1] = "Пошкодження";
  
  for(int i=0; i < 2; i++) {
    printf("%d. ", i);
    printf("%s\n", str[i]);
  }
  
  printf("%ld\n", sizeof(m_str));
  get_string(m_str, sizeof(m_str));
  
  printf("%s\n", m_str);
  /*printf("%s", str2);*/
  /*printf("Циркулярний наказ\n");*/
  return 0;
}

int get_string(char *str, long unsigned int size) {
  int i = 0;
  int d, c; 
  scanf("%d:%d", &d, &c);
  /*char ch = getch();*/
  /*while ( i < size) {
    str[i] = ch;
    i++;
    ch = getchar();
  }
  str[i] = '\0';*/
  /*scanf ("%%", &ch);*/
  return 0;
}

int c_prikas() {
  int num = 0;
}

int poshkodg() {

}