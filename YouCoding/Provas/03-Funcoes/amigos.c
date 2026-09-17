#include <stdio.h>
#include <stdbool.h>

/*
int testa_divisor(int numero, int divisor) {
  return 0;
}
*/

int soma_divisores(int value) {
  if (value == 1) return 0;

  int sum = 1;
  for (int i = 2; i * i <= value; i++) {
    if (value % i == 0) {
      sum += (value / i == i) ? i : (i + value / i);
    }
  }

  return sum;
}

bool testa_amigos(int num2, int intervalo[], int num1) {
  if (
    num2 >= intervalo[0] && 
    num2 <= intervalo[1] && 
    soma_divisores(num2) == num1 && 
    num1 != num2
  ) {
    return true;
  }

  return false;
}

int main() {
  int i1[2]; if (scanf("%d %d", &i1[0], &i1[1]) != 2) return 1;
  int i2[2]; if (scanf("%d %d", &i2[0], &i2[1]) != 2) return 1;
  int t = (i1[1] - i1[0]);
  int amigos[t];
  int tamanho = 0;

  for (int i = i1[0]; i <= i1[1]; i++) {
    int sum = soma_divisores(i);

    if (testa_amigos(sum, i2, i)) {
      amigos[tamanho] = i;
      tamanho++;
    }
  }

  if (tamanho == 0) {
    printf("Os intervalos nao apresentam amigos!\n");
  } else {
    for (int i = 0; i < tamanho; i++) {
      printf("O %d possui um amigo!\n", amigos[i]);
    }
  }

  return 0;
}