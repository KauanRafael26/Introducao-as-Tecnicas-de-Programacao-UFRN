#include <stdio.h>
#include <stdbool.h>

void ehPar(int x) {
  if (x % 2 == 0) {
    printf("true\n");
  } else {
    printf("false\n");
  }
}

int main(void) {
  int n; scanf("%d", &n);
  ehPar(n);

  return 0;
}