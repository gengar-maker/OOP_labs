#include <cassert>
#include <iostream>

class Player {
public:
    void takeDamage(int amount) {
        if (amount <= 0 || !alive_) {
            return;
        }

        if (amount >= health_) {
            health_ = 0;
            alive_ = false;
        } else {
            health_ -= amount;
        }
    }

    void heal(int amount) {
        if (amount <= 0 || !alive_) {
            return;
        }

        if (amount > max_health - health_) {
            health_ = max_health;
        } else {
            health_ += amount;
        }
    }

    int health() const {
        return health_;
    }

    bool isAlive() const {
        return alive_;
    }

    void print() const {
        std::cout << "health=" << health_
                  << ", alive=" << std::boolalpha << alive_ << '\n';
    }

private:
    static constexpr int max_health = 100;
    int health_ = max_health;
    bool alive_ = true;
};

int main() {
    Player player;

    player.takeDamage(30);
    assert(player.health() == 70);
    assert(player.isAlive());

    player.heal(1000);
    assert(player.health() == 100);

    player.takeDamage(100);
    assert(player.health() == 0);
    assert(!player.isAlive());

    player.print();
}
