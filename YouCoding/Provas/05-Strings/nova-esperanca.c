#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char S[] = {
    '0','1','2','3','4','5','6','7','8','9',
    'A','B','C','D','E','F','G','H','I','J',
    'K','L','M','N','O','P','Q','R','S','T',
    'U','V','W','X','Y','Z','.',',','?',' '
};
const int TAM_ALFABETO = 40;

int obter_indice(char c) {
    for (int i = 0; i < TAM_ALFABETO; i++) {
        if (S[i] == c) {
            return i;
        }
    }
    return -1; // Caractere não encontrado
}

void cifrar_mensagem(const char P[], const char K[], char C[]) {
    int len_P = strlen(P);
    
    for (int i = 0; i < len_P; i++) {
        int idx_p = obter_indice(P[i]);
        int deslocamento = K[i % 4] - '0'; 
        
        C[i] = S[(idx_p + deslocamento) % TAM_ALFABETO];
    }
    C[len_P] = '\0';
}

int main() {
    char K_str[100];
    char P[205];
    char C[205];

    
    if (scanf("%99s", K_str) != 1) {
        return 0;
    }

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    if (fgets(P, sizeof(P), stdin) == NULL) {
        return 0;
    }
    
    P[strcspn(P, "\r\n")] = '\0';

    if (strlen(K_str) != 4) {
        printf("Chave invalida!\n");
        return 0;
    }
    for (int i = 0; i < 4; i++) {
        if (!isdigit(K_str[i])) {
            printf("Chave invalida!\n");
            return 0;
        }
    }

    for (int i = 0; P[i] != '\0'; i++) {
        if (obter_indice(P[i]) == -1) {
            printf("Caractere invalido na entrada!\n");
            return 0;
        }
    }

    cifrar_mensagem(P, K_str, C);
    printf("%s\n", C);

    return 0;
}