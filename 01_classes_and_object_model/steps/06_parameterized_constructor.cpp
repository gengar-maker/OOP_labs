#include <cassert>
#include <iostream>

class Robot {
public:
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
    Robot first("R2D2", 80);
    Robot second(nullptr, 500);

    assert(first.energy() == 80);
    assert(second.energy() == 100);
    assert(second.name() != nullptr);

    first.print();
    second.print();
}
