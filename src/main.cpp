#include <iostream>

class Robot {
private:
    const char* name;
    float energy;
    int x;
    int y;
    bool active;

private:
    bool spendMovementEnergy() {
        if (energy < 1.5) {
            return false;
        }

        energy -= 1.5f;
        active = energy > 0;
        return true;
    }

public:
    Robot()
        : Robot("Unknown", 100, 0, 0) {
    }

    explicit Robot(const char* robotName)
        : Robot(robotName, 100, 0, 0) {
    }

    Robot(
        const char* robotName,
        float initialEnergy,
        int initialX,
        int initialY
    )
        : name(robotName),
          energy(initialEnergy),
          x(initialX),
          y(initialY),
          active(false)
    {
        if (name == nullptr) {
            name = "Unknown";
        }

        if (energy < 0) {
            energy = 0;
        } else if (energy > 100) {
            energy = 100;
        }

        active = energy > 0;
    }

    bool moveRight() {
        if (!spendMovementEnergy()) {
            return false;
        }

        ++x;
        return true;
    }

    bool moveLeft() {
        if (!spendMovementEnergy()) {
            return false;
        }

        --x;
        return true;
    }

    bool moveUp() {
        if (!spendMovementEnergy()) {
            return false;
        }

        ++y;
        return true;
    }

    bool moveDown() {
        if (!spendMovementEnergy()) {
            return false;
        }

        --y;
        return true;
    }

    void charge(int amount) {
        if (amount <= 0) {
            return;
        }

        if (amount > 100 - energy) {
            energy = 100;
        } else {
            energy += amount;
        }

        active = energy > 0;
    }

    const char* getName() const {
        return name;
    }

    float getEnergy() const {
        return energy;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    bool isActive() const {
        return active;
    }

    void printStatus() const {
        std::cout << "Robot " << name
                  << ": energy=" << energy
                  << ", position=(" << x << ", " << y << ')'
                  << ", active=" << std::boolalpha << active
                  << '\n';
    }
};

int main() {
    Robot defaultRobot;
    Robot namedRobot("R2D2");
    Robot lowEnergyRobot("Wall-E", 25, 3, 4);
    Robot emptyRobot(nullptr, -50, -2, 7);
    Robot overchargedRobot("ChargeBot", 150, 0, 0);

    defaultRobot.printStatus();
    namedRobot.printStatus();
    lowEnergyRobot.printStatus();
    emptyRobot.printStatus();
    overchargedRobot.printStatus();

    std::cout << "\nMovement test:\n";

    std::cout << lowEnergyRobot.moveRight() << '\n';
    std::cout << lowEnergyRobot.moveUp() << '\n';
    std::cout << lowEnergyRobot.moveLeft() << '\n';
    lowEnergyRobot.printStatus();

    std::cout << "\nCharging test:\n";

    lowEnergyRobot.charge(200);
    lowEnergyRobot.printStatus();

    return 0;
}
