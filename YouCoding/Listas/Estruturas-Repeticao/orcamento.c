#include <stdio.h>
#include <stdbool.h>

int main(void) {
  bool has_item = true;
  int total_qtd = 0;
  float total_price = 0;

  while (has_item) {
    int qtd; scanf("%d", &qtd);
    if (qtd > 0) {
      float price; scanf("%f", &price);
      total_qtd += qtd;
      total_price += qtd * price;
    } else {
      has_item = false;
    }
  }

  printf("%d ", total_qtd);
  printf("%.2f\n", total_price);

  return 0;
}