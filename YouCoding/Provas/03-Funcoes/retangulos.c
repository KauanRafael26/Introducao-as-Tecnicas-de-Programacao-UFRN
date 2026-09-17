#include <stdio.h>
#include <stdbool.h>

bool contem(float r1[], float r2[]) {
  return (r1[0] < r2[0] && r1[1] < r2[1] && r1[2] > r2[2] && r1[3] > r2[3]);
}

void comparar_e_printar(float r1[], float r2[]) {
}

int main(void) {
  float r1[4];
  if (scanf("%f %f %f %f", &r1[0], &r1[1], &r1[2], &r1[3]) != 4);
  
  while(true) {
    float novo[4];
    if (scanf("%f %f %f %f", &novo[0], &novo[1], &novo[2], &novo[3]) != 4) break;
    
    if (novo[0] == 0.0f && novo[1] == 0.0f && novo[2] == 0.0f && novo[3] == 0.0f) break;
    
    if (contem(r1, novo)) {
      printf("(<%.2f,%.2f>,<%.2f,%.2f>) contem (<%.2f,%.2f>,<%.2f,%.2f>).\n", r1[0], r1[1], r1[2], r1[3], novo[0], novo[1], novo[2], novo[3]);
    } else if (contem(novo, r1)) {
      printf("(<%.2f,%.2f>,<%.2f,%.2f>) contem (<%.2f,%.2f>,<%.2f,%.2f>).\n", novo[0], novo[1], novo[2], novo[3], r1[0], r1[1], r1[2], r1[3]);
    } else {
      printf("Nao posso afirmar!\n");
    }
  }

  return 0;
}