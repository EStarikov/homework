#include <stdio.h>
#include <stdlib.h>
void mon_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int x = rand() % n;
        int temp = arr[i];
        arr[i] = arr[x];
        arr[x] = temp;
    }
}
int check(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            return 1;
        }
    }
    return 0;
}
int main() {
    int flag = 1;
    int list[] = { 4, 6, 2, 3 };
    int l = sizeof(list) / sizeof(list[0]);
    while (check(list, l) == 1) {
        mon_sort(list, l);
    }
    for (int i = 0; i < l; ++i) {
        printf("%d\t", list[i]);
    }
    return 0;
}