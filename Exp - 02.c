#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int transition(int state, char input)
{
    switch (state)
	{
        case 0:
            if (input == '0') return 1;
            else return 0;
        case 1:
            if (input == '0') return 1;
            else if (input == '1') return 2;
            else return 0;
        case 2:
            if (input == '1') return 2;
            else return 0;
    }
    return 0;
}

bool simulateDFA(char *input)
{
    int currentState = 0;
    int inputLength = strlen(input);
    
    for (int i = 0; i < inputLength; i++)
        currentState = transition(currentState, input[i]);
    
    return currentState == 2;
}

int main()
{
    char input[100];
    printf("Enter a String : ");
    scanf("%s", input);
    
    if (simulateDFA(input))
        printf("Accepted\n");
    else
        printf("Not Accepted\n");    
    return 0;
}