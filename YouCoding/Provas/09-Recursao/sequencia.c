#include <stdio.h>

void sequencia(long long n) {
  printf("%lld", n);

  if (n == 1) {
    printf("\n");
    return;
  }

  printf(" ");

  if (n % 2 == 0) {
    sequencia(n / 2);
  } else {
    sequencia(3 * n + 1);
  }
}

int main() {
  long long n;

  scanf("%lld", &n);

  sequencia(n);

  return 0;
}
