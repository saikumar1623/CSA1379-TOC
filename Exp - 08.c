#include <stdio.h>
#include <stdbool.h>

int transitions[][3] = {
    {1, -1, -1}, {1, 2, -1}, {1, -1, 3}, {3, -1, 3}
};

bool simulateNFA(const char *input)
{
    int currentState = 0;

    for (int i = 0; input[i] != '\0'; i++)
	{
        char symbol = input[i];
        int symbolIndex = -1;

        if (symbol == 'b')
            symbolIndex = 0;
        else if (symbol == 'a')
            symbolIndex = 1;
        else
            return false;

        int nextState1 = transitions[currentState][symbolIndex];
        int nextState2 = transitions[currentState][2];

        if (nextState1 == -1 && nextState2 == -1)
            return false;

        if (nextState1 != -1)
            currentState = nextState1;
        else
            currentState = nextState2;
    }
    return currentState == 3;
}

int main()
{
    char input[100];
    printf("Enter a String : ");
    scanf("%s", input);

    if (simulateNFA(input))
        printf("Accepted\n");
    else
        printf("Rejected\n");
    return 0;
}