#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *elementos;
    int quantidade;
} Conjunto;

int pertence(Conjunto *c, int elemento) {
    for (int i = 0; i < c->quantidade; i++) {
        if (c->elementos[i] == elemento) {
            return 1;
        }
    }
    return 0;
}

Conjunto uniao(Conjunto *A, Conjunto *B) {
    Conjunto C;
    C.elementos = (int *)malloc((A->quantidade + B->quantidade) * sizeof(int));
    C.quantidade = 0;

    for (int i = 0; i < A->quantidade; i++) {
        C.elementos[C.quantidade++] = A->elementos[i];
    }

    for (int i = 0; i < B->quantidade; i++) {
        if (!pertence(A, B->elementos[i])) {
            C.elementos[C.quantidade++] = B->elementos[i];
        }
    }
    return C;
}

Conjunto intersecao(Conjunto *A, Conjunto *B) {
    Conjunto C;
    C.elementos = (int *)malloc(B->quantidade * sizeof(int));
    C.quantidade = 0;

    for (int i = 0; i < B->quantidade; i++) {
        if (pertence(A, B->elementos[i])) {
            C.elementos[C.quantidade++] = B->elementos[i];
        }
    }
    return C;
}

int main() {
    Conjunto A, B;

    scanf("%d", &A.quantidade);
    A.elementos = (int *)malloc(A.quantidade * sizeof(int));
    for (int i = 0; i < A.quantidade; i++) {
        scanf("%d", &A.elementos[i]);
    }

    scanf("%d", &B.quantidade);
    B.elementos = (int *)malloc(B.quantidade * sizeof(int));
    for (int i = 0; i < B.quantidade; i++) {
        scanf("%d", &B.elementos[i]);
    }

    Conjunto U = uniao(&A, &B);
    Conjunto I = intersecao(&A, &B);

    printf("A união B == {");
    if (U.quantidade == 0) {
        printf("vazio");
    } else {
        for (int i = 0; i < U.quantidade; i++) {
            printf("%d", U.elementos[i]);
            if (i < U.quantidade - 1) printf(" "); 
        }
    }
    printf("}\n");

    printf("A interseção B == {");
    if (I.quantidade == 0) {
        printf("vazio");
    } else {
        for (int i = 0; i < I.quantidade; i++) {
            printf("%d", I.elementos[i]);
            if (i < I.quantidade - 1) printf(" "); 
        }
    }
    printf("}\n");

    free(A.elementos);
    free(B.elementos);
    free(U.elementos);
    free(I.elementos);

    return 0;
}