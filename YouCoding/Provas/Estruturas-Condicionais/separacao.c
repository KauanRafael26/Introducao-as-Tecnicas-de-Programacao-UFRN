#include <stdio.h>
#include <string.h>

int main(void){
  char n[7]; scanf("%s", n);

  switch (strlen(n)) {
    case 1:
      printf("%c\n", n[0]);
      break;
    case 2:
      printf("%c\n%c\n", n[0], n[1]);
      break;
    case 3:
      printf("%c\n%c\n%c\n", n[0], n[1], n[2]);
      break;
    case 4:
      printf("%c\n%c\n%c\n%c\n", n[0], n[1], n[2], n[3]);
      break;
    case 5:
      printf("%c\n%c\n%c\n%c\n%c\n", n[0], n[1], n[2], n[3], n[4]);
      break;
    case 6:
      printf("%c\n%c\n%c\n%c\n%c\n%c\n", n[0], n[1], n[2], n[3], n[4], n[5]);
      break;
    default:
      printf("Número inválido");
  }

  return 0;
}