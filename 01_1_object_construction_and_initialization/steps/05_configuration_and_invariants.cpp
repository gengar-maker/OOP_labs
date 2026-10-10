#include <cassert>

struct DeviceConfig {
    const char* name = "Unknown";
    int volume = 50;
    bool enabled = true;
};

class Device {
public:
    explicit Device(DeviceConfig config)
        : name_(config.name != nullptr ? config.name : "Unknown"),
          volume_(normalizeVolume(config.volume)),
          enabled_(config.enabled) {
    }

    const char* name() const {
        return name_;
    }

    int volume() const {
        return volume_;
    }

    bool enabled() const {
        return enabled_;
    }

private:
    static int normalizeVolume(int value) {
        if (value < 0) {
            return 0;
        }
        if (value > 100) {
            return 100;
        }
        return value;
    }

    const char* name_;
    int volume_;
    bool enabled_;
};

int main() {
    DeviceConfig config{
        .name = "Speaker",
        .volume = 150
    };

    Device device{config};

    assert(device.name() != nullptr);
    assert(device.name()[0] == 'S');
    assert(device.volume() == 100);
    assert(device.enabled());

    config.volume = 20; // Меняется уже существующий config, не device.
    assert(device.volume() == 100);
}
