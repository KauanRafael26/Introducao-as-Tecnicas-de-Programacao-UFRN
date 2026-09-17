#include <stdio.h>

int main(void) {
  int x, v1, v2; scanf("%d %d %d", &x, &v1, &v2);
  if (v1 > v2) {
    int vr = v1 - v2;
    int t = x / vr;

    printf("%ds\n", t);
  } else {
    printf("impossivel\n");
  }

  return 0;
}