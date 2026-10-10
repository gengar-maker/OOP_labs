#include <cassert>
#include <iostream>

enum class MeasurementKind {
    count,
    temperature,
    grade
};

union MeasurementStorage {
    int count;
    double temperature;
    char grade;

    constexpr MeasurementStorage()
        : count(0) {
    }
};

class Measurement {
public:
    static Measurement fromCount(int value) {
        Measurement result;
        result.kind_ = MeasurementKind::count;
        result.storage_.count = value;
        return result;
    }

    static Measurement fromTemperature(double value) {
        Measurement result;
        result.kind_ = MeasurementKind::temperature;
        result.storage_.temperature = value;
        return result;
    }

    static Measurement fromGrade(char value) {
        Measurement result;
        result.kind_ = MeasurementKind::grade;
        result.storage_.grade = value;
        return result;
    }

    MeasurementKind kind() const {
        return kind_;
    }

    void print() const {
        switch (kind_) {
        case MeasurementKind::count:
            std::cout << "count=" << storage_.count << '\n';
            break;
        case MeasurementKind::temperature:
            std::cout << "temperature=" << storage_.temperature << '\n';
            break;
        case MeasurementKind::grade:
            std::cout << "grade=" << storage_.grade << '\n';
            break;
        }
    }

private:
    Measurement() = default;

    MeasurementKind kind_ = MeasurementKind::count;
    MeasurementStorage storage_;
};

int main() {
    const Measurement count = Measurement::fromCount(42);
    const Measurement temperature = Measurement::fromTemperature(21.5);
    const Measurement grade = Measurement::fromGrade('A');

    assert(count.kind() == MeasurementKind::count);
    assert(temperature.kind() == MeasurementKind::temperature);
    assert(grade.kind() == MeasurementKind::grade);

    count.print();
    temperature.print();
    grade.print();

    std::cout << "storage size=" << sizeof(MeasurementStorage)
              << ", alignment=" << alignof(MeasurementStorage) << '\n';
}
