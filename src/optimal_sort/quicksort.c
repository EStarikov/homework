#include "functions.h"

void quicksort(int* mas, int size) {
    int i = 0;
    int j = size - 1;
    int mid = mas[size / 2];

    while (i <= j) {
        while (mas[i] < mid) {
            i++;
        }
        while (mas[j] > mid) {
            j--;
        }

        if (i <= j) {
            int t = mas[i];
            mas[i] = mas[j];
            mas[j] = t;
            i++;
            j--;
        }
    }

    if (j > 0) {
        quicksort(mas, ++j);
    }
    if (i < size) {
        quicksort(&mas[i], size - i);
    }
}