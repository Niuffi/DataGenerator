#include "Date.h"
#include <random>

//-----------------------------------------------------------------
//Default constructor
Date::Date(int day, int month, int year) {
    if (dateValidation(day,month,year)) {
        this->year = year;
        this->month = month;
        this->day = day;
    } else {
        throw "Invalid date!"; //TODO
    }
}

//-----------------------------------------------------------------

Date::Date(int dayOfYear, int year) {
    int day = dayOfYear;
    int month = 1;
    if (isLoop(year)){
        if(day <= 365) {
            for (int i = 1; day > daysInMonthLoop[i]; i++) {
                day -= daysInMonthLoop[i];
                month++;
            }
            this->year = year;
            this->month = month;
            this->day = day;
        } else {
            throw "Invalid date!"; //TODO
        }
    } else {
        if (day <= 365) {
            for (int i = 1; day > daysInMonth[i]; i++) {
                day -= daysInMonth[i];
                month++;
            }
            this->year = year;
            this->month = month;
            this->day = day;
        } else {
            throw "Invalid date!"; //TODO
        }
    }
}

//-----------------------------------------------------------------

Date::Date (int sDay, int sMonth, int sYear, int eDay, int eMonth, int eYear) {
    if (dateValidation(sDay,sMonth,sYear) && dateValidation(eDay,eMonth,eYear)) {
        std::default_random_engine gen(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> randomYear(sYear,eYear);

        int dayInYear;
        int year = randomYear(gen);

        if (isLoop(year)) {
            std::uniform_int_distribution<int> randomDayInYear(1,366);
            dayInYear = randomDayInYear(gen);
            new (this) Date(dayInYear,year);
        } else {
            std::uniform_int_distribution<int> randomDayInYear(1,365);
            dayInYear = randomDayInYear(gen);
            new (this) Date(dayInYear,year);
        }
    } else {
        throw "Invalid date!"; //TODO
    }
}

//-----------------------------------------------------------------

std::string Date::dateString() const {
    return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}

//-----------------------------------------------------------------

bool Date::isLoop(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    } else {
        return false;
    }
}

//-----------------------------------------------------------------

bool Date::dateValidation(int day, int month, int year) {
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day >= 1 && day <= 31) {
        return true;
    } else if (month == 4 || month == 6 || month == 9|| month == 11 && day >= 1 && day <= 30) {
        return true;
    } else if (month == 2) {
        if (isLoop(year) && day >= 1 && day <= 29) {
            return true;
        } else if (day >= 1 && day <= 28) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

//-----------------------------------------------------------------

int Date::lastDayOfMonth(int month, int year) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        return 31;
    } else if (month == 4 || month == 6 || month == 9|| month == 11) {
        return 30;
    } else if (isLoop(year) && month == 2) {
        return 29;
    } else {
        return 28;
    }
}

//-----------------------------------------------------------------

int Date::dayOfYear(Date date) {
    if(isLoop(date.year)) {
        int days = 0;
        for(int i = 1; i < date.month; i++) {
            days += daysInMonthLoop[i-1];
        }
        return days + date.day;
    } else {
        int days = 0;
        for(int i = 1; i < date.month; i++) {
            days += daysInMonth[i-1];
        }
        return days + date.day;
    }
}

//-----------------------------------------------------------------

bool Date::operator > (Date const &date) const {
    if (this->year * 10000 + this->month * 100 + day > date.year * 10000 + date.month * 100 + day) {
        return true;
    } else {
        return false;
    }
}

//-----------------------------------------------------------------

bool Date::operator < (Date const &date) const {
    if (this->year * 10000 + this->month * 100 + day < date.year * 10000 + date.month * 100 + day) {
        return true;
    } else {
        return false;
    }
}

//-----------------------------------------------------------------

bool Date::operator == (Date const &date) const {
    if (this->year * 10000 + this->month * 100 + day == date.year * 10000 + date.month * 100 + day) {
        return true;
    } else {
        return false;
    }
}

//-----------------------------------------------------------------
