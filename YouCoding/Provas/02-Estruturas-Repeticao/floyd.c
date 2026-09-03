#include <stdio.h>
#include <string.h>

int main(void) {
  int num; scanf("%d", &num);

  int max_num = (1 + num) * num / 2;
  char s_max_num[20];
  sprintf(s_max_num, "%d", max_num);
  int tamanho = strlen(s_max_num);

  int n = 1;
  if (num > 0) {
    for (int i = 0; i < num; i++) {
      for (int j = 0; j < i + 1; j++) {
        printf("%*d ", tamanho, n);
        n++;
      }
      printf("\n");
    }
  } else {
    printf("Você entrou com %d, tente de novo na próxima\n", num);
  }

  return 0;
}