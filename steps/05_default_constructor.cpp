#include <cassert>
#include <iostream>

class Robot {
public:
    Robot() = default;

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
    const char* name_ = "Unknown";
    int energy_ = 100;
    int x_ = 0;
    int y_ = 0;
    bool active_ = true;
};

int main() {
    Robot robot;
    assert(robot.name() != nullptr);
    assert(robot.energy() == 100);
    robot.print();
}
