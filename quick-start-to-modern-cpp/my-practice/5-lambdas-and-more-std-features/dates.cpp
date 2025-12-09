#include <chrono>
#include <iostream>

// C H R O N O  D A T E S
/*
This library allows you to work with dates, calendar types, and time zones.
*/

using namespace std::chrono_literals;

int main() {
    // can create variables representing units of time
    auto half_day = std::chrono::hours(12);
    auto minutes = std::chrono::minutes(60);
    auto seconds = std::chrono::seconds(30);
    auto milliseconds = std::chrono::milliseconds(500);
    auto microseconds = std::chrono::microseconds(500);
    auto nanoseconds = std::chrono::nanoseconds(500);

    // using the chrono_literals!
    // format: year / month / date
    auto d1 = 2025y / 10 / 9;
    auto d2 = 2025y / std::chrono::December / 9;
    // format: day / month / year
    auto d3 = 9d / 10 / 2025;
    auto d4 = 9d / std::chrono::December / 2025;
    // format: month / day / year
    auto d5 = 12 / 9d / 2025;
    auto d6 = std::chrono::December / 9 / 2025;

    // timezones
    auto time = std::chrono::zoned_time{std::chrono::current_zone(), std::chrono::system_clock::now()};
    std::cout << time << std::endl;

    auto time2 = std::chrono::zoned_time{std::chrono::locate_zone("Asia/Tokyo"), std::chrono::system_clock::now()};
    std::cout << time2 << std::endl;

    return 0;
}
