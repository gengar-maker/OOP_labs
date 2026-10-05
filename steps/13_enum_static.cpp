#include <cassert>
#include <iostream>

struct Position {
    int x = 0;
    int y = 0;
};

class Robot {
public:
    enum class Direction {
        left,
        right,
        up,
        down
    };

    explicit Robot(const char* name)
        : name_(name == nullptr ? "Unknown" : name) {
    }

    bool move(Direction direction) {
        if (energy_ < movement_cost) {
            return false;
        }

        switch (direction) {
        case Direction::left:
            --position_.x;
            break;
        case Direction::right:
            ++position_.x;
            break;
        case Direction::up:
            ++position_.y;
            break;
        case Direction::down:
            --position_.y;
            break;
        }

        energy_ -= movement_cost;
        ++successful_moves_;
        return true;
    }

    const Position& position() const {
        return position_;
    }

    static int successfulMoves() {
        return successful_moves_;
    }

    void print() const {
        std::cout << name_ << ": (" << position_.x << ", " << position_.y << ")\n";
    }

private:
    static constexpr int movement_cost = 10;
    static int successful_moves_;

    const char* name_;
    Position position_;
    int energy_ = 100;
};

// Для static-поля без inline требуется ровно одно определение в .cpp.
// Ключевое слово static здесь повторять не нужно.
int Robot::successful_moves_ = 0;

int main() {
    Robot first("Atlas");
    Robot second("Rover");

    assert(first.move(Robot::Direction::right));
    assert(second.move(Robot::Direction::up));
    assert(Robot::successfulMoves() == 2);

    first.print();
    second.print();
}
