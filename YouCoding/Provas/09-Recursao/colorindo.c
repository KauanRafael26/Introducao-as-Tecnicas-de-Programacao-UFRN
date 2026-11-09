#include <stdio.h>
#include <stdlib.h>

void preencher(char **mat, int **visitado, int m, int n,
               int i, int j, char original, char nova) {
  if (i < 0 || i >= m || j < 0 || j >= n) {
    return;
  }

  if (visitado[i][j] || mat[i][j] != original) {
    return;
  }

  visitado[i][j] = 1;
  mat[i][j] = nova;

  preencher(mat, visitado, m, n, i - 1, j, original, nova);
  preencher(mat, visitado, m, n, i + 1, j, original, nova);
  preencher(mat, visitado, m, n, i, j - 1, original, nova);
  preencher(mat, visitado, m, n, i, j + 1, original, nova);
}

int main() {
  int m, n, i, j;
  char c;
  char **mat;
  int **visitado;

  scanf("%d %d", &m, &n);

  mat = malloc(m * sizeof(char *));
  visitado = malloc(m * sizeof(int *));

  for (int k = 0; k < m; k++) {
    mat[k] = malloc((n + 1) * sizeof(char));
    visitado[k] = calloc(n, sizeof(int));
    scanf("%s", mat[k]);
  }

  scanf("%d %d", &i, &j);
  scanf(" %c", &c);

  if (i >= 0 && i < m && j >= 0 && j < n) {
    char original = mat[i][j];
    preencher(mat, visitado, m, n, i, j, original, c);
  }

  for (int k = 0; k < m; k++) {
    printf("%s\n", mat[k]);
  }

  for (int k = 0; k < m; k++) {
    free(mat[k]);
    free(visitado[k]);
  }

  free(mat);
  free(visitado);

  return 0;
}
