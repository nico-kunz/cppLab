#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#include "Board.hpp"
#include "Random_player.hpp"
#include "Cheating_player.hpp"

int main() {

    constexpr size_t ROUNDS = 1000;
    constexpr size_t DIM = 10;

    const std::vector<Ship> fleet = {
        Ship(5, "dreadnought"),
        Ship(4, "cruiser"),
        Ship(4, "cruiser"),
        Ship(3, "destroyer"),
        Ship(3, "destroyer"),
        Ship(3, "destroyer"),
        Ship(2, "submarine"),
        Ship(2, "submarine"),
        Ship(2, "submarine"),
        Ship(2, "submarine"),
        Ship(2, "submarine"),
    };

    std::vector<std::pair<size_t, size_t>> stats{};
    stats.reserve(ROUNDS);

    for (size_t i = 0; i < ROUNDS; ++i) {
        Board b1 = Board(DIM);
        Board b2 = Board(DIM);

        b1.place_fleet_randomly(fleet);
        b2.place_fleet_randomly(fleet);

        Player* p1 = new RandomPlayer(b2);
        Player* p2 = new RandomPlayer(b1);

        size_t shots = 0;

        while (true) {
            p1->performNextMove();

            p2->performNextMove();

            if (b2.fleet_destroyed() && b1.fleet_destroyed()) {
                stats.push_back({ 0, shots });
                break;
            }
            else if (b2.fleet_destroyed()) {
                stats.push_back({ 1, shots });
                break;
            }
            else if (b1.fleet_destroyed()) {
                stats.push_back({ 2, shots });
                break;
            }

            ++shots;
        }

        delete p1;
        delete p2;
    }

    const size_t p1_wins = std::count_if(stats.cbegin(), stats.cend(), [](auto v) { return v.first == 1; });
    const size_t p2_wins = std::count_if(stats.cbegin(), stats.cend(), [](auto v) { return v.first == 2; });
    const size_t ties = ROUNDS - p1_wins - p2_wins;
    const size_t cumulated_shots = std::accumulate(stats.cbegin(), stats.cend(), 0, [](size_t acc, auto v) { return acc + v.second; });

    std::cout << ROUNDS << " were played\n";
    std::cout << "player 1 won " << p1_wins << " rounds (" << (double)p1_wins / ROUNDS * 100 << "%)\n";
    std::cout << "player 2 won " << p2_wins << " rounds (" << (double)p2_wins / ROUNDS * 100 << "%)\n";
    std::cout << ties << " rounds ended in a tie (" << (double)ties / ROUNDS * 100 << "%)\n";
    std::cout << "the average number of shots needed was " << (double)cumulated_shots / ROUNDS << "\n";

    return 0;
}
