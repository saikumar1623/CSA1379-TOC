#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int dfa_transition(int state, char input)
{
    if (state == 0 && input == 'a')
        return 1;
    else if (state == 1 && input == 'a')
        return 1;
    else
        return 0;
}

bool simulate_dfa(const char *input)
{
    int current_state = 0;
    int input_length = strlen(input);

    for (int i = 0; i < input_length; i++)
        current_state = dfa_transition(current_state, input[i]);
    return current_state == 1;
}

int main()
{
    char input[100];
    printf("Enter a String : ");
    scanf("%s", input);

    if (simulate_dfa(input))
        printf("String Accepted.\n");
    else
        printf("String Not Accepted.\n");
    return 0;
}