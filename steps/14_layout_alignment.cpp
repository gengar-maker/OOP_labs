#include <cstddef>
#include <iostream>

struct LayoutA {
    char flag;
    int value;
    char state;
};

struct LayoutB {
    int value;
    char flag;
    char state;
};

struct alignas(16) AlignedPoint {
    int x;
    int y;
};

int main() {
    std::cout << "LayoutA: sizeof=" << sizeof(LayoutA)
              << ", alignof=" << alignof(LayoutA) << '\n';
    std::cout << "  flag=" << offsetof(LayoutA, flag)
              << ", value=" << offsetof(LayoutA, value)
              << ", state=" << offsetof(LayoutA, state) << '\n';

    std::cout << "LayoutB: sizeof=" << sizeof(LayoutB)
              << ", alignof=" << alignof(LayoutB) << '\n';
    std::cout << "  value=" << offsetof(LayoutB, value)
              << ", flag=" << offsetof(LayoutB, flag)
              << ", state=" << offsetof(LayoutB, state) << '\n';

    std::cout << "AlignedPoint: sizeof=" << sizeof(AlignedPoint)
              << ", alignof=" << alignof(AlignedPoint) << '\n';
}
