#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int total_zero_sum_subarrays = 0;
    for (int i = 0; i < n; i++) {
        long long current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += arr[j];
            
            if (current_sum == 0) {
                total_zero_sum_subarrays++;
            }
        }
    }

    printf("%d\n", total_zero_sum_subarrays);
    return 0;
}
