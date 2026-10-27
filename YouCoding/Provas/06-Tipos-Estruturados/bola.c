#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[205];
    int vitorias;
    int empates;
    int derrotas;
    int gols_feitos;
    int gols_sofridos;
    
    int pontos;
    int jogos;
    int saldo_gols;
} Time;

void lerTimes(Time times[], int T) {
    for (int i = 0; i < T; i++) {
        scanf(" %[^;]; %d %d %d %d %d", 
              times[i].nome, 
              &times[i].vitorias, 
              &times[i].empates, 
              &times[i].derrotas, 
              &times[i].gols_feitos, 
              &times[i].gols_sofridos);
              
        times[i].pontos = (times[i].vitorias * 3) + (times[i].empates * 1);
        times[i].jogos = times[i].vitorias + times[i].empates + times[i].derrotas;
        times[i].saldo_gols = times[i].gols_feitos - times[i].gols_sofridos;
    }
}

void ordenarTimes(Time times[], int T) {
    for (int i = 0; i < T - 1; i++) {
        for (int j = 0; j < T - i - 1; j++) {
            int trocar = 0;
            
            if (times[j].pontos < times[j+1].pontos) {
                trocar = 1;
            } 
            else if (times[j].pontos == times[j+1].pontos) {
                if (times[j].vitorias < times[j+1].vitorias) {
                    trocar = 1;
                } 
                else if (times[j].vitorias == times[j+1].vitorias) {
                    if (times[j].saldo_gols < times[j+1].saldo_gols) {
                        trocar = 1;
                    }
                }
            }
            
            if (trocar) {
                Time temp = times[j];
                times[j] = times[j+1];
                times[j+1] = temp;
            }
        }
    }
}

void imprimirTabela(Time times[], int T) {
    printf("Tabela do campeonato:\n");
    printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols\n");
    
    for (int i = 0; i < T; i++) {
        printf("%s| %d| %d| %d| %d| %d| %d| %d| %d\n", 
               times[i].nome, times[i].pontos, times[i].jogos, 
               times[i].vitorias, times[i].empates, times[i].derrotas, 
               times[i].gols_feitos, times[i].gols_sofridos, times[i].saldo_gols);
    }
    
    printf("\nTimes na zona da libertadores: \n");
    for (int i = 0; i < 6 && i < T; i++) {
        printf("%s\n", times[i].nome);
    }
    
    printf("\nTimes rebaixados: \n");
    for (int i = T - 1; i >= T - 4 && i >= 0; i--) {
        printf("%s\n", times[i].nome);
    }
}

int main() {
    int T;
    
    if (scanf("%d", &T) != 1) return 0;
    
    Time times[T];

    lerTimes(times, T);
    ordenarTimes(times, T);
    imprimirTabela(times, T);
    
    return 0;
}