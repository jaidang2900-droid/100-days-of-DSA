#include <stdlib.h>

// Structure for car
typedef struct {
    int position;
    double time;
} Car;

// Sort by position descending
int cmp(const void* a, const void* b) {
    Car* c1 = (Car*)a;
    Car* c2 = (Car*)b;
    return c2->position - c1->position;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    if (positionSize == 0) return 0;

    // Step 1: Create car array
    Car* cars = (Car*)malloc(sizeof(Car) * positionSize);

    for (int i = 0; i < positionSize; i++) {
        cars[i].position = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // Step 2: Sort by position descending
    qsort(cars, positionSize, sizeof(Car), cmp);

    // Step 3: Count fleets
    int fleets = 0;
    double prevTime = 0.0;

    for (int i = 0; i < positionSize; i++) {
        if (cars[i].time > prevTime) {
            fleets++;
            prevTime = cars[i].time;
        }
    }

    free(cars);
    return fleets;
}