#include <cassert>

// Задание:
// 1. Добавьте поля name, retries, timeoutSeconds и loggingEnabled.
// 2. Задайте разумные значения по умолчанию.
// 3. Создайте defaultProfile через {}.
// 4. Создайте testProfile через designated initializers.
// 5. Проверьте значения через assert.
struct DeviceProfile {
    const char* name = "Unknown";
    int retries = 3;
    int timeoutSeconds = 30;
    bool loggingEnabled = false;
};

int main() {
    DeviceProfile defaultProfile{};

    // Замените позиционную форму на designated initialization.
    DeviceProfile testProfile{"Test", 5, 10, true};

    assert(defaultProfile.retries == 3);
    assert(testProfile.timeoutSeconds == 10);
}
