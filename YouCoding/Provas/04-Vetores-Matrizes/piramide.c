#include <stdio.h>

int min(int a, int b) {
  return (a < b) ? a : b;
}

int main(void) {
  int n; scanf("%d", &n);
  int piramide[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int dist_cima = i;
      int dist_base = n - 1 - i;
      int dist_esq = j;
      int dist_dir = n - 1 - j;

      int altura = 1 + min(dist_cima, min(dist_base, min(dist_esq, dist_dir)));

      piramide[i][j] = altura;

      printf("%d%s", piramide[i][j], (j == n - 1) ? "" : " ");
    }
    printf("\n");
  }

  return 0;
}