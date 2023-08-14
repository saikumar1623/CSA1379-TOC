#include <stdio.h>
#include <string.h>

int belongsToGrammar(char str[], int start, int end)
{
    if (start > end)
        return 1;
    
    if (str[start] == '0' && str[end] == '0')
	{
        int i = start + 1;
        while (i < end)
		{
            if (belongsToGrammar(str, start + 1, i - 1) && belongsToGrammar(str, i + 1, end - 1))
                return 1;
            i += 2;
        }
    }

    if (str[start] == '1' && belongsToGrammar(str, start + 1, end - 1))
        return 1;
    return 0;
}

int main()
{
    char str[100];
    printf("Enter a String : ");
    scanf("%s", str);

    int len = strlen(str);
    if (belongsToGrammar(str, 0, len - 1))
        printf("The Given String Belongs to Context Free Grammar.\n");
    else
        printf("The Given String Doesn't Belong to Context Free Grammar.\n");
    return 0;
}