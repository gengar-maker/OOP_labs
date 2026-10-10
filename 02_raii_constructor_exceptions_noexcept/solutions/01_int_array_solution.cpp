#include <cassert>
#include <cstddef>
#include <iostream>
#include <stdexcept>

class IntArray {
public:
    IntArray() noexcept
        : size_(0), data_(nullptr) {
    }

    explicit IntArray(int size)
        : size_(size), data_(nullptr) {
        if (size_ < 0) {
            throw std::invalid_argument("size must not be negative");
        }

        if (size_ > 0) {
            data_ = new int[static_cast<std::size_t>(size_)]{};
        }
    }

    ~IntArray() noexcept {
        delete[] data_;
    }

    IntArray(const IntArray&) = delete;
    IntArray& operator=(const IntArray&) = delete;

    int size() const noexcept {
        return size_;
    }

    bool empty() const noexcept {
        return size_ == 0;
    }

    explicit operator bool() const noexcept {
        return !empty();
    }

    int& operator[](int index) noexcept {
        return data_[index];
    }

    const int& operator[](int index) const noexcept {
        return data_[index];
    }

    int& at(int index) {
        validate_index(index);
        return data_[index];
    }

    const int& at(int index) const {
        validate_index(index);
        return data_[index];
    }

    void fill(int value) noexcept {
        for (int index = 0; index < size_; ++index) {
            data_[index] = value;
        }
    }

    void clear() noexcept {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
    }

    void resize(int new_size) {
        if (new_size < 0) {
            throw std::invalid_argument("size must not be negative");
        }

        if (new_size == size_) {
            return;
        }

        int* new_data = new_size > 0
            ? new int[static_cast<std::size_t>(new_size)]{}
            : nullptr;

        const int elements_to_copy = new_size < size_ ? new_size : size_;
        for (int index = 0; index < elements_to_copy; ++index) {
            new_data[index] = data_[index];
        }

        delete[] data_;
        data_ = new_data;
        size_ = new_size;
    }

private:
    void validate_index(int index) const {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("index is out of range");
        }
    }

    int size_;
    int* data_;
};

bool operator==(const IntArray& left, const IntArray& right) noexcept {
    if (left.size() != right.size()) {
        return false;
    }

    for (int index = 0; index < left.size(); ++index) {
        if (left[index] != right[index]) {
            return false;
        }
    }

    return true;
}

bool operator!=(const IntArray& left, const IntArray& right) noexcept {
    return !(left == right);
}

std::ostream& operator<<(std::ostream& output, const IntArray& array) {
    output << '[';

    for (int index = 0; index < array.size(); ++index) {
        if (index > 0) {
            output << ", ";
        }
        output << array[index];
    }

    return output << ']';
}

int main() {
    static_assert(noexcept(IntArray{}));

    IntArray numbers(3);
    numbers.fill(7);
    numbers.at(1) = 42;

    assert(numbers.size() == 3);
    assert(numbers[0] == 7 && numbers[1] == 42 && numbers[2] == 7);

    const IntArray& read_only = numbers;
    assert(read_only[1] == 42);
    assert(read_only.at(2) == 7);

    try {
        numbers.at(10) = 100;
        assert(false);
    } catch (const std::out_of_range&) {
        assert(numbers[0] == 7 && numbers[1] == 42 && numbers[2] == 7);
    }

    IntArray same(3);
    same[0] = 7;
    same[1] = 42;
    same[2] = 7;
    assert(numbers == same);

    numbers.resize(5);
    assert(numbers.size() == 5);
    assert(numbers[0] == 7 && numbers[1] == 42 && numbers[2] == 7);
    assert(numbers[3] == 0 && numbers[4] == 0);

    numbers.resize(2);
    assert(numbers.size() == 2);
    assert(numbers[0] == 7 && numbers[1] == 42);
    assert(numbers != same);

    std::cout << "numbers = " << numbers << '\n';

    numbers.clear();
    numbers.clear();
    assert(numbers.empty());
    assert(!numbers);

    try {
        IntArray invalid(-5);
        assert(false);
    } catch (const std::invalid_argument&) {
        // Некорректный объект не был создан.
    }
}
