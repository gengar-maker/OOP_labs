#include <iostream>

class IntArray {
public:
    IntArray() noexcept;
    explicit IntArray(int size);
    ~IntArray() noexcept;

    IntArray(const IntArray&) = delete;
    IntArray& operator=(const IntArray&) = delete;

    int size() const noexcept;
    bool empty() const noexcept;
    explicit operator bool() const noexcept;

    int& operator[](int index) noexcept;
    const int& operator[](int index) const noexcept;

    int& at(int index);
    const int& at(int index) const;

    void fill(int value) noexcept;
    void clear() noexcept;
    void resize(int new_size);

private:
    void validate_index(int index) const;

    int size_;
    int* data_;
};

bool operator==(const IntArray& left, const IntArray& right) noexcept;
bool operator!=(const IntArray& left, const IntArray& right) noexcept;
std::ostream& operator<<(std::ostream& output, const IntArray& array);

// TODO: разместите определения методов и свободных операторов здесь.
// Выполняйте работу по этапам из основного документа лабораторной.

int main() {
    std::cout
        << "Implement IntArray, then replace this message with the required tests.\n";
}
