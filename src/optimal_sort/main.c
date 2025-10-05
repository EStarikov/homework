#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    int arr[100];
    int index = 0;
    int count = 0;
    while (scanf("%d", &arr[index]) == 1) {
        index++;
    }
    int* numbers = (int*)malloc(sizeof(int) * index);
    for (int i = 0; i < index; i++) {
        numbers[i] = arr[i];
    }

    quicksort(numbers, index);
    for (int i = 0; i < index; i++) {
        if (numbers[i] != arr[i]) {
            count++;
        }
    }
    printf("%d", count);
    free(numbers);
    return 0;
}