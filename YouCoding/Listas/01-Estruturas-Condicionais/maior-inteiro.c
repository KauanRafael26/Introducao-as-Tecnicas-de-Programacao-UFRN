#include <stdio.h>

int main(void) {
  int nums[4];
  for (int i = 0; i < 4; i++) {
    scanf("%d", &nums[i]);
  }

  int maior = nums[0];
  for (int i = 1; i <= 3; i++) {
    if (nums[i] > maior) {
      maior = nums[i];
    }
  }
  printf("Maior: %d\n", maior);

  return 0;
}