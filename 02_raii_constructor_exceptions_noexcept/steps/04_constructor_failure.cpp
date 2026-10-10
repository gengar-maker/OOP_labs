#include <cassert>
#include <iostream>
#include <stdexcept>

class TraceMember {
public:
    TraceMember(const char* name, bool must_fail)
        : name_(name) {
        std::cout << "start: " << name_ << '\n';

        if (must_fail) {
            throw std::runtime_error("member construction failed");
        }

        std::cout << "complete: " << name_ << '\n';
    }

    ~TraceMember() noexcept {
        ++destroyed_count_;
        std::cout << "destroy: " << name_ << '\n';
    }

    static void reset() noexcept {
        destroyed_count_ = 0;
    }

    static int destroyed_count() noexcept {
        return destroyed_count_;
    }

private:
    const char* name_;
    inline static int destroyed_count_ = 0;
};

class MemberFailureDevice {
public:
    MemberFailureDevice()
        : first_("first", false),
          second_("second", true) {
    }

    ~MemberFailureDevice() noexcept {
        ++device_destructor_calls_;
    }

    static int destructor_calls() noexcept {
        return device_destructor_calls_;
    }

private:
    TraceMember first_;
    TraceMember second_;
    inline static int device_destructor_calls_ = 0;
};

class BodyFailureDevice {
public:
    BodyFailureDevice()
        : first_("first", false),
          second_("second", false) {
        throw std::runtime_error("constructor body failed");
    }

    ~BodyFailureDevice() noexcept {
        ++device_destructor_calls_;
    }

    static int destructor_calls() noexcept {
        return device_destructor_calls_;
    }

private:
    TraceMember first_;
    TraceMember second_;
    inline static int device_destructor_calls_ = 0;
};

int main() {
    TraceMember::reset();

    try {
        MemberFailureDevice device;
    } catch (const std::exception& error) {
        std::cout << "caught: " << error.what() << '\n';
    }

    assert(TraceMember::destroyed_count() == 1);
    assert(MemberFailureDevice::destructor_calls() == 0);

    TraceMember::reset();

    try {
        BodyFailureDevice device;
    } catch (const std::exception& error) {
        std::cout << "caught: " << error.what() << '\n';
    }

    assert(TraceMember::destroyed_count() == 2);
    assert(BodyFailureDevice::destructor_calls() == 0);
}
