#include <cassert>
#include <iostream>
#include <stdexcept>

class SmallArray {
public:
    explicit SmallArray(int size)
        : size_(size) {
        if (size_ < 0 || size_ > capacity_) {
            throw std::invalid_argument("size must be from 0 to 3");
        }
    }

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

private:
    void validate_index(int index) const {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("index is out of range");
        }
    }

    inline static constexpr int capacity_ = 3;
    int size_;
    int data_[capacity_]{};
};

bool operator==(const SmallArray& left, const SmallArray& right) noexcept {
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

bool operator!=(const SmallArray& left, const SmallArray& right) noexcept {
    return !(left == right);
}

std::ostream& operator<<(std::ostream& output, const SmallArray& array) {
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
    SmallArray values(3);
    values[0] = 10;
    values.at(1) = 20;
    values[2] = 30;

    const SmallArray& read_only = values;
    assert(read_only[0] == 10);
    assert(read_only.at(1) == 20);

    SmallArray same(3);
    same[0] = 10;
    same[1] = 20;
    same[2] = 30;

    assert(values == same);
    assert(values);
    std::cout << values << '\n';

    try {
        values.at(3) = 40;
        assert(false);
    } catch (const std::out_of_range&) {
        assert(values == same);
    }
}
