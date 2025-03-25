#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printer(char* pattern, int gap, int red, int green) {
    int i, c = red + green;
    for (i = 0; i < gap; i++) {
        printf(" ");
    }
    for (i = 0; i < c; i++) {
        printf("%c", pattern[i]);
    }
    printf("\n");
}

void shiftTable(int *table, char *p, int m) {
    int i;
    for (i = 0; i < 27; i++) {
        table[i] = m;
    }
    for (i = 0; i < m - 1; i++) {
        if (p[i] != '_') {
            table[(int)p[i] - 65] = m - i - 1;
        } else {
            table[26] = m - i - 1;
        }
    }
}

int horspoolMatching(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int i;
    int *table = (int *)malloc(sizeof(int) * 27);
    shiftTable(table, pattern, m);

    printf("\nShift table:\n");
    printf("------------------------------------------------------\n");
    for (i = 0; i < 26; i++) {
        printf("%c ", i + 65);
    }
    printf("_\n");
    for (i = 0; i < 27; i++) {
        printf("%d ", table[i]);
    }
    printf("\n------------------------------------------------------\n");
    printf("Text given: %s\n", text);

    i = m - 1;
    while (i <= n - 1) {
        int k = 0;
        while (k <= m - 1 && pattern[m - 1 - k] == text[i - k]) {
            k++;
        }
        if (k == m) {
            printer(pattern, i - m + 1, 0, m);
            free(table);
            return i - m + 1;
        } else {
            printer(pattern, i - m + 1, m - k, k);
            if (text[i] != '_') {
                i += table[(int)text[i] - 65];
            } else {
                i += table[26];
            }
        }
    }

    free(table);
    return -1;
}

int main() {
    char text[100], pattern[100];
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  // Remove trailing newline

    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0';  // Remove trailing newline

    int result = horspoolMatching(text, pattern);
    if (result != -1) {
        printf("Pattern found at index %d\n", result);
    } else {
        printf("Pattern not found\n");
    }
    return 0;
}