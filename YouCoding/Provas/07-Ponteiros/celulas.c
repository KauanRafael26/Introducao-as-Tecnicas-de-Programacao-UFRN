#include <stdio.h>
#include <stdlib.h>

int get_range(int n, int cells[n], int distance, int user, int *left_index, int *right_index) {
    int count = 0;
    *left_index = -1;
    *right_index = -1;

    int limite_inferior = user - distance;
    int limite_superior = user + distance;

    for (int i = 0; i < n; i++) {
        if (cells[i] >= limite_inferior && cells[i] <= limite_superior) {
            if (*left_index == -1) {
                *left_index = i;
            }
            *right_index = i;
            count++;
        }
    }
    
    return count;
}

int main() {
    int n, distance, user;
    
    scanf("%d %d %d", &n, &distance, &user);

    int *cells = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &cells[i]);
    }

    int left_index, right_index;

    int quantidade = get_range(n, cells, distance, user, &left_index, &right_index);

    if (quantidade == 0) {
        printf("USUARIO DESCONECTADO\n");
    } else {
        for (int i = left_index; i <= right_index; i++) {
            printf("%d", cells[i]);
            if (i < right_index) {
                printf(" ");
            }
        }
        printf("\n");
    }

    free(cells);

    return 0;
}