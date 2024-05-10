//
// Created by flo on 2/14/24.
//
#ifndef GOL_SFML_COLONY_H
#define GOL_SFML_COLONY_H

class Colony {
private:
    bool state;
    bool next_state;
public:
    Colony(bool initial_state);
    bool getState() const;
    // Here, the rules are applied
    void calculateNextState(int alive_neighbors);

    void evolve();
};

#endif //GOL_SFML_COLONY_H
