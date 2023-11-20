#include<stdio.h>

int main() {
    int disk, temp[100001] = {0};
    scanf("%d", &disk);

    int min = disk, size = disk;
    int q;

    for (int i = 0; i < disk; i++) {
        scanf("%d", &q);
        temp[q] = q;

        if(q == min) {
            while(temp[size]) {
                printf("%d ", size);
                size--;
            }
            min = size;
            printf("\n");
        }
    }
}
