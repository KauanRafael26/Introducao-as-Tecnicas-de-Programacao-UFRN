#include <stdio.h>
#include <stdbool.h>

int main(void) {
  float max; scanf(" %f", &max);
  bool recebendo = true;
  int aptos = 0;

  while (recebendo) {
    float tempo; scanf(" %f", &tempo);
    if (tempo > 0) {
      if (tempo <= max) {
        aptos++;
      }
    } else {
      recebendo = false;
    }
  }

  int series = 0;
  if (aptos % 8 == 0) {
    series = aptos / 8;
  } else {
    series = (aptos - (aptos % 8)) / 8 + 1;
  }

  printf("%d", aptos);
  printf(" %d\n", series);

  return 0;
}