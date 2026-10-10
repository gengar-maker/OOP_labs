#include <cassert>
#include <iostream>
#include <stdexcept>

class ScopeMarker {
public:
    explicit ScopeMarker(const char* name)
        : name_(name) {
        std::cout << "enter: " << name_ << '\n';
    }

    ~ScopeMarker() noexcept {
        ++destroyed_count_;
        std::cout << "leave: " << name_ << '\n';
    }

    static int destroyed_count() noexcept {
        return destroyed_count_;
    }

private:
    const char* name_;
    inline static int destroyed_count_ = 0;
};

void inner() {
    ScopeMarker inner_marker("inner");
    throw std::runtime_error("failure in inner");
}

void outer() {
    ScopeMarker outer_marker("outer");
    inner();
}

int main() {
    try {
        outer();
    } catch (const std::exception& error) {
        std::cout << "caught: " << error.what() << '\n';
    }

    assert(ScopeMarker::destroyed_count() == 2);
}
