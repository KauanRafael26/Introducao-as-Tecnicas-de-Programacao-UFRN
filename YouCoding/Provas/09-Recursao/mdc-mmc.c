#include <stdio.h>

int calcularMDC(int x, int y) {
  if (y == 0) {
    return x;
  }

  return calcularMDC(y, x % y);
}

void calc_mdc_mmc(int x, int y, int *mdc, int *mmc) {
  *mdc = calcularMDC(x, y);
  *mmc = (x * y) / *mdc;
}

int main() {
  int x, y, mdc, mmc;

  scanf("%d %d", &x, &y);

  calc_mdc_mmc(x, y, &mdc, &mmc);

  printf("MDC = %d, MMC = %d\n", mdc, mmc);

  return 0;
}
