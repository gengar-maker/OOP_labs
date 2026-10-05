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
          energy_(normalizeEnergy(initial_energy)) {
    }

    const char* name() const {
        return name_;
    }

    int energy() const {
        return energy_;
    }

    void print() const {
        std::cout << name_ << ": energy=" << energy_
                  << ", position=(" << x_ << ", " << y_ << ')'
                  << ", active=" << std::boolalpha << active_ << '\n';
    }

private:
    static int normalizeEnergy(int value) {
        if (value < 0) {
            return 0;
        }
        if (value > 100) {
            return 100;
        }
        return value;
    }

    const char* name_;
    int energy_;
    int x_ = 0;
    int y_ = 0;
    bool active_ = true;
};

int main() {
    Robot first;
    Robot second("Atlas");
    Robot third("Rover", -20);

    // Robot accidental = "C3PO"; // Не компилируется из-за explicit.

    assert(first.energy() == 100);
    assert(second.energy() == 100);
    assert(third.energy() == 0);

    first.print();
    second.print();
    third.print();
}
