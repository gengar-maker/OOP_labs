#include <cassert>
#include <iostream>

class Robot {
public:
    Robot()
        : Robot("Unknown", 100) {
    }

    explicit Robot(const char* robot_name)
        : Robot(robot_name, 100) {
    }

    Robot(const char* robot_name, int initial_energy)
        : name_(robot_name == nullptr ? "Unknown" : robot_name),
          energy_(normalizeEnergy(initial_energy)),
          active_(true) {
    }

    bool moveLeft() {
        if (!spendMovementEnergy()) {
            return false;
        }
        --x_;
        return true;
    }

    bool moveRight() {
        if (!spendMovementEnergy()) {
            return false;
        }
        ++x_;
        return true;
    }

    bool moveUp() {
        if (!spendMovementEnergy()) {
            return false;
        }
        ++y_;
        return true;
    }

    bool moveDown() {
        if (!spendMovementEnergy()) {
            return false;
        }
        --y_;
        return true;
    }

    void charge(int amount) {
        if (amount <= 0) {
            return;
        }

        if (amount > max_energy - energy_) {
            energy_ = max_energy;
        } else {
            energy_ += amount;
        }
    }

    void deactivate() {
        active_ = false;
    }

    const char* getName() const { return name_; }
    int getEnergy() const { return energy_; }
    int getX() const { return x_; }
    int getY() const { return y_; }
    bool isActive() const { return active_; }

    void printStatus() const {
        std::cout << getName()
                  << ": energy=" << getEnergy()
                  << ", position=(" << getX() << ", " << getY() << ')'
                  << ", active=" << std::boolalpha << isActive() << '\n';
    }

private:
    static constexpr int max_energy = 100;
    static constexpr int movement_cost = 10;

    static int normalizeEnergy(int value) {
        if (value < 0) {
            return 0;
        }
        if (value > max_energy) {
            return max_energy;
        }
        return value;
    }

    bool spendMovementEnergy() {
        if (!active_ || energy_ < movement_cost) {
            return false;
        }
        energy_ -= movement_cost;
        return true;
    }

    const char* name_;
    int energy_;
    int x_ = 0;
    int y_ = 0;
    bool active_;
};

int main() {
    Robot first;
    Robot second("Atlas");
    Robot third("Rover", 15);

    assert(first.getEnergy() == 100);
    assert(second.getEnergy() == 100);

    assert(third.moveRight());
    assert(third.getX() == 1);
    assert(third.getEnergy() == 5);

    assert(!third.moveUp());
    assert(third.getY() == 0);

    third.charge(500);
    assert(third.getEnergy() == 100);

    third.deactivate();
    assert(!third.moveLeft());

    third.printStatus();
}
