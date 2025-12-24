#include "quicksort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int arr[100];
    int index = 0;
    int count = 0;
    while (scanf("%d", &arr[index]) == 1) {
        index++;
    }
    int* numbers = (int*)malloc(sizeof(int) * index);
    memcpy(numbers, arr, index * sizeof(int));
    quicksort(numbers, index);
    for (int i = 0; i < index; i++) {
        if (numbers[i] != arr[i]) {
            count++;
        }
    }
    free(numbers);
    return count;
}
