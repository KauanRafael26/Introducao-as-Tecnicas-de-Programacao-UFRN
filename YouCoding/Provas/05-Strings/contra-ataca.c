#include <stdio.h>
#include <string.h>

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
    return -1;
}

int descobrir_chave(const char C[], const char KP[], int K[]) {
    int len_C = strlen(C);
    int len_KP = strlen(KP);

    for (int i = 0; i <= len_C - len_KP; i++) {
        int tempK[4] = {-1, -1, -1, -1};
        int possivel = 1;

        for (int j = 0; j < len_KP; j++) {
            int idx_c = obter_indice(C[i + j]);
            int idx_kp = obter_indice(KP[j]);

            if (idx_c == -1 || idx_kp == -1) {
                possivel = 0;
                break;
            }

            int diff = (idx_c - idx_kp + TAM_ALFABETO) % TAM_ALFABETO;

            if (diff > 9) {
                possivel = 0;
                break;
            }

            int pos_chave = (i + j) % 4;

            if (tempK[pos_chave] != -1 && tempK[pos_chave] != diff) {
                possivel = 0;
                break;
            }

            tempK[pos_chave] = diff;
        }

        if (possivel) {
            for (int k = 0; k < 4; k++) {
                K[k] = tempK[k];
            }
            return 1;
        }
    }

    return 0;
}

void decifrar_mensagem(const char C[], const int K[], char P[]) {
    int len_C = strlen(C);

    for (int i = 0; i < len_C; i++) {
        int idx_c = obter_indice(C[i]);
        int deslocamento = K[i % 4];

        int idx_p = (idx_c - deslocamento + TAM_ALFABETO) % TAM_ALFABETO;
        P[i] = S[idx_p];
    }
    P[len_C] = '\0';
}

int main() {
    char C[205];
    char P[205];
    int K[4];
    const char KP[] = "QUE A FORCA ESTEJA COM VOCE";

    if (fgets(C, sizeof(C), stdin) != NULL) {
        size_t len = strlen(C);
        if (len > 0 && (C[len - 1] == '\n' || C[len - 1] == '\r')) {
            C[strcspn(C, "\r\n")] = '\0';
        }

        if (descobrir_chave(C, KP, K)) {
            printf("%d%d%d%d\n", K[0], K[1], K[2], K[3]);

            decifrar_mensagem(C, K, P);
            printf("%s\n", P);
        } else {
            printf("Mensagem nao e da Resistencia!\n");
        }
    }

    return 0;
}