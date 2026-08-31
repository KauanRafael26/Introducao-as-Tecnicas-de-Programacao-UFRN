#include <stdio.h>
#include <string.h>

int main(void) {
  char num[50];
  scanf("%s", num);

  int len = strlen(num);
  if (len % 2 == 0) {
    for (int i = 0; i < len / 2; i++) {
      if (num[i] != num[len - 1 - i]) {
        printf("%s não é Palíndromo e ", num);
        break;
      } else {
        printf("%s é Palíndromo e ", num);
        break;
      }
    }
  } else {
    for (int i = 0; i < (len - 1) / 2; i++) {
      if (num[i] != num[len - 1 - i]) {
        printf("%s não é Palíndromo e ", num);
        break;
      } else {
        printf("%s é Palíndromo e ", num);
        break;
      }
    }
  }

  if (
    num[len - 1] == '0' || 
    num[len - 1] == '2' || 
    num[len - 1] == '4' || 
    num[len - 1] == '6' || 
    num[len - 1] == '8') {
      printf("par.\n");
  } else {
    printf("impar.\n");
  }


  for (int i = 0; i < len; i++) {

  }

  return 0;
}