#include <stdio.h>
#include <stdbool.h>

bool pertence(int x, int conjunto[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    if (conjunto[i] == x) {
      return true;
    }
  }
  return false;
}

int intersecao(int A[], int n, int B[], int m, int U[]) {
  int tamanho_intersecao = 0;

  for (int i = 0; i < n; i++) {
    if (pertence(A[i], B, m)) {
      U[tamanho_intersecao] = A[i];
      tamanho_intersecao++;
    }
  }

  return tamanho_intersecao;
}

int main(void) {
  int n, m;
  if (scanf("%d %d", &n, &m) != 2) return 1;

  int A[50];
  int B[50];
  int U[50];

  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &B[i]);
  }

  int tam_intersecao = intersecao(A, n, B, m, U);

  for (int i = 0; i < tam_intersecao; i++) {
    printf("%d%s", U[i], (i == tam_intersecao - 1) ? "" : " ");
  }
  printf("\n");

  return 0;
}