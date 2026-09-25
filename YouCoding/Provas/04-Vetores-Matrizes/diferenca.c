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

int diferenca_simetrica(int A[], int n, int B[], int m, int D[]) {
  int tam_diferenca = 0;

  for (int i = 0; i < n; i++) {
    if (!pertence(A[i], B, m)) {
      D[tam_diferenca] = A[i];
      tam_diferenca++;
    }
  }

  for (int i = 0; i < m; i++) {
    if (!pertence(B[i], A, n)) {
      D[tam_diferenca] = B[i];
      tam_diferenca++;
    }
  }

  return tam_diferenca;
}

void sort(int arr[], int n) {
  int i, j, temp, swapped;

  for (i = 0; i < n - 1; i++) {
    swapped = 0;

    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = 1;
      }
    }
    if (swapped == 0) break;
  }
}

int main(void) {
  int n, m;
  if (scanf("%d %d", &n, &m) != 2) return 1;
  int A[n];
  int B[m];
  int D[m + n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &B[i]);
  }

  int tam_diferenca = diferenca_simetrica(A, n, B, m, D);

  sort(D, tam_diferenca);

  for (int i = 0; i < tam_diferenca; i++) {
    printf("%d%s", D[i], (i == tam_diferenca - 1) ? "" : " ");
  }
  printf("\n");

  return 0;
}