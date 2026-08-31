#include <stdio.h>

int main(void) {
  int n; scanf("%d", &n);

  float sum = 0;
  int qtd = 0;
  for (int i = 0; i < n; i++) {
    float distancia; scanf("%f", &distancia);
    if (distancia > 0) {
      sum += distancia;
      qtd++;
    }
  }

  if (sum != 0) {
    float media = sum / qtd;
    printf("%.2f\n", media);
  } else {
    printf("A competicao nao possui dados historicos!\n");
  }

  return 0;
}