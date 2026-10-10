#include <iostream>

class TracedRobot {
public:
    explicit TracedRobot(const char* name)
        : name_(name == nullptr ? "Unknown" : name) {
        std::cout << "constructed: " << name_ << '\n';
    }

    ~TracedRobot() {
        std::cout << "destroyed: " << name_ << '\n';
    }

private:
    const char* name_;
};

void runDemo() {
    TracedRobot local("Local");
    std::cout << "inside runDemo\n";
}

int main() {
    TracedRobot outer("Outer");

    {
        TracedRobot inner("Inner");
        std::cout << "inside nested scope\n";
    }

    runDemo();
    std::cout << "leaving main\n";
}
