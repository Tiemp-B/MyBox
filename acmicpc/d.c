#include <time.h>
#include <stdio.h>

int main() {
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);

    // Add 9 hours to convert UTC to KST
    t->tm_hour += 9;

    // Adjust for overflow in hour
    if (t->tm_hour >= 24) {
        t->tm_hour -= 24;
        t->tm_mday += 1; // Increment the day

        // Adjust for month and year if necessary
        if (t->tm_mday > 31 || // Maximum day may vary depending on the month
            (t->tm_mon == 3 && t->tm_mday > 30) || // April has 30 days
            (t->tm_mon == 5 && t->tm_mday > 30) || // June has 30 days
            (t->tm_mon == 8 && t->tm_mday > 30) || // September has 30 days
            (t->tm_mon == 10 && t->tm_mday > 30)) { // November has 30 days
            t->tm_mday = 1;
            t->tm_mon += 1; // Increment the month

            if (t->tm_mon >= 12) { // Adjust for year overflow
                t->tm_mon = 0;
                t->tm_year += 1;
            }
        } else if (t->tm_mon == 1 && t->tm_mday > 28) { // Special case: February
            int is_leap = (t->tm_year + 1900) % 4 == 0 && 
                          ((t->tm_year + 1900) % 100 != 0 || (t->tm_year + 1900) % 400 == 0);
            if (t->tm_mday > (is_leap ? 29 : 28)) {
                t->tm_mday = 1;
                t->tm_mon += 1;
            }
        }
    }

    printf("%4d-%02d-%02d",
           t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
           t->tm_hour, t->tm_min, t->tm_sec);

    return 0;
}
