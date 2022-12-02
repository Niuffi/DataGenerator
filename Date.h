#include <iostream>

struct Date {
    int day;
    int month;
    int year;

    constexpr static int daysInMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    constexpr static int daysInMonthLoop[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};

    Date(int day, int month, int year);

    Date(int dayOfYear, int year);

    Date(int sDay, int sMonth, int sYear, int eDay, int eMonth, int eYear);

    std::string dateString() const;

    static bool isLoop(int year);

    static bool dateValidation(int day, int month, int year);

    static int lastDayOfMonth(int month, int year);

    static int dayOfYear(Date date);


    bool operator > (Date const &date) const;

    bool operator < (Date const &date) const;

    bool operator == (Date const &date) const;
};