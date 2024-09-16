#include "dfa.h"
#include <stdio.h>

void initialize_states(struct state states[NUMSTATES], int transition_matrix[NUMSTATES][4]) {
    for (int i = 0; i < NUMSTATES; ++i) {
        states[i].name = transition_matrix[i][0];
        states[i].is_final = transition_matrix[i][3];
    }
}

// Link DFA transitions based on the transition matrix
void link_transitions(struct state states[NUMSTATES], int transition_matrix[NUMSTATES][4]) {
    for (int i = 0; i < NUMSTATES; ++i) {
        states[i].next_state[0] = (transition_matrix[i][1] != INVALID_STATE) ? &states[transition_matrix[i][1]] : NULL;
        states[i].next_state[1] = (transition_matrix[i][2] != INVALID_STATE) ? &states[transition_matrix[i][2]] : NULL;
    }
}


int simulate_dfa(struct state* start_state, const char* input_string) {
    struct state* current_state = start_state;

    for (int i = 0; input_string[i] != '\0'; i++) {
        int symbol = input_string[i] - '0'; 

        if (symbol < 0 || symbol >= NUMINPUTS) {
            printf("Invalid input character: %c\n", input_string[i]);
            return 0; 
        }

        current_state = current_state->next_state[symbol];

        if (current_state == NULL) {
            return 0; // Rejected
        }
    }

    return current_state->is_final;
}

