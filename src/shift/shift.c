#include <math.h>
#include <stdio.h>

int From2To10(int* arr, int N)
{
    int a = 0;
    for (int i = N - 1; i >= 0; i--) {
        a += arr[i] * (int)pow(2, N - 1 - i);
    }
    return a;
}

int biggest(int* arr, int N)
{
    int m = From2To10(arr, N);
    for (int i = 0; i < N; i++) {
        int x = arr[0];
        for (int j = 0; j < N - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[N - 1] = x;
        int n = From2To10(arr, N);
        if (n > m) {
            m = n;
        }
    }
    return m;
}

int main()
{
    int b[] = { 1, 0, 0, 1, 0 };
    int N = 5;
    printf("%d", biggest(b, N));
}
