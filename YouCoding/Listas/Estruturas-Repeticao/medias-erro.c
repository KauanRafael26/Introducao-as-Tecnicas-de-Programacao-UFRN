#include <stdio.h>
#include <math.h>

int main(void) {
  float nums[10];
  float sum = 0;
  double inv_sum = 0;
  double prod = 1;
  for (int i = 0; i < 10; i++) {
    scanf("%f", &nums[i]);
    sum += nums[i];
    prod *= nums[i];
    inv_sum += 1 / nums[i];
  }

  float ma = sum / 10;
  float mh = 10 / inv_sum;
  float mg = pow(prod, 1.0 / 10);
  float eh = (mh - ma) / ma;
  float eg = (mg - ma) / ma;
  float em = (eh + eg) / 2;

  printf("Média aritmética é %.2lf\n", ma);
  printf("Média harmônica é %.2lf\n", mh);
  printf("Média geométrica é %.2lf\n", mg);
  printf("Erro médio é %.2lf %%\n", em * 100);

  return 0;
}