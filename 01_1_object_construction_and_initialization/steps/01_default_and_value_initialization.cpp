#include <cassert>

struct Point {
    int x;
    int y;
};

class Counter {
public:
    Counter()
        : value_(10) {
    }

    int value() const {
        return value_;
    }

private:
    int value_;
};

int main() {
    [[maybe_unused]] int indeterminate;
    int zero{};
    Point origin{};

    Counter first;
    Counter second{};

    assert(zero == 0);
    assert(origin.x == 0 && origin.y == 0);
    assert(first.value() == 10);
    assert(second.value() == 10);

    // Читать indeterminate до присваивания нельзя.
}
