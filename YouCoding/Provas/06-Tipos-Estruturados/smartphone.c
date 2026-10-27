#include <stdio.h>

typedef struct {
    char modelo[40];
    int memoria;
    float processador;
    float camera;
    float bateria;
} Smartphone;

int cadastraSmartphone(int qnt_cadastrada, Smartphone phones[]) {
    scanf(" %[^\n]", phones[qnt_cadastrada].modelo);
    
    scanf("%d %f %f %f",
          &phones[qnt_cadastrada].memoria,
          &phones[qnt_cadastrada].processador,
          &phones[qnt_cadastrada].camera,
          &phones[qnt_cadastrada].bateria);
          
    return qnt_cadastrada + 1;
}

int pesquisaSmartphones(int qnt_cadastrada, Smartphone phones[], Smartphone reqMin) {
    int encontrados = 0;
    
    for (int i = 0; i < qnt_cadastrada; i++) {
        if (phones[i].memoria >= reqMin.memoria &&
            phones[i].processador >= reqMin.processador &&
            phones[i].camera >= reqMin.camera &&
            phones[i].bateria >= reqMin.bateria) {
            
            printf("Modelo: %s\n", phones[i].modelo);
            printf("Memoria: %dGB\n", phones[i].memoria);
            printf("Processador: %.2fGhz\n", phones[i].processador);
            printf("Camera: %.2fMPixels\n", phones[i].camera);
            printf("Bateria: %.2fmA\n\n", phones[i].bateria); 
            
            encontrados++;
        }
    }
    
    return encontrados;
}

int main() {
    Smartphone phones[100]; 
    int qnt_cadastrada = 0;
    char opcao;

    while (scanf(" %c", &opcao) == 1 && opcao == 's') {
        qnt_cadastrada = cadastraSmartphone(qnt_cadastrada, phones);
    }

    Smartphone reqMin;
    scanf("%d %f %f %f", &reqMin.memoria, &reqMin.processador, &reqMin.camera, &reqMin.bateria);

    int encontrados = pesquisaSmartphones(qnt_cadastrada, phones, reqMin);
    
    printf("%d smartphones encontrados.\n", encontrados);

    return 0;
}