#include <stdio.h>
#include <stdbool.h>

bool simulateNFA(const char *input)
{
    int currentState = 0;

    for (int i = 0; input[i] != '\0'; i++)
	{
        if (currentState == 0 && input[i] == '0')
            currentState = 1;
        else if (currentState == 1 && input[i] == '1')
            currentState = 2;
        else
		{
            currentState = -1;
            break;
        }
    }
    return (currentState == 2);
}

int main()
{
    char input[100];
    printf("Enter a String : ");
    scanf("%s", input);

    if (simulateNFA(input))
        printf("String Not Accepted.\n");
    else
        printf("String Accepted.\n");
    return 0;
}