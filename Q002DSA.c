#include <stdio.h>

int main() {
    int n, pos, i;

    // Input the size of the array
    if (scanf("%d", &n) != 1) return 1;

    int arr[n];

    // Input n space-separated integers
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the 1-based position to delete
    scanf("%d", &pos);

    // Validate position and shift elements left
    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
    } else {
        // Shift elements starting from the deletion point (pos-1)
        for (i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        // Print updated array with (n-1) elements
        for (i = 0; i < n - 1; i++) {
            printf("%d%c", arr[i], (i == n - 2) ? '\n' : ' ');
        }
    }

    return 0;
}
