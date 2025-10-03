#include <iostream>
#include <sstream>
using namespace std;

class Point {
    public:
    double x{0};
    double y{0};
    Point() :x() ,y() {};
    Point(double xx, double yy) :x(xx), y(yy) {};
};

ostream& operator<<(ostream& os, const Point& p) {
    cout << p.x << " " << p.y << '\n';
    return os;
}

int get_coords(Point& p, const string& s) {
    istringstream is{s};
    double x,y;
    char left, ch, right;
    is >> left >> x >> ch >> y >> right;
    if(!is || left!='(' || ch!=',' || right!=')') {
        cerr << "wrong input string.\n";
        return -1;
    }
    p.x = x;
    p.y = y;
    is >> ws;   // for clean whitespaces rest of the file (if exists)
    if(is.eof()) cout << "eof reached.\n";
    return 1;
}

int main() {
    Point p{0.1,0.1};
    cout << p << endl;

    string s_good{"(1.21,213.23)"};     // Good string
    string s_bad{"~(22.01,13.03)"};     // Bad string
    
    get_coords(p, s_good);
    cout << p << endl;
    get_coords(p, s_bad);
    cout << p << endl;
}