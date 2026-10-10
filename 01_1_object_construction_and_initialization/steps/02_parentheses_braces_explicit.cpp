#include <cassert>

class Battery {
public:
    explicit Battery(int charge)
        : charge_(normalize(charge)) {
    }

    int charge() const {
        return charge_;
    }

private:
    static int normalize(int value) {
        if (value < 0) {
            return 0;
        }
        if (value > 100) {
            return 100;
        }
        return value;
    }

    int charge_;
};

int main() {
    Battery with_parentheses(80);
    Battery with_braces{70};

    assert(with_parentheses.charge() == 80);
    assert(with_braces.charge() == 70);

    // Battery implicit = 60; // Ошибка: конструктор explicit.
    // Battery narrowing{19.9}; // Ошибка: {} запрещают narrowing.
    // Battery conversion(19.9); // Компилируется, но теряет дробную часть.
}
