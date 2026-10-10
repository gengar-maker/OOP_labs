#include <cassert>
#include <cstddef>
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

    int& at(int index) {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("index is out of range");
        }
        return data_[index];
    }

private:
    int size_;
    int* data_;
};

int main() {
    IntArray empty;
    assert(empty.empty());

    IntArray values(3);
    values.at(1) = 42;

    assert(values.size() == 3);
    assert(values.at(1) == 42);

    try {
        IntArray invalid(-1);
        assert(false);
    } catch (const std::invalid_argument&) {
        // Недостроенный объект invalid не появляется.
    }
}
