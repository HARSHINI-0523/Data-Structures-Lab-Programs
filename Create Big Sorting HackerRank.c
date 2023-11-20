#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int stringAsInt(const void *pLeft, const void *pRight)
{
    const char *left = *(const char **)pLeft;
    const char *right = *(const char **)pRight;
    int leftLen = (int)strlen(left);
    int rightLen = (int)strlen(right);

    if (leftLen != rightLen)
    {
        return leftLen - rightLen;
    }

    else
    {
        return strcmp(left, right);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    char buffer[1000000 + 1];
    char **a = malloc(sizeof(char *) * (size_t)n);

    for (int i = 0; i < n; i++)
    {
        scanf("%1000000s", buffer);
        a[i] = malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(a[i], buffer);
    }

    qsort(a, (size_t)n, sizeof(a[0]), stringAsInt);

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", a[i]);
        free(a[i]);
    }

    free(a);
    return 0;
}
