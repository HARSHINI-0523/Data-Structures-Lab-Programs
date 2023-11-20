/*A program which linear search the characters*/
#include <stdio.h>

int main() {

    int n;
    printf("Enter the number of characters: ");
    scanf("%d", &n);

    char arr[n];
    printf("Enter the characters:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &arr[i]);
    }

    char x;
    printf("Enter the character to search: ");
    scanf(" %c", &x);

    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index: %d\n", index);
    }

    return 0;
}
