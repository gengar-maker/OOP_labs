#include <iostream>

struct Player {
    const char* name = "Unknown";
    int health = 100;
    int x = 0;
    int y = 0;
    bool alive = true;

    void takeDamage(int amount) {
        if (amount <= 0 || !alive) {
            return;
        }

        if (amount >= health) {
            health = 0;
            alive = false;
        } else {
            health -= amount;
        }
    }

    void heal(int amount) {
        if (amount <= 0 || !alive) {
            return;
        }

        if (amount > 100 - health) {
            health = 100;
        } else {
            health += amount;
        }
    }

    void print() const {
        std::cout << name << ": health=" << health
                  << ", alive=" << std::boolalpha << alive << '\n';
    }
};

int main() {
    Player player{"Alex", 100, 0, 0, true};

    player.takeDamage(35);
    player.heal(10);
    player.print();

    player.takeDamage(1000);
    player.heal(100);
    player.print();
}
