#include <stdio.h>
#include <string.h>
#include "dfa.h"

int main() {
    // Transition table for the DFA (state_name, next_state_0, next_state_1, is_final)
    // DFA for the regex 0*11 
    int transition_matrix[NUMSTATES][4] = {
        {0, 0, 1, 0},  // State 0: 0 -> 0, 1 -> 1, not final
        {1, INVALID_STATE, 2, 0},  // State 1: no transition on '0', 1 -> 2, not final
        {2, INVALID_STATE, INVALID_STATE, 1}   // State 2: final state, no transitions
    };

    struct state dfa_states[NUMSTATES];

    initialize_states(dfa_states, transition_matrix);
    link_transitions(dfa_states, transition_matrix);

    char input_string[100];
    while (1) {
        printf("\nInput string (type 'q' to quit): ");
        scanf("%s", input_string);

        if (strcmp(input_string, "q") == 0) {
            break;
        }

        if (simulate_dfa(&dfa_states[0], input_string)) {
            printf("The string '%s' is accepted.\n\n", input_string);
        } else {
            printf("The string '%s' is rejected.\n\n", input_string);
        }
    }

    return 0;
}

