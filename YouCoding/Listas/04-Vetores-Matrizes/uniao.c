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

int uniao(int A[], int n, int B[], int m, int U[]) {
  int tamanho_uniao = 0;

  for (int i = 0; i < n; i++) {
    U[tamanho_uniao] = A[i];
    tamanho_uniao++;
  }

  for (int i = 0; i < m; i++) {
    if (!pertence(B[i], A, n)) {
      U[tamanho_uniao] = B[i];
      tamanho_uniao++;
    }
  }

  return tamanho_uniao;
}

int main(void) {
  int n, m;
  if (scanf("%d %d", &n, &m) != 2) return 1;

  int A[50];
  int B[50];
  int U[100];

  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &B[i]);
  }

  int tam_uniao = uniao(A, n, B, m, U);

  for (int i = 0; i < tam_uniao; i++) {
    printf("%d%s", U[i], (i == tam_uniao - 1) ? "" : " ");
  }
  printf("\n");

  return 0;
}