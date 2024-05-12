
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
    // if less than 2 or more than 3 neighbors, die because of over-/underpopulation
    if (state && (alive_neighbors < 2 || alive_neighbors > 3)) {
        next_state = false;
    }

    // Colony will be revived if it has 3 neighbors because of Expansion
    if (!state && alive_neighbors == 3) {
        next_state = true;
    }
}