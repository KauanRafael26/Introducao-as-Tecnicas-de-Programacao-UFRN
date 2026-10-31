#include <stdio.h>
#include <stdlib.h>

void compute_votes(int n, int votes[n], int *most_voted, int *second_most_voted) {
    int contagem[11] = {0};

    for (int i = 0; i < n; i++) {
        contagem[votes[i]]++;
    }

    int max_votos = -1;
    int segundo_max_votos = -1;

    for (int i = 1; i <= 10; i++) {
        if (contagem[i] > max_votos) {
            max_votos = contagem[i];
            *most_voted = i;
        }
    }

    for (int i = 1; i <= 10; i++) {
        if (i != *most_voted && contagem[i] > segundo_max_votos) {
            segundo_max_votos = contagem[i];
            *second_most_voted = i;
        }
    }
}

int main() {
    int n;

    scanf("%d", &n);

    int *votes = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &votes[i]);
    }

    int most_voted, second_most_voted;

    compute_votes(n, votes, &most_voted, &second_most_voted);

    printf("%d %d\n", most_voted, second_most_voted);

    free(votes);

    return 0;
}