#include <stdio.h>

int main(void) {
  int t; scanf("%d", &t);

  if (t < 5) {
    printf("Iniciante\n");
  } else if (t >= 5 && t < 20) {
    int saude; scanf("%d", &saude);

    if (saude == 0) {
      printf("Iniciante\n");
    } else {
      printf("Intermediário\n");
    }
  } else {
    int saude; scanf("%d", &saude);

    if (saude == 0) {
      printf("Intermediário\n");
    } else {
      printf("Avançado\n");
    }
  }
  
  return 0;
}