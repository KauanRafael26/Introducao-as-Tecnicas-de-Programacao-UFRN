#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char **PARTICIPANTES = NULL;
  char *nome;
  int *sorteados;
  int N = 0, S, indice, total = 0;
  int capacidade, tamanho, c;

  while (1) {
    capacidade = 16;
    tamanho = 0;
    nome = malloc(capacidade * sizeof(char));

    while ((c = getchar()) != '\n' && c != EOF) {
      if (tamanho + 1 >= capacidade) {
        capacidade *= 2;
        nome = realloc(nome, capacidade * sizeof(char));
      }
      nome[tamanho++] = c;
    }

    nome[tamanho] = '\0';

    if (strcmp(nome, "acabou") == 0) {
      free(nome);
      break;
    }

    PARTICIPANTES = realloc(PARTICIPANTES, (N + 1) * sizeof(char *));
    PARTICIPANTES[N] = nome;
    N++;
  }

  scanf("%d", &S);
  srand(S);

  sorteados = calloc(N, sizeof(int));

  while (total < N) {
    indice = rand() % N;

    if (sorteados[indice] == 0) {
      printf("%s\n", PARTICIPANTES[indice]);
      sorteados[indice] = 1;
      total++;
    }
  }

  for (int i = 0; i < N; i++) {
    free(PARTICIPANTES[i]);
  }

  free(PARTICIPANTES);
  free(sorteados);

  return 0;
}
