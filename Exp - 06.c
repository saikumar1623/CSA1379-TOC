#include <stdio.h>
#include <string.h>

int belongsToGrammar(char *str, int start, int end)
{
    if (start > end)
        return 1;

    if (str[start] == '0' && str[end] == '1')
	{
        for (int i = start + 1; i < end; i++)
            if (belongsToGrammar(str, start + 1, i - 1) && belongsToGrammar(str, i + 1, end - 1))
                return 1;
    }
    return 0;
}

int main()
{
    char input[100];
    printf("Enter a String : ");
    scanf("%s", input);

    int length = strlen(input);
    int result = belongsToGrammar(input, 0, length - 1);

    if (result)
        printf("The Given String Belong to Context Free Grammar.\n");
    else
        printf("The Given String Doesn't Belong to Context Free Grammar.\n");
    return 0;
}