#include <stdio.h>

int main(void) {
  int n; scanf(" %d", &n);
  char c; scanf(" %c", &c);

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (j == i || j == n - 2 - i) {
        printf("%c", c);
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}