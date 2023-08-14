#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 50
#define MAX_TRANSITIONS 50

typedef struct
{
    int state;
    int transition[MAX_TRANSITIONS];
} NFAState;

NFAState nfa[MAX_STATES];
int numStates;

void epsilonClosure(int state, bool visited[])
{
    visited[state] = true;

    for (int i = 0; nfa[state].transition[i] != -1; i++)
	{
        int nextState = nfa[state].transition[i];
        if (!visited[nextState])
            epsilonClosure(nextState, visited);
    }
}

int main()
{
    printf("Enter Number of States in NFA: ");
    scanf("%d", &numStates);

    for (int i = 0; i < numStates; i++)
	{
        nfa[i].state = i;

        printf("Enter Number of Epsilon Transitions For State %d (Enter -1 to End) : ", i);
        int numTransitions = 0;
        do
		{
            scanf("%d", &nfa[i].transition[numTransitions]);
            numTransitions++;
        }
		while (nfa[i].transition[numTransitions - 1] != -1);
    }

    printf("\nEpsilon-Closure For Each State :\n");
    for (int i = 0; i < numStates; i++)
	{
        bool visited[MAX_STATES] = {false};
        epsilonClosure(i, visited);

        printf("Epsilon-Closure of State %d : ", i);
        for (int j = 0; j < numStates; j++)
            if (visited[j])
                printf("%d ", j);
        printf("\n");
    }
    return 0;
}