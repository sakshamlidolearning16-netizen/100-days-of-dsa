#include <stdio.h>
#include <stdlib.h>

// Structure for car
typedef struct {
    int pos;
    int speed;
} Car;

// Comparator: sort by position descending
int compare(const void *a, const void *b) {
    Car *x = (Car *)a;
    Car *y = (Car *)b;
    return y->pos - x->pos;
}

int carFleet(int target, int position[], int speed[], int n) {
    Car cars[n];

    // Step 1: store data
    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].speed = speed[i];
    }

    // Step 2: sort by position descending
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0.0;

    // Step 3: process cars
    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    return fleets;
}

int main() {
    int target, n;

    scanf("%d", &target);
    scanf("%d", &n);

    int position[n], speed[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &position[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    printf("%d\n", carFleet(target, position, speed, n));

    return 0;
}