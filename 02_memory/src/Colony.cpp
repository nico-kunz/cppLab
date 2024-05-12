
#include "Colony.hpp"

// TODO: 2.1
Colony::Colony(bool initial_state) {
    state = initial_state;
}

bool Colony::getState() const {
    return state;
}

void Colony::evolve() {
    state = next_state;
}

void Colony::calculateNextState(int alive_neighbors) {

    if(state) {
        if (alive_neighbors < 2 || alive_neighbors > 3)
            next_state = false;
        else
            next_state = true;
    } else {
        if(alive_neighbors == 3)
            next_state = true;
        else
            next_state = false;
    }
}