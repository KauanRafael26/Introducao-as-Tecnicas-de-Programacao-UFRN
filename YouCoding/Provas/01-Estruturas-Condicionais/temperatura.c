#include <stdio.h>

int main(void) {
  float t; scanf("%f", &t);
  char u; scanf(" %c", &u);

  double tc, tf, tk;
  if (u == 'C') {
    tc = t;
    tf = t * 1.8 + 32;
    tk = t + 273.15;
  } else if (u == 'F') {
    tc = (t - 32) / 1.8;
    tf = t;
    tk = tc + 273.15;
  } else if (u == 'K') {
    tc = t - 273.15;
    tf = tc * 1.8 + 32;
    tk = t;
  } else {
    printf("A unidade de medida precisa ser Celsius (C), Farenheit (F) ou Kelvin (K)");
  }

  printf("Celsius: %.2f\n", tc);
  printf("Farenheit: %.2f\n", tf);
  printf("Kelvin: %.2f\n", tk);

  return 0;
}