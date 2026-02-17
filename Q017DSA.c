#include <stdio.h>

int main() {
    int n, i;
    int max, min;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Please enter a positive integer for the size.\n");
        return 1;
    }
    int arr[n];
    printf("Enter %d numbers: ", n);
    for(i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Error: Invalid input. Please enter integers only.\n");
            return 1;
        }
    }
    max = arr[0];
    min = arr[0];
    for(i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    return 0;
}
