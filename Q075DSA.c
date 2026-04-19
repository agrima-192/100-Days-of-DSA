#include <stdio.h>

int findMaxLength(int arr[], int n) {
    int max_len = 0;
    int current_sum = 0;

    for (int i = 0; i < n; i++) {
        current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += arr[j];

            if (current_sum == 0) {
                int length = j - i + 1;
                if (length > max_len) {
                    max_len = length;
                }
            }
        }
    }
    return max_len;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", findMaxLength(arr, n));

    return 0;
}
