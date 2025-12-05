#include <stdio.h>
int per(int a) {
    int b[100];
    int index = 0;
    while (a >= 2) {
        b[index] = a % 2;
        a = a / 2;
        ++index;
    }
    b[index] = a; // число будет записано задом наперед, но для палиндрома это не важно
    int l = 0;
    int r = index;
    while (l < r) {
        if (b[l] != b[r]) {
            return 0;
        }
        ++l;
        --r;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        if (per(i) == 1) {
            printf("%d\n", i);
        }
    }
    return 0;
}