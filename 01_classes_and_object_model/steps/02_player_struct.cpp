#include <iostream>

struct Player {
    const char* name;
    int health;
    int x;
    int y;
    bool alive;
};

void printPlayer(const Player& player) {
    std::cout << player.name
              << ": health=" << player.health
              << ", position=(" << player.x << ", " << player.y << ')'
              << ", alive=" << std::boolalpha << player.alive << '\n';
}

int main() {
    Player first{"Alex", 100, 0, 0, true};
    Player second{"Sam", 80, 5, 2, true};

    first.health = 90;
    ++second.x;

    printPlayer(first);
    printPlayer(second);
}
