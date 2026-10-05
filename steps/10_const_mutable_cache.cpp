#include <cassert>
#include <iostream>

class Sensor {
public:
    explicit Sensor(int value)
        : raw_value_(value) {
    }

    void setRawValue(int value) {
        raw_value_ = value;
        cache_valid_ = false;
    }

    int level() const {
        if (!cache_valid_) {
            cached_level_ = normalize(raw_value_);
            cache_valid_ = true;
            ++computation_count_;
        }

        return cached_level_;
    }

    unsigned int computationCount() const {
        return computation_count_;
    }

private:
    static int normalize(int value) {
        if (value < 0) {
            return 0;
        }
        if (value > 100) {
            return 100;
        }
        return value;
    }

    int raw_value_;
    mutable bool cache_valid_ = false;
    mutable int cached_level_ = 0;
    mutable unsigned int computation_count_ = 0;
};

int main() {
    Sensor sensor(120);
    const Sensor& view = sensor;

    assert(view.level() == 100);
    assert(view.level() == 100);
    assert(view.computationCount() == 1);

    sensor.setRawValue(40);
    assert(view.level() == 40);
    assert(view.computationCount() == 2);

    std::cout << "computed " << view.computationCount() << " times\n";
}
