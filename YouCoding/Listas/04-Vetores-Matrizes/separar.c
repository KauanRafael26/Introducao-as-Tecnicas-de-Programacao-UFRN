#include <stdio.h>

int main(void) {
  int vetorA[15];
  int vetorB[15];
  int vetorC[15];
  int vetorD[15];

  int tamanhoB = 0;
  int tamanhoC = 0;
  int tamanhoD = 0;

  for (int i = 0; i < 15; i++) {
    scanf("%d", &vetorA[i]);
    if (vetorA[i] % 2 == 0) {
      vetorB[tamanhoB] = vetorA[i];
      tamanhoB++;
    } 
    if (vetorA[i] % 3 == 0) {
      vetorC[tamanhoC] = vetorA[i];
      tamanhoC++;
    } 
    if (vetorA[i] % 2 != 0 && vetorA[i] % 3 != 0) {
      vetorD[tamanhoD] = vetorA[i];
      tamanhoD++;
    }
  }

  printf("B = [");
  for (int i = 0; i < tamanhoB; i++) {
    printf("%d%s", vetorB[i], (i == tamanhoB - 1) ? "]\n" : ", ");
  }

  printf("C = [");
  for (int i = 0; i < tamanhoC; i++) {
    printf("%d%s", vetorC[i], (i == tamanhoC - 1) ? "]\n" : ", ");
  }

  printf("D = [");
  for (int i = 0; i < tamanhoD; i++) {
    printf("%d%s", vetorD[i], (i == tamanhoD - 1) ? "]\n" : ", ");
  }

  return 0;
}