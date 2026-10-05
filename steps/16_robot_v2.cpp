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

    void chargeFully() {
        charge_ = max_charge;
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
    enum class Direction {
        left,
        right,
        up,
        down
    };

    Robot()
        : Robot("Unknown", 100) {
    }

    explicit Robot(const char* name)
        : Robot(name, 100) {
    }

    Robot(const char* name, int initial_energy)
        : name_(name == nullptr ? "Unknown" : name),
          battery_(initial_energy),
          active_(battery_.level() > 0) {
    }

    bool move(Direction direction) {
        Position next = position_;

        switch (direction) {
        case Direction::left:
            --next.x;
            break;
        case Direction::right:
            ++next.x;
            break;
        case Direction::up:
            ++next.y;
            break;
        case Direction::down:
            --next.y;
            break;
        default:
            return false;
        }

        if (!active_ || !battery_.spend(movement_cost)) {
            return false;
        }

        position_ = next;
        ++successful_moves_;
        return true;
    }

    void charge() {
        battery_.chargeFully();
    }

    void charge(int amount) {
        battery_.charge(amount);
    }

    void activate() {
        if (battery_.level() > 0) {
            active_ = true;
        }
    }

    void deactivate() {
        active_ = false;
    }

    const char* name() const { return name_; }
    int energy() const { return battery_.level(); }
    const Position& position() const { return position_; }
    bool isActive() const { return active_; }

    static int successfulMoves() {
        return successful_moves_;
    }

    void printStatus() const {
        std::cout << name()
                  << ": energy=" << energy()
                  << ", position=(" << position().x << ", " << position().y << ')'
                  << ", active=" << std::boolalpha << isActive() << '\n';
    }

private:
    static constexpr int movement_cost = 10;
    inline static int successful_moves_ = 0;

    const char* name_;
    Position position_;
    Battery battery_;
    bool active_ = true;
};

int main() {
    Robot first;
    Robot second("Atlas", 15);
    Robot third("Rover", -10);

    assert(first.energy() == 100);
    assert(second.energy() == 15);
    assert(third.energy() == 0);

    assert(second.move(Robot::Direction::right));
    assert(second.position().x == 1);
    assert(second.energy() == 5);
    assert(!second.move(Robot::Direction::up));
    assert(second.position().y == 0);

    second.charge(500);
    assert(second.energy() == 100);
    second.deactivate();
    assert(!second.move(Robot::Direction::left));
    second.activate();
    assert(second.move(Robot::Direction::up));

    third.activate();
    assert(!third.isActive());
    assert(!third.move(Robot::Direction::right));

    assert(Robot::successfulMoves() == 2);

    const Robot& view = second;
    assert(view.name() != nullptr);
    view.printStatus();
}
