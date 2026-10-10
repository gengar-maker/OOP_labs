#include <cassert>
#include <cstddef>
#include <stdexcept>

void safe_operation() noexcept {
}

void risky_operation() {
}

class Buffer {
public:
    Buffer() noexcept
        : size_(0), data_(nullptr) {
    }

    explicit Buffer(int size)
        : size_(size), data_(nullptr) {
        if (size_ < 0) {
            throw std::invalid_argument("size must not be negative");
        }

        if (size_ > 0) {
            data_ = new int[static_cast<std::size_t>(size_)]{};
        }
    }

    ~Buffer() noexcept {
        delete[] data_;
    }

    Buffer(const Buffer&) = delete;
    Buffer& operator=(const Buffer&) = delete;

    int size() const noexcept {
        return size_;
    }

    void clear() noexcept {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
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

static_assert(noexcept(safe_operation()));
static_assert(!noexcept(risky_operation()));
static_assert(noexcept(Buffer{}));

int main() {
    Buffer values(2);
    assert(values.size() == 2);

    static_assert(noexcept(values.size()));
    static_assert(noexcept(values.clear()));
    static_assert(!noexcept(values.at(0)));

    values.clear();
    assert(values.size() == 0);
}
