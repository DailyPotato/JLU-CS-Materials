#include <iostream>

using namespace std;

class Date
{
public:
    Date(int y, int m, int d):year(y), month(m), day(d){}
    void setDate(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    bool isLeapYear()
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return true;
        return false;
    }
    bool isEndOfMonth()
    {
        if (month == 2)
        {
            if (isLeapYear())
                return day == 29;
            else
                return day == 28;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
            return day == 30;
        else
            return day == 31;
    }
    int addDaysFromNow(Date other)
    {
        int addday = 0;
        int tempyear = year;
        for(tempyear = year; tempyear < other.year; tempyear++)
        {
            if ((tempyear % 4 == 0 && tempyear % 100 != 0) || (tempyear % 400 == 0))
                addday += 366;
            else
                addday += 365;
        }
        for(int i=month;i!=other.month;i++)
        {
            if (i == 2)
            {
                if(tempyear!=other.year)
                {
                    if (tempyear % 4 == 0 && tempyear % 100 != 0 || tempyear % 400 == 0)
                        addday += 29;
                    else
                        addday += 28;
                }
                else
                {
                    if(other.isLeapYear())
                        addday += 29;
                    else
                        addday += 28;
                }
            }
            else if (i == 4 || i == 6 || i == 9 || i == 11)
                addday += 30;
            else
                addday += 31;
        }
        addday += other.day - day;
        return addday;
    }
    int calculateDaysBetween(Date date1,Date date2)
    {
        if (date1.year > date2.year || (date1.year == date2.year && date1.month > date2.month) || (date1.year == date2.year && date1.month == date2.month && date1.day > date2.day))
            return -calculateDaysBetween(date2, date1);
        return date1.addDaysFromNow(date2);
    }
    void printDate(string type)
    {
        if(type == "YYYY-MM-DD")
            cout << year << "-" << month << "-" << day << endl;
        else if(type == "MM/DD/YYYY")
            cout << month << "/" << day << "/" << year << endl;
        else if(type == "DD.MM.YYYY")
            cout << day << "." << month << "." << year << endl;
    }
    private:
    int year;
    int month;
    int day;
};

int main()
{
    Date date1(2026, 5, 17);
    Date date2(2030, 12, 25);
    cout<<date1.isLeapYear()<<endl;
    cout<<date1.isEndOfMonth()<<endl;
    cout<<date1.addDaysFromNow(date2)<<endl;
    cout << date1.calculateDaysBetween(date1, date2) << endl;
    date1.printDate("YYYY-MM-DD");
    date1.printDate("MM/DD/YYYY");
    date1.printDate("DD.MM.YYYY");
    return 0;
}