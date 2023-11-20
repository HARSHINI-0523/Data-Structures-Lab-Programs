/*A program which binary search the strings*/
#include <stdio.h>
#include <string.h>

int main() {

    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char arr[n][100];
    printf("Enter the sorted strings:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    char x[100];
    printf("Enter the string to search: ");
    scanf("%s", x);

    int low = 0, high = n - 1;
    int index = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int res = strcmp(arr[mid], x);
        if (res == 0) {
            index = mid;
            break;
        } else if (res < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (index == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index: %d\n", index);
    }
    return 0;
}
