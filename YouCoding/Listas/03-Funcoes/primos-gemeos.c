#include <stdio.h>
#include <stdbool.h>

bool e_primo(int x) {
  if (x == 1) {
    return false;
  }

  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int main(void) {
  int n; scanf("%d", &n);

  if (e_primo(n) && e_primo(n + 2)) {
    printf("Numero forma par de gemeos\n");
  } else {
    printf("Numero nao forma par de gemeos\n");
  }

  return 0;
}