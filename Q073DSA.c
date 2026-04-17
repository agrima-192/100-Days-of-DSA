#include <stdio.h>
#include <string.h>

char findFirstNonRepeating(char *s) {
    int count[26] = {0};
    int n = strlen(s);

    // Step 1: Build frequency map
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }

    // Step 2: Find the first char with count 1
    for (int i = 0; i < n; i++) {
        if (count[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';
}

int main() {
    char s[100001];
    scanf("%s", s);
    printf("%c", findFirstNonRepeating(s));
    return 0;
}
