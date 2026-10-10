#include <cassert>

struct DeviceProfile {
    const char* name = "Unknown";
    int retries = 3;
    int timeoutSeconds = 30;
    bool loggingEnabled = false;
};

int main() {
    DeviceProfile defaultProfile{};

    DeviceProfile testProfile{
        .name = "Test",
        .retries = 5,
        .timeoutSeconds = 10,
        .loggingEnabled = true
    };

    DeviceProfile patientProfile{
        .name = "Patient",
        .timeoutSeconds = 120
    };

    assert(defaultProfile.name != nullptr);
    assert(defaultProfile.name[0] == 'U');
    assert(defaultProfile.retries == 3);
    assert(defaultProfile.timeoutSeconds == 30);
    assert(!defaultProfile.loggingEnabled);

    assert(testProfile.name != nullptr);
    assert(testProfile.name[0] == 'T');
    assert(testProfile.retries == 5);
    assert(testProfile.timeoutSeconds == 10);
    assert(testProfile.loggingEnabled);

    assert(patientProfile.retries == 3);
    assert(patientProfile.timeoutSeconds == 120);
    assert(!patientProfile.loggingEnabled);
}
