#include <stdio.h>
#include <string.h>

int main() {
    char codeName[100];

    if (scanf("%s", codeName) == 1) {
        int length = strlen(codeName);

        for (int i = length - 1; i >= 0; i--) {
            printf("%c", codeName[i]);
        }
        
        printf("\n");
    }

    return 0;
}
