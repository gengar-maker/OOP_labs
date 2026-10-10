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

struct Entity {
    Point position;
    bool active = true;
};

int main() {
    int initial_x = 5;
    Point designated{
        .x = initial_x,
        .y = 6
    };

    WindowSettings defaults{};
    WindowSettings custom{
        .width = 1280,
        .height = 720,
        .fullscreen = true
    };
    WindowSettings partial{.height = 900};
    Entity entity{
        .position = Point{10, 20},
        .active = false
    };

    // Point wrong_order{.y = 2, .x = 1}; // Ошибка: порядок фиксирован.
    // Point mixed{1, .y = 2};             // Ошибка: формы нельзя смешивать.

    assert(designated.x == 5 && designated.y == 6);
    assert(defaults.width == 800 && defaults.height == 600);
    assert(custom.width == 1280 && custom.height == 720 && custom.fullscreen);
    assert(partial.width == 800 && partial.height == 900 && !partial.fullscreen);
    assert(entity.position.x == 10 && entity.position.y == 20 && !entity.active);
}
