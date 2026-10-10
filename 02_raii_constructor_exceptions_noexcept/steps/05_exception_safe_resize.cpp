#include <cassert>
#include <cstddef>
#include <stdexcept>

class PairState {
public:
    PairState(int first, int second) noexcept
        : first_(first), second_(second) {
    }

    int first() const noexcept {
        return first_;
    }

    int second() const noexcept {
        return second_;
    }

    void update_with_basic_guarantee(
        int new_first,
        int new_second,
        bool fail_after_first
    ) {
        first_ = new_first;

        if (fail_after_first) {
            throw std::runtime_error("failure after the first change");
        }

        second_ = new_second;
    }

    void update_with_strong_guarantee(
        int new_first,
        int new_second,
        bool must_fail
    ) {
        // Все потенциально опасные действия выполняются до изменения объекта.
        if (must_fail) {
            throw std::runtime_error("failure before commit");
        }

        // Присваивание int не выбрасывает: это короткая стадия фиксации.
        first_ = new_first;
        second_ = new_second;
    }

    void reset() noexcept {
        first_ = 0;
        second_ = 0;
    }

private:
    int first_;
    int second_;
};

class IntBuffer {
public:
    explicit IntBuffer(int size)
        : size_(size), data_(nullptr) {
        if (size_ < 0) {
            throw std::invalid_argument("size must not be negative");
        }

        if (size_ > 0) {
            data_ = new int[static_cast<std::size_t>(size_)]{};
        }
    }

    ~IntBuffer() noexcept {
        delete[] data_;
    }

    IntBuffer(const IntBuffer&) = delete;
    IntBuffer& operator=(const IntBuffer&) = delete;

    int size() const noexcept {
        return size_;
    }

    int& operator[](int index) noexcept {
        return data_[index];
    }

    const int& operator[](int index) const noexcept {
        return data_[index];
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
    int size_;
    int* data_;
};

int main() {
    PairState basic(10, 20);

    try {
        basic.update_with_basic_guarantee(100, 200, true);
        assert(false);
    } catch (const std::runtime_error&) {
        // Объект корректен, но первая часть изменения уже произошла.
    }

    assert(basic.first() == 100);
    assert(basic.second() == 20);

    PairState strong(10, 20);

    try {
        strong.update_with_strong_guarantee(100, 200, true);
        assert(false);
    } catch (const std::runtime_error&) {
        // Ошибка произошла до фиксации: состояние полностью прежнее.
    }

    assert(strong.first() == 10);
    assert(strong.second() == 20);

    strong.update_with_strong_guarantee(100, 200, false);
    assert(strong.first() == 100);
    assert(strong.second() == 200);

    strong.reset();
    assert(strong.first() == 0 && strong.second() == 0);

    IntBuffer values(3);
    values[0] = 10;
    values[1] = 20;
    values[2] = 30;

    values.resize(5);
    assert(values.size() == 5);
    assert(values[0] == 10 && values[1] == 20 && values[2] == 30);
    assert(values[3] == 0 && values[4] == 0);

    try {
        values.resize(-1);
        assert(false);
    } catch (const std::invalid_argument&) {
        // Проверка выполнена до изменения объекта.
    }

    assert(values.size() == 5);
    assert(values[0] == 10 && values[1] == 20 && values[2] == 30);

    values.resize(2);
    assert(values.size() == 2);
    assert(values[0] == 10 && values[1] == 20);
}
