#include <stdio.h>

int verifica(char tab[][4], int i, int j, char c) {
  if (tab[i][j] != '.') {
    return 1;
  }

  tab[i][j] = c;

  int venceu = 0;

  if (tab[i][0] == c && tab[i][1] == c && tab[i][2] == c) {
    venceu = 1;
  } else if (tab[0][j] == c && tab[1][j] == c && tab[2][j] == c) {
    venceu = 1;
  } else if (i == j && tab[0][0] == c && tab[1][1] == c && tab[2][2] == c) {
    venceu = 1;
  } else if (i + j == 2 && tab[0][2] == c && tab[1][1] == c && tab[2][0] == c) {
    venceu = 1;
  }

  tab[i][j] = '.';

  if (venceu) {
    return 2;
  } else {
    return 3;
  }
}

int main(void) {
  char tabuleiro[3][4];

  for (int i = 0; i < 3; i++) {
    scanf("%3s", tabuleiro[i]);
  }

  int n;
  if (scanf("%d", &n) != 1) return 1;

  for (int k = 0; k < n; k++) {
    int i, j;
    char simb;
    scanf("%d %d %c", &i, &j, &simb);

    switch (verifica(tabuleiro, i - 1, j - 1, simb)) {
      case 1:
        printf("Jogada inválida!\n");
        break;
      case 2:
        printf("Boa jogada, vai vencer!\n");
        break;
      case 3:
        printf("Continua o jogo.\n");
        break;
      default:
        break;
    }
  }

  return 0;
}