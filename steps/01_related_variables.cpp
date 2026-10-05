#include <iostream>

int main() {
    const char* player_name = "Alex";
    int player_health = 100;
    int player_x = 0;
    int player_y = 0;
    bool player_alive = true;

    std::cout << player_name
              << ": health=" << player_health
              << ", position=(" << player_x << ", " << player_y << ')'
              << ", alive=" << std::boolalpha << player_alive << '\n';
}
