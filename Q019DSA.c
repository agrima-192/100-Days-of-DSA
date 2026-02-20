#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    if (scanf("%d", &n) != 1 || n < 2) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int first = arr[0];
    int second = arr[1];
    int min_sum = first + second;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int current_sum = arr[i] + arr[j];
            if (abs(current_sum) < abs(min_sum)) {
                min_sum = current_sum;
                first = arr[i];
                second = arr[j];
            }
        }
    }
    printf("%d %d\n", first, second);
    return 0;
}
