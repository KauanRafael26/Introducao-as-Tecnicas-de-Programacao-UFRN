#include <stdio.h>

float min(float n1, float n2, float n3) {
  float minimo = n1;
  if (n2 < minimo) {
    minimo = n2;
  } 
  if (n3 < minimo) {
    minimo = n3;
  }
  return minimo;
}

float calcNota(float n1, float n2, float n3) {
  float media = (n1 + n2 + n3) / 3;
  if (n1 >= 3 && n2 >= 3 && n3 >= 3 && media < 5) {
    float minimo = min(n1, n2, n3);
    float nota;

    if (minimo == n1) {
      nota = 15 - n2 - n3;
    } else if (minimo == n2) {
      nota = 15 - n1 - n3;
    } else {
      nota = 15 - n1 - n2;
    }

    return nota;
  }
  return -1;
}

int main(void) {
  float n1, n2, n3; scanf("%f %f %f", &n1, &n2, &n3);
  float nota = calcNota(n1, n2, n3);

  if (nota == -1) {
    printf("Nao faz prova final\n");
  } else {
    printf("Final\n");
    printf("%.1f\n", nota);
  }

  return 0;
}