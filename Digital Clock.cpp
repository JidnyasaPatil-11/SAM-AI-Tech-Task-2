#include <iostream>
#include <iomanip>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

int main() {

    cout << "\n";
    cout << "============================================\n";
    cout << "              DIGITAL CLOCK\n";
    cout << "============================================\n";
    cout << "        Indian Standard Time (IST)\n";
    cout << "        Real-Time System Clock\n";
    cout << "        Updates Every Second\n";
    cout << "        Press Ctrl + C to Exit\n";
    cout << "--------------------------------------------\n\n";

    const char* days[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };

    while (true) {

        // Get current UTC time
        time_t currentTime = time(nullptr);

        // Convert UTC time to IST (UTC + 5 hours 30 minutes)
        currentTime += 5 * 3600 + 30 * 60;

        // Convert adjusted time to UTC structure
        tm* istTime = gmtime(&currentTime);

        // Move cursor to the beginning of the clock line
        cout << "\r";

        // Display day and date
        cout << "   "
             << days[istTime->tm_wday]
             << "  |  "
             << setfill('0') << setw(2) << istTime->tm_mday
             << "/"
             << setw(2) << istTime->tm_mon + 1
             << "/"
             << istTime->tm_year + 1900;

        // Display IST time
        cout << "   |   IST: "
             << setfill('0')
             << setw(2) << istTime->tm_hour << ":"
             << setw(2) << istTime->tm_min << ":"
             << setw(2) << istTime->tm_sec
             << "     "
             << flush;

        // Update every second
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}