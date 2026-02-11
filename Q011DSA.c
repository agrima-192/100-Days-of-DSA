#include <stdio.h>

int main() {
    int m, n;

    if (scanf("%d %d", &m, &n) != 2) return 0;
    int matrix1[m][n];
    int matrix2[m][n];
    int sum[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d", sum[i][j]);
            
            if (j < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
