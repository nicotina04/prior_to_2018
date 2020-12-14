#include <vector>
#include "myDate.h"

myDate::myDate(int year, int month, int day) {this->year = year; this->month = month; this->day = day;}
myDate::myDate(const myDate &date)
{
    int *ty = new int, *tm = new int, *td = new int;
    *ty = date.getYear(); *tm = date.getMonth(); *td = date.getDayOfMonth();
    this->year = *ty; this->month = *tm; this->day = *td;
    delete ty,tm,td;
}

void myDate::setDayOfMonth(int day) {this->day = day;}
void myDate::setMonth(int month) {this->month = month;}
void myDate::setYear(int year) {this->year = year;}
void myDate::setDate(int year, int month, int day) {this->year = year; this->month = month; this->day = day;}

int myDate::getDayOfMonth() const {return this->day;}
int myDate::getMonth() const {return this->month;}
int myDate::getYear() const {return this->year;}

bool myDate::isLeapYear() const {return !(this->year % 400) || (!(this->year % 4) && (this->year % 100));}

bool myDate::isLeapYear(int ye) const
{
    return !(ye % 400) || (!(ye % 4) && (ye % 100));
}

int myDate::getDayOfWeek() const
{
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum(5);

    for (int i = 1582; i < year; ++i)
    {
        if (isLeapYear(i)) {sum += 366;}
        else {sum += 365;}
    }

    for (int j = 1; j < month; ++j)
    {
        if(j == 1)
        {
            if(isLeapYear()) {months[j] = 29;}
            else {months[j] = 28;}
        }
        sum += months[j];
    }
    sum += this->day - 1; sum %= 7;

    return sum;
}

int myDate::getDayOfYear() const
{
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int summer(0);

    for (int i = 0; i < month - 1; ++i)
    {
        if(i == 1)
        {
            if(isLeapYear()) {months[1] = 29;}
            else {months[1] = 28;}
        }
        summer += months[i];
    }

    return summer + this->day;
}

