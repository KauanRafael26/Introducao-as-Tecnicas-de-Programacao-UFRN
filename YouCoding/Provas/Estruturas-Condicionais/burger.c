#include <stdio.h>

int main(void) {
  int pedido; scanf(" %d", &pedido);
  int pago; scanf(" %d", &pago);
  int valor;

  switch (pedido) {
    case 1:
      valor = 12;
      break;
    case 2:
      valor = 23;
      break;
    case 3:
      valor = 31;
      break;
    case 4:
      valor = 28;
      break;
    case 5:
      valor = 15;
      break;
    default:
      printf("Insira um item do cardápio");
  }

  if (pago == valor) {
    printf("Deu certim!\n");
  } else if (pago > valor) {
    printf("Troco = %d reais\n", pago - valor);
  } else {
    printf("Saldo insuficiente! Falta %d reais\n", valor - pago);
  }
  
  return 0;
}