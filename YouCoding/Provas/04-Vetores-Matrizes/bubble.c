#include <stdio.h>

void bubblue_sort(int arr[], int n) {
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
    
    for (int k = 0; k < n; k++) {
      printf("%d ", arr[k]);
    }
    printf("\n");
  }
}

int main(void) {
  int n; scanf("%d", &n);
  int A[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
    printf("%d ", A[i]);
  }
  printf("\n");

  bubblue_sort(A, n);

  return 0;
}