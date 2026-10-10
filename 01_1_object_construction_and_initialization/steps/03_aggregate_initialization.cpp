#include <cassert>

struct Point {
    int x;
    int y;
};

struct WindowSettings {
    int width = 800;
    int height = 600;
    bool fullscreen = false;
};

class MixedAccess {
public:
    int public_value;

    int private_value() const {
        return private_value_;
    }

private:
    int private_value_;
};

class ConfiguredExample {
public:
    ConfiguredExample(int public_value, int private_value)
        : public_value(public_value),
          private_value_(private_value) {}

    int private_value() const {
        return private_value_;
    }

    int public_value;

private:
    int private_value_;
};

int main() {
    Point origin{};
    Point with_braces{10, 20};
    Point with_parentheses(30, 40); // Инициализация агрегата через () — C++20.

    WindowSettings defaults{};
    WindowSettings positional{1280, 720, true};
    WindowSettings partial{1024};

    // MixedAccess не является агрегатом из-за приватного поля.
    MixedAccess empty_mixed{}; // Вызывается неявный конструктор без аргументов.

    // MixedAccess values{10, 20};
    // Ошибка: значения не передаются полям неагрегатного типа.

    // MixedAccess named{.public_value = 10};
    // Ошибка: инициализация по именам полей разрешена только для агрегатов.

    ConfiguredExample configured{10, 20}; // Вызывается конструктор.

    assert(origin.x == 0 && origin.y == 0);
    assert(with_braces.x == 10 && with_braces.y == 20);
    assert(with_parentheses.x == 30 && with_parentheses.y == 40);
    assert(defaults.width == 800 && defaults.height == 600 && !defaults.fullscreen);
    assert(positional.width == 1280 && positional.height == 720 && positional.fullscreen);
    assert(partial.width == 1024 && partial.height == 600 && !partial.fullscreen);
    assert(empty_mixed.public_value == 0);
    assert(empty_mixed.private_value() == 0);
    assert(configured.public_value == 10);
    assert(configured.private_value() == 20);

    // Point narrowing{1.5, 2}; // Ошибка: сужающее преобразование.
}
