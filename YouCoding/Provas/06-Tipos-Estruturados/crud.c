#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[55];
    int idade;
    char sexo;
} Pessoa;

Pessoa criar(char nome[], int idade, char sexo) {
    Pessoa p;
    strcpy(p.nome, nome);
    p.idade = idade;
    p.sexo = sexo;
    return p;
}

void inserir(Pessoa vetor[], int *tamanho, Pessoa p) {
    vetor[*tamanho] = p;
    (*tamanho)++;
}

void deletar(Pessoa vetor[], int *tamanho, Pessoa p) {
    for (int i = 0; i < *tamanho; i++) {
        if (strcmp(vetor[i].nome, p.nome) == 0 && 
            vetor[i].idade == p.idade && 
            vetor[i].sexo == p.sexo) {
            
            for (int j = i; j < *tamanho - 1; j++) {
                vetor[j] = vetor[j + 1];
            }
            
            (*tamanho)--;
            break;
        }
    }
}

void imprimir(Pessoa vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%s,%d,%c\n", vetor[i].nome, vetor[i].idade, vetor[i].sexo);
    }
}

int main() {
    int capacidade = 10;
    Pessoa *vetor = malloc(capacidade * sizeof(Pessoa));
    int tamanho = 0;
    
    char comando;

    while (scanf(" %c", &comando) == 1) {
        if (comando == 'i') {
            char nome[55];
            int idade;
            char sexo;
            
            scanf(" %[^\n]", nome);
            scanf("%d", &idade);
            scanf(" %c", &sexo);
            
            Pessoa p = criar(nome, idade, sexo);
            
            if (tamanho >= capacidade) {
                capacidade *= 2;
                vetor = realloc(vetor, capacidade * sizeof(Pessoa));
            }
            
            inserir(vetor, &tamanho, p);
            
        } else if (comando == 'd') {
            char nome[55];
            int idade;
            char sexo;
            
            scanf(" %[^\n]", nome);
            scanf("%d", &idade);
            scanf(" %c", &sexo);
            
            Pessoa p = criar(nome, idade, sexo);
            deletar(vetor, &tamanho, p);
            
        } else if (comando == 'p') {
            imprimir(vetor, tamanho);
            break;
        }
    }
    
    free(vetor);
    return 0;
}