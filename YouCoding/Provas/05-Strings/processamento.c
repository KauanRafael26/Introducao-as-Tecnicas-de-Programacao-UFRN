#include <stdio.h>
#include <string.h>

#define MAX_AFFIXES 1000 
#define MAX_LEN_AFFIX 15
#define MAX_LEN_WORD 105

int main() {
    int n, m;
    char prefixes[MAX_AFFIXES][MAX_LEN_AFFIX];
    char suffixes[MAX_AFFIXES][MAX_LEN_AFFIX];

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", prefixes[i]);
    }

    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        scanf("%s", suffixes[i]);
    }

    char word[MAX_LEN_WORD];
    
    while (scanf("%s", word) == 1) {
        if (strcmp(word, "-1") == 0) {
            break;
        }

        int len = strlen(word);
        int start = 0;
        int end = len;

        for (int i = 0; i < n; i++) {
            int p_len = strlen(prefixes[i]);
            if (len >= p_len && strncmp(word, prefixes[i], p_len) == 0) {
                start = p_len;
                break;
            }
        }

        for (int i = 0; i < m; i++) {
            int s_len = strlen(suffixes[i]);
            if (len >= s_len && strncmp(word + len - s_len, suffixes[i], s_len) == 0) {
                end = len - s_len;
                break; 
            }
        }

        if (end > start) {
            for (int i = start; i < end; i++) {
                putchar(word[i]);
            }
            putchar('\n');
        }
    }

    return 0;
}