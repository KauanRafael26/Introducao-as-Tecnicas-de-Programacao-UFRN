#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    char pattern[100];

    if (fgets(text, sizeof(text), stdin) == NULL) return 0;
    text[strcspn(text, "\r\n")] = '\0'; 

    if (fgets(pattern, sizeof(pattern), stdin) == NULL) return 0;
    pattern[strcspn(pattern, "\r\n")] = '\0';

    int n = strlen(text);
    int m = strlen(pattern);
    
    int in_pattern[256] = {0};
    for (int k = 0; k < m; k++) {
        in_pattern[(unsigned char)pattern[k]] = 1;
    }

    int found = 0;
    int i = 0; 

    while (i <= n - m) {
        int j;
        
        for (j = 0; j < m; j++) {
            printf("%c ", text[i + j]);

            if (text[i + j] != pattern[j]) {
                printf("não\n");
                
                if (!in_pattern[(unsigned char)text[i + j]]) {
                    i = i + j + 1;
                } else {
                    i++;
                }
                break;
            }
        }
        
        if (j == m) {
            printf("sim\n");
            printf("Achei o padrão no índice %d\n", i);
            found = 1;
            break; 
        }
    }

    if (!found) {
        printf("Não achei o padrão\n");
    }

    return 0;
}