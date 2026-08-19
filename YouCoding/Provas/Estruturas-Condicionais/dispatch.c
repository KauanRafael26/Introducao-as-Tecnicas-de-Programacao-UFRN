#include <stdio.h>

int main(void) {
  int n; scanf(" %d", &n);
  int classe; scanf(" %d", &classe);
  int monstro; scanf(" %d", &monstro);

  if (n == 1) {
    if (classe - monstro >= 1 || monstro == 5) {
        printf("Heróis vencerão!\n");
    } else {
      printf("Melhor chamar Saitama!\n");
    }
  } else if (n > 1) {
      if (classe - monstro >= 0) {
        printf("Heróis vencerão!\n");
      } else {
        printf("Melhor chamar Saitama!\n");
      }
  } else {
    printf("Melhor chamar Saitama!\n");
  }

  return 0;
}