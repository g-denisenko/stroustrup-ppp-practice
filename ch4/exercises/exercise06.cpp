#include <iostream>
#include <cassert>
using namespace std;

double ctof(double c) {
    assert(c>-273.15 && "Temperature cannot be lower then absolute zero.");
    return c*9/5 +32;
}

double ftoc(double f) {
    assert(f>-459.67 && "Temperatrue cannot be lower then absolute zero.");
    return (f-32)*5/9;
}

int main() {
    cout << ctof(32) << endl;
    cout << ftoc(12) << endl;
    return 0;
}