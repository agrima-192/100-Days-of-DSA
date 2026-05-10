#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start, end;
};

int compare(const void* a, const void* b) {
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}

void mergeIntervals(struct Interval arr[], int n) {
    if (n <= 0) return;

    qsort(arr, n, sizeof(struct Interval), compare);

    int j = 0; 
    for (int i = 1; i < n; i++) {
        if (arr[j].end >= arr[i].start) {
            if (arr[j].end < arr[i].end) {
                arr[j].end = arr[i].end;
            }
        } else {
            j++;
            arr[j] = arr[i];
        }
    }

    for (int i = 0; i <= j; i++) {
        printf("[%d, %d] ", arr[i].start, arr[i].end);
    }
}

int main() {
    struct Interval arr[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}
