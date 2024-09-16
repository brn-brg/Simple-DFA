#ifndef DFA_H
#define DFA_H

#define NUMSTATES 3
#define NUMINPUTS 2
#define INVALID_STATE -1

struct state {
    int name;
    struct state* next_state[NUMINPUTS]; // Transitions for each input (0, 1)
    int is_final;
};

void initialize_states(struct state states[NUMSTATES], int transition_matrix[NUMSTATES][4]);
void link_transitions(struct state states[NUMSTATES], int transition_matrix[NUMSTATES][4]);
int simulate_dfa(struct state* start_state, const char* input_string);

#endif

