#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int n; scanf(" %d", &n);

  int c = 0;
  int s = 0;
  int l = 0;
  for (int i = 0; i < n; i++) {
    bool t = true;
    while (t) {
      char m; scanf(" %c", &m);

      if (m == 'S') {
        s++;
      } else if (m == 'C') {
        c++;
      } else if (m == 'L') {
        l++;
      } else {
        t = false;
      }
    }
  }

  int sum = c + s + l;
  printf("%d %d %d %d\n", c, s, l, sum);

  return 0;
}