#include <stdio.h>

int main(void) {
  int a, b, c;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);

  if (a + b > c && a + c > b && b + c > a) {
    printf("possivel\n");
  } else {
    printf("impossivel\n");
  }

  return 0;
}