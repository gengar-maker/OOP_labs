#include <cassert>
#include <iostream>

struct Position {
    int x = 0;
    int y = 0;
};

class Battery {
public:
    explicit Battery(int initial_charge = max_charge)
        : charge_(normalize(initial_charge)) {
    }

    bool spend(int amount) {
        if (amount <= 0 || amount > charge_) {
            return false;
        }

        charge_ -= amount;
        return true;
    }

    void charge(int amount) {
        if (amount <= 0) {
            return;
        }

        if (amount > max_charge - charge_) {
            charge_ = max_charge;
        } else {
            charge_ += amount;
        }
    }

    int level() const {
        return charge_;
    }

private:
    static constexpr int max_charge = 100;

    static int normalize(int value) {
        if (value < 0) {
            return 0;
        }
        if (value > max_charge) {
            return max_charge;
        }
        return value;
    }

    int charge_;
};

class Robot {
public:
    Robot(const char* name, int initial_energy)
        : name_(name == nullptr ? "Unknown" : name),
          battery_(initial_energy) {
    }

    bool moveBy(int dx, int dy) {
        if (!battery_.spend(movement_cost)) {
            return false;
        }

        position_.x += dx;
        position_.y += dy;
        return true;
    }

    void charge(int amount) {
        battery_.charge(amount);
    }

    const Position& position() const {
        return position_;
    }

    int energy() const {
        return battery_.level();
    }

    void print() const {
        std::cout << name_
                  << ": energy=" << energy()
                  << ", position=(" << position_.x << ", " << position_.y << ")\n";
    }

private:
    static constexpr int movement_cost = 10;
    const char* name_;
    Position position_;
    Battery battery_;
};

int main() {
    Robot robot("Atlas", 20);

    assert(robot.moveBy(1, 0));
    assert(robot.moveBy(0, 1));
    assert(!robot.moveBy(1, 0));
    assert(robot.position().x == 1);
    assert(robot.position().y == 1);
    assert(robot.energy() == 0);

    robot.charge(15);
    assert(robot.energy() == 15);
    robot.print();
}
