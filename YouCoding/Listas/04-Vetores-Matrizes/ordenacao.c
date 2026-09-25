#include <stdio.h>

void exchange_sort(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  for (int i = 0; i <= n - 2; i++) {
    for (int j = i + 1; j <= n - 1; j++) {
      if (a[i] > a[j]) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }

    for (int i = 0; i < n; i++) {
      printf("%d ", a[i]);
    }
    printf("\n");
  }
}

int main(void) {
  int n; scanf("%d", &n);
  int array[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  exchange_sort(array, n);

  return 0;
}