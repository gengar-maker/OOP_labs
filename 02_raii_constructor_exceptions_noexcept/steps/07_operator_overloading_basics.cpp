#include <cassert>
#include <iostream>

class Counter {
public:
    explicit Counter(int value = 0) noexcept
        : value_(value) {
    }

    int value() const noexcept {
        return value_;
    }

    Counter& operator+=(int delta) noexcept {
        value_ += delta;
        return *this;
    }

    Counter operator-() const noexcept {
        return Counter(-value_);
    }

    Counter& operator++() noexcept {
        ++value_;
        return *this;
    }

    Counter operator++(int) noexcept {
        Counter old_value(*this);
        ++(*this);
        return old_value;
    }

private:
    int value_;
};

Counter operator+(Counter left, int delta) noexcept {
    left += delta;
    return left;
}

Counter operator+(int delta, Counter right) noexcept {
    right += delta;
    return right;
}

bool operator==(const Counter& left, const Counter& right) noexcept {
    return left.value() == right.value();
}

bool operator!=(const Counter& left, const Counter& right) noexcept {
    return !(left == right);
}

std::ostream& operator<<(std::ostream& output, const Counter& counter) {
    return output << counter.value();
}

class LinearFunction {
public:
    LinearFunction(double coefficient, double offset) noexcept
        : coefficient_(coefficient), offset_(offset) {
    }

    double operator()(double x) const noexcept {
        return coefficient_ * x + offset_;
    }

private:
    double coefficient_;
    double offset_;
};

int main() {
    Counter counter(5);

    Counter& same_object = (counter += 3);
    assert(&same_object == &counter);
    assert(counter.value() == 8);

    Counter sum = counter + 2;
    assert(counter.value() == 8);
    assert(sum.value() == 10);

    Counter reversed_sum = 2 + counter;
    assert(reversed_sum.value() == 10);

    Counter negative = -counter;
    assert(counter.value() == 8);
    assert(negative.value() == -8);

    Counter before_increment = counter++;
    assert(before_increment.value() == 8);
    assert(counter.value() == 9);

    Counter& after_increment = ++counter;
    assert(&after_increment == &counter);
    assert(counter == Counter(10));
    assert(counter != sum + 1);

    LinearFunction line(2.0, 3.0);
    assert(line(5.0) == 13.0);

    std::cout << "counter = " << counter << '\n';
}
