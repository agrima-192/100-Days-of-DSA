#include <stdio.h>
#include <string.h>

char findFirstRepeated(char* s) {
    int seen[256] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char val = s[i];
        if (seen[val] == 1) {
            return s[i];
        }
        seen[val] = 1;
    }

    return '\0';
}

int main() {
    char s[] = "geeksforgeeks";
    char result = findFirstRepeated(s);

    if (result != '\0') {
        printf("%c\n", result);
    } else {
        printf("-1\n");
    }

    return 0;
}
