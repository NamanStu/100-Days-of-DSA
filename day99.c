#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    int speed;
} Car;

int compare(const void* a, const void* b) {
    Car* x = (Car*)a;
    Car* y = (Car*)b;
    return y->pos - x->pos;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    Car cars[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &cars[i].pos);
    for (int i = 0; i < n; i++)
        scanf("%d", &cars[i].speed);

    qsort(cars, n, sizeof(Car), compare);

    double lastTime = 0.0;
    int fleets = 0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    printf("%d\n", fleets);

    return 0;
}