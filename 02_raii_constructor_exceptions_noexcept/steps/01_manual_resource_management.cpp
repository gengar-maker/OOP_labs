#include <iostream>

void process_manually(bool stop_early) {
    int* data = new int[3]{10, 20, 30};

    std::cout << "resource acquired\n";

    if (stop_early) {
        // Если забыть эту строку, ранний выход приведёт к утечке.
        delete[] data;
        std::cout << "resource released before early return\n";
        return;
    }

    std::cout << "first value: " << data[0] << '\n';
    delete[] data;
    std::cout << "resource released at normal exit\n";
}

int main() {
    process_manually(false);
    process_manually(true);
}
