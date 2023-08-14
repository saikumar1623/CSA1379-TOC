#include <stdio.h>
#include <string.h>

int belongsToCFG(char *str, int start, int end)
{
    if (start > end)
        return 1;

    if (str[start] == '0' && str[end] == '0')
        return belongsToCFG(str, start + 1, end - 1);
    else if (str[start] == '1' && str[end] == '1')
        return belongsToCFG(str, start + 1, end - 1);
    else if (str[start] == '0')
        return belongsToCFG(str, start + 1, end);
    else if (str[start] == '1')
        return belongsToCFG(str, start + 1, end);
    return 0;
}

int main()
{
    char str[100];
    printf("Enter a String : ");
    scanf("%s", str);

    int len = strlen(str);

    if (belongsToCFG(str, 0, len - 1))
        printf("String Belongs to Context Free Grammar.\n");
    else
        printf("String Doesn't Belong to Context Free Grammar.\n");
    return 0;
}