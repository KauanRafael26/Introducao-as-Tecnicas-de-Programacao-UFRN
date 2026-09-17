#include <stdio.h>
#include <stdbool.h>

bool eh_perfeito(int x) {
  if (x == 1) {
    return false;
  }

  int sum = 1;

  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      sum += (x / i == i) ? i : (i + x / i);
    }
  }

  if (sum == x) {
    return true;
  }
  return false;
}

int main(void) {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int num; scanf("%d", &num);

    if (eh_perfeito(num)) {
      printf("%d eh perfeito\n", num);
    } else {
      printf("%d nao eh perfeito\n", num);
    }
  }

  return 0;
}