int myDate::getNumHolidays() const
{
    int dayz(0); int holis(0); int holisum(0);
    int months[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    myDate boostfuel(this->getYear(), 1, 1);

    dayz = boostfuel.getDayOfWeek() - 1;

    for (int j = 1; j <= 12; ++j)
    {
        if (isLeapYear()) {months[1] = 29;}
        for (int k = 1; k <= months[j - 1]; ++k)
        {
            ++dayz;
            if(dayz % 7 == 6 || dayz % 7 == 0) {++holis;}
            switch(j)
            {
                case 1: case 3:
                    if (k == 1){if (dayz % 7 != 6 && dayz % 7 != 0){++holisum;}}
                    break;
                case 2:
                    if (k == 1 || k == 2 || k == 3){if (dayz % 7 != 6 && dayz % 7 != 0){++holisum;}}
                    break;
                case 5:
                    if (k == 5|| k == 15){if (dayz % 7 != 6 && dayz  % 7 != 0){++holisum;}}
                    break;
                case 6:
                    if(k == 6){if (dayz % 7 != 6 && dayz % 7 != 0){++holisum;}}
                    break;
                case 7:
                    if (k == 17){if (dayz % 7 != 6 && dayz % 7 != 0){++holisum;}}
                    break;
                case 8:
                    if (k == 15){if (dayz % 7 != 6 && dayz % 7 != 0){++holisum;}}
                    break;
                case 9:
                    if (k == 15 || k == 16 || k == 17){if (dayz % 7 != 6 && dayz % 7 != 0){++holisum;}}
                    break;
                case 10:
                    if (k == 3){if (dayz % 7 != 6 && dayz % 7 != 0){++holisum;}}
                    break;
                case 12:
                    if (k == 25){if(dayz % 7 != 6 && dayz % 7 != 0){++holisum;}}
                    break;
                default: break;
            }
        }
    }

    int final(holisum + holis);
    return final;
}

int myDate::getNumSummerTimeDays() const
{
    int sumtimes;

    myDate __ = myDate();
    __.setYear(this->year); __.setMonth(3); __.setDayOfMonth(1);

    int summer_start(1 + (7 - __.getDayOfWeek()) % 7);
    int summer_final(summer_start);

    while(summer_final + 7 <= 31) {summer_final += 7;}

    __.setMonth(3); __.setDayOfMonth(summer_final);


    myDate _ = myDate();
    _.setYear(this->year); _.setMonth(10); _.setDayOfMonth(1);

    summer_start = 1 + (7 - _.getDayOfWeek()) % 7;
    summer_final = summer_start;

    while(summer_final + 7 <= 31) {summer_final += 7;}

    _.setMonth(10); _.setDayOfMonth(summer_final);

    sumtimes = _.getDayOfYear() - __.getDayOfYear();

    return sumtimes;
}

void myDate::printCalendarOfMonth() const
{
    cout.tie(NULL);
    int monthset[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    std::vector<int> v;
    std::vector<int>::iterator tv;

    unsigned int days(0);
    for(int x = 1582; x < this->year; ++x)
    {
        if(isLeapYear(x)) {days += 366;}
        else {days += 365;}
    }

    if(isLeapYear()) {monthset[1] = 29;}
    else {monthset[1] = 28;}

    if(this->month != 1)
    {
        for(int k = 0; k < this->month - 1; ++k){days += monthset[k];}
    }
    int checker(days%7);
    int starter;
    if(checker == 1){starter = 5;}else if(checker == 2){starter = 6;}else if(checker == 3){starter = 0;}else if(checker == 4){starter = 1;}else if(checker == 5){starter = 2;}else if(checker == 6){starter = 3;}else{starter = 4;}
    if(starter + 1 != 7)
    {
        for(int l = 0; l <= starter; ++l){v.push_back(0);}
    }
    for(int l = 1; l <= monthset[this->month - 1]; ++l){v.push_back(l);}
    if(v.size() > 28 && v.size() < 35)
    {
        while(v.size() != 35)
        {
            v.push_back(0);
        }
    }
    else if(v.size() > 35 && v.size() < 42)
    {
        while(v.size() != 42)
        {
            v.push_back(0);
        }
    }
    cout << this->year << " " << this->month << "\n";
    int col(0);
    for(tv = v.begin(); tv != v.end(); ++tv)
    {
        ++col;
        cout << *tv << " ";
        if(col % 7 == 0){cout << "\n";}
    }

}

ostream &operator<<(ostream &outStream, const myDate &date)
{
    int monthes(date.getDayOfMonth());
    int year(date.getYear());
    int month(date.getMonth());

    if(monthes <= 9) {outStream << "0" << monthes;}else {outStream << monthes;}
    outStream << "/";

    if(month <= 9) {outStream << "0" << month;}else {outStream << month;}
    outStream << "/";

    outStream << year;

    return outStream;
}

istream &operator>>(istream &inStream, myDate &date)
{
    int y; short m, d;
    inStream >> y >> m >> d;
    date.setDate(y, m, d);

    return inStream;
}

myDate operator+(int num, const myDate &date)
{
    int M[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(date.isLeapYear()) {M[1] = 29;}
    else {M[1] = 28;}

    int year(date.getYear()); int month(date.getMonth()); int day(date.getDayOfMonth());

    if(num >= 0)
    {
        while(num > 0)
        {
            ++day;
            if(day > M[month - 1])
            {
                ++month; day = 1;
            }
            if(month > 12)
            {
                ++year; month = 1; day = 1;
                if(date.isLeapYear(year)) {M[1] = 29;}
                else {M[1] = 28;}
            }
            --num;
        }
    }
    else
    {
        while(num < 0)
        {
            --day;
            if (day <= 0)
            {
                --month; day = M[month - 1];
            }
            if (month <= 0)
            {
                --year; month = 12; day = 31;
                if(date.isLeapYear(year)) {M[1] = 29;}
                else {M[1] = 28;}
            }
            if (year < 1582)
            {
                return myDate(1582, 1, 1);
            }
            ++num;
        }
    }

    return myDate(year, month, day);
}

int myDate::operator-(const myDate &date) const
{
    int seedy(this->getYear());
    int targety(date.getYear());
    int seed(0), target(0);

    for(int i = 1582; i < seedy; ++i)
    {
        if(this->isLeapYear(i)) {seed += 366;}
        else {seed += 365;}
    }
    seed += getDayOfYear();

    for(int i = 1582; i < targety; ++i)
    {
        if(date.isLeapYear(i)) {target += 366;}
        else {target += 365;}
    }
    target += date.getDayOfYear();

    return seed - target;
}

myDate myDate::operator+(int num) const
{
    int M[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(this->isLeapYear()) {M[1] = 29;}
    else {M[1] = 28;}

    int month(this->getMonth()); int day(this->getDayOfMonth());
    int seedy(this->getYear());


    if(num >= 0)
    {
        while(num > 0)
        {
            ++day;
            if(day > M[month - 1])
            {
                ++month; day = 1;
            }
            if(month > 12)
            {
                ++seedy; month = 1; day = 1;
                if(this->isLeapYear()) {M[1] = 29;}
                else {M[1] = 28;}
            }
            --num;
        }
    }
    else
    {
        while(num < 0)
        {
            --day;
            if (day <= 0)
            {
                --month; day = M[month - 1];
            }
            if (month <= 0)
            {
                --seedy; month = 12; day = 31;
                if(this->isLeapYear()) {M[1] = 29;}
                else {M[1] = 28;}
            }
            if (seedy < 1582)
            {
                return myDate(1582, 1, 1);
            }
            ++num;
        }
    }

    return myDate(seedy, month, day);
}

myDate myDate::operator-(int num) const
{
    int M[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(this->isLeapYear()) {M[1] = 29;}
    else {M[1] = 28;}

    int seedy(this->getYear()); int month(this->getMonth()); int day(this->getDayOfMonth());

    if(num >= 0)
    {
        while(num > 0)
        {
            --day;
            if (day <= 0)
            {
                --month; day = M[month - 1];
            }
            if (month <= 0)
            {
                --seedy; month = 12; day = 31;
                if(this->isLeapYear(seedy)) {M[1] = 29;}
                else {M[1] = 28;}
            }
            if (seedy < 1582)
            {
                return myDate(1582, 1, 1);
            }
            --num;
        }
    }
    else
    {
        while(num < 0)
        {
            ++day;
            if(day > M[month - 1])
            {
                ++month; day = 1;
            }
            if(month > 12)
            {
                ++seedy; month = 1; day = 1;
                if(this->isLeapYear(seedy)) {M[1] = 29;}
                else {M[1] = 28;}
            }
            ++num;
        }
    }

    return myDate(seedy, month, day);
}

myDate &myDate::operator++()
{
    int M[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(this->isLeapYear()) {M[1] = 29;}
    else {M[1] = 28;}

    int seedy(this->getYear()); int month(this->getMonth()); int day(this->getDayOfMonth());

    ++day;
    if(day > M[month - 1]) {++month; day = 1;}
    if(month > 12) {++seedy; month = 1; day = 1;}

    this->setDate(seedy, month, day);

    return *this;
}

myDate &myDate::operator--()
{
    int M[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(this->isLeapYear()) {M[1] = 29;}
    else {M[1] = 28;}

    int seedy(this->getYear()); int month(this->getMonth()); int day(this->getDayOfMonth());

    --day;
    if(day <= 0) {--month; day = M[month - 1];}
    if(month <= 0)
    {
        --seedy; month = 12; day = 31;
        if(this->isLeapYear()) {M[1] = 29;}
        else {M[1] = 28;}
    }

    if(seedy < 1582) {this->setDate(1582, 1, 1); return *this;}

    this->setDate(seedy, month, day);

    return *this;
}

myDate myDate::operator++(int)
{
    myDate placeholder(*this);

    int M[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(this->isLeapYear()) {M[1] = 29;}
    else {M[1] = 28;}

    int seedy(this->getYear()); int month(this->getMonth()); int day(this->getDayOfMonth());

    ++day;
    if(day > M[month - 1]) {++month; day = 1;}
    if(month > 12) {++seedy; month = 1;}

    this->setDate(seedy, month, day);

    return placeholder;
}

myDate myDate::operator--(int)
{
    myDate placeholder(*this);

    int M[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(this->isLeapYear()) {M[1] = 29;}
    else {M[1] = 28;}

    int seedy(this->getYear()); int month(this->getMonth()); int day(this->getDayOfMonth());

    --day;
    if(day < 1) {--month; day = M[month - 1];}
    if(month < 1) {--seedy; month = 12; day = 31;}

    if(seedy < 1582) {this->setDate(1582, 1, 1); return placeholder;}

    this->setDate(seedy, month, day);

    return placeholder;
}

myDate &myDate::operator=(const myDate &date)
{
    int *ty = new int, *tm = new int, *td = new int;
    *ty = date.getYear(); *tm = date.getMonth(); *td = date.getDayOfMonth();
    this->setDate(*ty, *tm, *td);

    delete ty,tm,td;

    return *this;
}

myDate &myDate::operator+=(int num)
{
    int M[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(this->isLeapYear()) {M[1] = 29;}
    else {M[1] = 28;}

    int month(this->getMonth()); int day(this->getDayOfMonth());
    int seedy(this->getYear());

    if(num >= 0)
    {
        while(num > 0)
        {
            ++day;
            if(day > M[month - 1])
            {
                ++month; day = 1;
            }
            if(month > 12)
            {
                ++seedy; month = 1;
                if(isLeapYear(seedy)) {M[1] = 29;}
                else {M[1] = 28;}
            }
            --num;
        }
    }
    else
    {
        while(num < 0)
        {
            --day;
            if(day <= 0)
            {
                --month; day = M[month - 1];
            }
            if(month <= 0)
            {
                --seedy; month = 12; day = 31;
                if(isLeapYear(seedy)) {M[1] = 29;}
                else {M[1] = 28;}
            }
            if(seedy < 1582)
            {
                this->setDate(1582, 1, 1);
                return *this;
            }
            ++num;
        }
    }

    this->setDate(seedy, month, day);
    return *this;
}

myDate &myDate::operator-=(int num)
{
    int M[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(this->isLeapYear()) {M[1] = 29;}
    else {M[1] = 28;}

    int seedy(this->getYear()); int month(this->getMonth()); int day(this->getDayOfMonth());

    if(num >= 0)
    {
        while(num > 0)
        {
            --day;
            if (day <= 0)
            {
                --month; day = M[month - 1];
            }
            if (month <= 0)
            {
                --seedy; month = 12; day = 31;
                if(isLeapYear(seedy)) {M[1] = 29;}
                else {M[1] = 28;}
            }
            if (seedy < 1582)
            {
                this->setDate(1582, 1, 1);
                return *this;
            }
            --num;
        }
    }
    else
    {
        while(num < 0)
        {
            ++day;
            if(day > M[month - 1])
            {
                ++month; day = 1;
            }
            if(month > 12)
            {
                ++seedy; month = 1;
                if(isLeapYear(seedy)) {M[1] = 29;}
                else {M[1] = 28;}
            }
            ++num;
        }
    }

    this->setDate(seedy, month, day);
    return *this;
}

bool myDate::operator>(const myDate &date) const
{
    int seedy(this->getYear());
    int targety(date.getYear());
    int seed(0), target(0);

    for(int i = 1582; i < seedy; ++i)
    {
        if(this->isLeapYear(i)) {seed += 366;}
        else {seed += 365;}
    }
    seed += getDayOfYear();

    for(int i = 1582; i < targety; ++i)
    {
        if(date.isLeapYear(i)) {target += 366;}
        else {target += 365;}
    }
    target += date.getDayOfYear();

    return seed > target;
}

bool myDate::operator>=(const myDate &date) const
{
    int seedy(this->getYear());
    int targety(date.getYear());
    int seed(0), target(0);

    for(int i = 1582; i < seedy; ++i)
    {
        if(this->isLeapYear(i)) {seed += 366;}
        else {seed += 365;}
    }
    seed += getDayOfYear();

    for(int i = 1582; i < targety; ++i)
    {
        if(date.isLeapYear(i)) {target += 366;}
        else {target += 365;}
    }
    target += date.getDayOfYear();

    return seed >= target;
}

bool myDate::operator<(const myDate &date) const
{
    int seedy(this->getYear());
    int targety(date.getYear());
    int seed(0), target(0);

    for(int i = 1582; i < seedy; ++i)
    {
        if(this->isLeapYear(i)) {seed += 366;}
        else {seed += 365;}
    }
    seed += this->getDayOfYear();

    for(int i = 1582; i < targety; ++i)
    {
        if(date.isLeapYear(i)) {target += 366;}
        else {target += 365;}
    }
    target += date.getDayOfYear();

    return seed < target;
}

bool myDate::operator<=(const myDate &date) const
{
    int seedy(this->getYear());
    int targety(date.getYear());
    int seed(0), target(0);

    for(int i = 1582; i < seedy; ++i)
    {
        if(this->isLeapYear(i)) {seed += 366;}
        else {seed += 365;}
    }
    seed += getDayOfYear();

    for(int i = 1582; i < targety; ++i)
    {
        if(date.isLeapYear(i)) {target += 366;}
        else {target += 365;}
    }
    target += date.getDayOfYear();

    return seed <= target;}

bool myDate::operator==(const myDate &date) const
{
    return this->getYear() == date.getYear() && this->getMonth() == date.getMonth() && this->getDayOfMonth() == date.getDayOfMonth();
}

bool myDate::operator!=(const myDate &date) const
{
    return this->getYear() != date.getYear() || this->getMonth() != date.getMonth() || this->getDayOfMonth() != date.getDayOfMonth();
}
