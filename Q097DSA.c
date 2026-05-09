#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compareIntervals(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

void minHeapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        minHeapify(heap, size, smallest);
    }
}

void push(int heap[], int* size, int value) {
    heap[*size] = value;
    int i = *size;
    (*size)++;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void pop(int heap[], int* size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    minHeapify(heap, *size, 0);
}

int minMeetingRooms(Interval* intervals, int intervalsSize) {
    if (intervalsSize <= 0) return 0;

    qsort(intervals, intervalsSize, sizeof(Interval), compareIntervals);

    int* heap = (int*)malloc(sizeof(int) * intervalsSize);
    int heapSize = 0;

    push(heap, &heapSize, intervals[0].end);

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i].start >= heap[0]) {
            pop(heap, &heapSize);
        }
        push(heap, &heapSize, intervals[i].end);
    }

    int result = heapSize;
    free(heap);
    return result;
}

int main() {
    Interval meetings[] = {{0, 30}, {5, 10}, {15, 20}};
    int n = sizeof(meetings) / sizeof(meetings[0]);
    printf("%d\n", minMeetingRooms(meetings, n));
    return 0;
}
