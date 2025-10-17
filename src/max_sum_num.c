#include <stdio.h>
int sum_of_num(int a) {
    int s = 0;
    if (a < 0) {
        a = a * -1;
    }
    while (a / 10 != 0) {
        s = s + (a % 10);
        a = a / 10;
    }
    return s + a;
}
int main() {
    int arr[] = { 2, -879, 432, 9708, 908, 789 };
    int l = sizeof(arr) / sizeof(arr[0]);
    int arr_sum[6];
    int maximum = 0;
    for (int i = 0; i < l; i++) {
        arr_sum[i] = sum_of_num(arr[i]);
        if (arr_sum[i] > maximum) {
            maximum = arr_sum[i];
        }
    }
    for (int i = 0; i < l; i++) {
        if (arr_sum[i] == maximum) {
            printf("%d\t", arr[i]);
        }
    }

    return 0;
}