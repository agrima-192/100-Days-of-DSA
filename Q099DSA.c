#include <stdio.h>
#include <stdlib.h>

struct Car {
    int p;
    float t;
};

int cmp(const void* a, const void* b) {
    return ((struct Car*)b)->p - ((struct Car*)a)->p;
}

int main() {
    int target, n;

    printf("Enter target distance and number of cars: ");
    scanf("%d %d", &target, &n);

    if (n <= 0) {
        printf("0\n");
        return 0;
    }

    struct Car *cars = malloc(n * sizeof(struct Car));
    int *pos = malloc(n * sizeof(int));
    int *spd = malloc(n * sizeof(int));

    printf("Enter positions: ");
    for (int i = 0; i < n; i++) scanf("%d", &pos[i]);

    printf("Enter speeds: ");
    for (int i = 0; i < n; i++) scanf("%d", &spd[i]);

    for (int i = 0; i < n; i++) {
        cars[i].p = pos[i];
        cars[i].t = (float)(target - pos[i]) / spd[i];
    }

    qsort(cars, n, sizeof(struct Car), cmp);

    int fleets = 0;
    float max_t = 0;
    for (int i = 0; i < n; i++) {
        if (cars[i].t > max_t) {
            max_t = cars[i].t;
            fleets++;
        }
    }

    printf("Number of fleets: %d\n", fleets);

    free(cars);
    free(pos);
    free(spd);
    return 0;
}
