#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    int gols_marcados;
    int gols_sofridos;
} Time;

void ordenarPorGols(Time times[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (times[j].gols_marcados < times[j+1].gols_marcados) {
                Time temp = times[j];
                times[j] = times[j+1];
                times[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    
    if (scanf("%d", &n) != 1) return 0;
    
    Time times[n];
    
    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", times[i].nome);
        scanf("%d", &times[i].gols_marcados);
        scanf("%d", &times[i].gols_sofridos);
    }
    
    ordenarPorGols(times, n);
    
    for (int i = 0; i < n; i++) {
        printf("%d - %s\n", i + 1, times[i].nome);
        printf("Gols marcados: %d\n", times[i].gols_marcados);
        printf("Gols sofridos: %d\n", times[i].gols_sofridos);
    }
    
    return 0;
}