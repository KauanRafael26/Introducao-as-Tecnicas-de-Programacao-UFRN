#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int votes;
} Party;

int compute_votes(
    int num_votes, int votes[num_votes],
    int num_parties, Party parties[num_parties],
    Party *most_voted, Party *second_most_voted
) {
    int valid_votes_count = 0;

    for (int i = 0; i < num_parties; i++) {
        parties[i].votes = 0;
    }

    for (int i = 0; i < num_votes; i++) {
        for (int j = 0; j < num_parties; j++) {
            if (votes[i] == parties[j].id) {
                parties[j].votes++;
                valid_votes_count++;
                break;
            }
        }
    }

    int max1 = -1, max2 = -1;
    int idx1 = -1, idx2 = -1;

    for (int i = 0; i < num_parties; i++) {
        if (parties[i].votes > max1) {
            max2 = max1;
            idx2 = idx1;
            max1 = parties[i].votes;
            idx1 = i;
        } else if (parties[i].votes > max2) {
            max2 = parties[i].votes;
            idx2 = i;
        }
    }

    *most_voted = parties[idx1];
    *second_most_voted = parties[idx2];

    return valid_votes_count;
}

int main() {
    int num_parties;
    scanf("%d", &num_parties);
    
    Party *parties = (Party *)malloc(num_parties * sizeof(Party));
    
    for (int i = 0; i < num_parties; i++) {
        scanf("%d %s", &parties[i].id, parties[i].name);
        parties[i].votes = 0;
    }
    
    int num_votes;
    scanf("%d", &num_votes);
    
    int *votes = (int *)malloc(num_votes * sizeof(int));
    
    for (int i = 0; i < num_votes; i++) {
        scanf("%d", &votes[i]);
    }
    
    Party winner, vice;
    
    int valid_votes = compute_votes(num_votes, votes, num_parties, parties, &winner, &vice);
    
    double pct_winner = (winner.votes * 100.0) / valid_votes;
    double pct_vice   = (vice.votes * 100.0) / valid_votes;
    
    printf("VENCEDOR: %s (%d votos = %.2f%%)\n", winner.name, winner.votes, pct_winner);
    printf("VICE: %s (%d votos = %.2f%%)\n", vice.name, vice.votes, pct_vice);
    
    free(parties);
    free(votes);

    return 0;
}