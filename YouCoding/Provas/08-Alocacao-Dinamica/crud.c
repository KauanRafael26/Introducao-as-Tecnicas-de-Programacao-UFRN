
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *nome;
  int idade;
  char sexo;
} Pessoa;

char* lerNome() {
  int capacidade = 16;
  int tamanho = 0;
  int c;
  char *nome = malloc(capacidade * sizeof(char));

  while ((c = getchar()) != '\n' && c != EOF) {
    if (tamanho + 1 >= capacidade) {
      capacidade *= 2;
      nome = realloc(nome, capacidade * sizeof(char));
    }
    nome[tamanho++] = c;
  }

  nome[tamanho] = '\0';
  return nome;
}

Pessoa criar(char *nome, int idade, char sexo) {
  Pessoa p;

  p.nome = nome;
  p.idade = idade;
  p.sexo = sexo;

  return p;
}

void inserir(Pessoa **vetor, int *n, Pessoa p) {
  *vetor = realloc(*vetor, (*n + 1) * sizeof(Pessoa));
  (*vetor)[*n] = p;
  (*n)++;
}

void deletar(Pessoa **vetor, int *n, Pessoa p) {
  for (int i = 0; i < *n; i++) {
    if (strcmp((*vetor)[i].nome, p.nome) == 0 &&
        (*vetor)[i].idade == p.idade &&
        (*vetor)[i].sexo == p.sexo) {

      free((*vetor)[i].nome);

      for (int j = i; j < *n - 1; j++) {
        (*vetor)[j] = (*vetor)[j + 1];
      }

      (*n)--;

      if (*n == 0) {
        free(*vetor);
        *vetor = NULL;
      } else {
        *vetor = realloc(*vetor, *n * sizeof(Pessoa));
      }

      break;
    }
  }
}

void imprimir(Pessoa *vetor, int n) {
  for (int i = 0; i < n; i++) {
    printf("%s,%d,%c\n",
           vetor[i].nome,
           vetor[i].idade,
           vetor[i].sexo);
  }
}

int main() {
  Pessoa *vetor = NULL;
  Pessoa p;
  int n = 0;
  int idade;
  char sexo, op;
  char *nome;

  while (scanf(" %c", &op) == 1) {
    if (op == 'p') {
      imprimir(vetor, n);
      break;
    }

    if (op == 'i' || op == 'd') {
      getchar();
      nome = lerNome();
      scanf("%d", &idade);
      scanf(" %c", &sexo);

      p = criar(nome, idade, sexo);

      if (op == 'i') {
        inserir(&vetor, &n, p);
      } else {
        deletar(&vetor, &n, p);
        free(p.nome);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    free(vetor[i].nome);
  }

  free(vetor);

  return 0;
}
