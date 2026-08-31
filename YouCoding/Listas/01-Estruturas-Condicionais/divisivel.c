#include <stdio.h>

int main(void) {
  int a, b;
  scanf("%d %d", &a, &b);

  if (a % b == 0) {
    printf("Resultado: %d\n", a / b);
  } else {
    printf("Não divisivel\n");
  }

  return 0;
}