#include <cassert>
#include <iostream>

class Robot {
public:
    Robot();
    explicit Robot(const char* name);

    void charge();
    void charge(int amount);
    int energy() const;
    const char* name() const;
    void print() const;

private:
    static constexpr int max_energy = 100;
    const char* name_;
    int energy_;
};

Robot::Robot()
    : Robot("Unknown") {
}

Robot::Robot(const char* name)
    : name_(name == nullptr ? "Unknown" : name),
      energy_(0) {
}

void Robot::charge() {
    charge(max_energy);
}

void Robot::charge(int amount) {
    if (amount <= 0) {
        return;
    }

    if (amount > max_energy - energy_) {
        energy_ = max_energy;
    } else {
        energy_ += amount;
    }
}

int Robot::energy() const {
    return energy_;
}

const char* Robot::name() const {
    return name_;
}

void Robot::print() const {
    std::cout << name() << ": energy=" << energy() << '\n';
}

int main() {
    Robot robot("Atlas");

    robot.charge(30);
    assert(robot.energy() == 30);

    robot.charge();
    assert(robot.energy() == 100);
    robot.print();
}
