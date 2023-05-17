#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double weight;
    double value;
    double ratio;
} Item;

int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    return (itemB->ratio - itemA->ratio) > 0 ? 1 : -1;
}

double fractionalKnapsack(int capacity, Item items[], int n) {
    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0;
    int i;

    for (i = 0; i < n; i++) {
        if (capacity <= 0)
            break;

        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += (capacity / items[i].weight) * items[i].value;
            break;
        }
    }

    return totalValue;
}

int main() {
    int capacity = 50;
    Item items[] = {
        {10, 60, 0},  // item 1: weight = 10, value = 60
        {20, 100, 0}, // item 2: weight = 20, value = 100
        {30, 120, 0}  // item 3: weight = 30, value = 120
    };
    int n = sizeof(items) / sizeof(items[0]);

    for (int i = 0; i < n; i++) {
        items[i].ratio = items[i].value / items[i].weight;
    }

    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value: %.2f\n", maxValue);

    return 0;
}
