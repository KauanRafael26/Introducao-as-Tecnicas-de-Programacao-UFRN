#include <stdio.h>

int contarFibonacci(int n1, int n2, long long a, long long b) {
  if (a >= n2) {
    return 0;
  }

  if (a > n1) {
    return 1 + contarFibonacci(n1, n2, b, a + b);
  }

  return contarFibonacci(n1, n2, b, a + b);
}

int fibonacciEntre(int n1, int n2) {
  return contarFibonacci(n1, n2, 1, 1);
}

int main() {
  int n1, n2;

  scanf("%d %d", &n1, &n2);

  printf("Existem %d números de fibonacci entre %d e %d\n",
         fibonacciEntre(n1, n2), n1, n2);

  return 0;
}
