#include <iostream>
using namespace std;

enum class Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

vector<string> month_tbl = {"Not a month", "January", "February", "March", "April", "May", "June", "Jule", "August", "September", "Octember", "November", "December"};

class Year {
    public:
    int year = 2001;
    Year(){};
    Year(int y) : year(y){};
};

class Day {
    public:
    int day = 1;
    Day(){};
    Day(int d) : day(d){};
};

class Date {
    public:
    Date(){};
    Date(Day dd, Month mm, Year yy) :d(dd),m(mm),y(yy) {};
    bool is_valid();    // Don't implemented yet
    int year() const {return y.year;}
    int month() const {return (int)m;}
    string month_str() const {return month_tbl[(int)m];}
    int day() const {return d.day;}
    void add_day();

    private:
    Year y;
    Month m{Month::jan};
    Day d;
};

void Date::add_day() {
    if(d.day == 31) {
        if((int)m == 12) {
            m = Month::jan;
            d.day = 1;
            y.year = y.year+1;
        }
        else {
            m = (Month)(month()+1);
            d = 1;
        }
    }
    else {
        m = (Month)(month()+1);
        d = d.day+1;
    }
}

ostream& operator<<(ostream& os, Date d) {
    return os << d.day() << " " << d.month_str() << " " << d.year();
}

int main() {
    Date d;
    Date d2{31,Month::apr,2004};
    Date d3{31,Month::dec,2004};
    Date today = {2,Month::feb, 2020};
    Date tommorow = today;
    tommorow.add_day();
    cout << d << " - " << d2 << " - " << d3 << endl;
    cout << "today: "<< today << endl;
    cout << "tommorow: "<< tommorow << endl;
}