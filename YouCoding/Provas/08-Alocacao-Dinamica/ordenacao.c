#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
  int x = *(const int *)a;
  int y = *(const int *)b;

  return (x > y) - (x < y);
}

int main() {
  int *vetor = NULL;
  int n = 0, num;
  char c;

  while (scanf("%d", &num) == 1) {
    vetor = realloc(vetor, (n + 1) * sizeof(int));
    vetor[n] = num;
    n++;

    c = getchar();
    if (c == '\n' || c == EOF) {
      break;
    }
  }

  qsort(vetor, n, sizeof(int), comparar);

  for (int i = 0; i < n; i++) {
    if (i > 0) {
      printf(" ");
    }
    printf("%d", vetor[i]);
  }

  printf("\n");

  free(vetor);

  return 0;
}
