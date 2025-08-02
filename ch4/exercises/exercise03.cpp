#include <iostream>
#include <limits>
using namespace std;

void error (string s) {
    throw runtime_error{s};
}

double celsius_to_kelvin(double celsius)
{
    return celsius + 273.15;
}

int main()
{
    cout << "Enter a temperature in Celsius: " << endl;
    double celsius = 0;
    try {
        while(!(cin>>celsius)) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cerr << "Wrong input. Try again" << endl;
        }
        if(celsius < -273.15) error("Entered Celsus below -273.15");
        cout << "You entered Celsius: " << celsius << endl;
        double kelvin = celsius_to_kelvin(celsius);
        cout << celsius << " celsius in kelvin is: " << kelvin << endl;
    }
    catch(runtime_error& e) {
        cerr << "Absolute temperature cannot be below 0" << endl;
    }
}