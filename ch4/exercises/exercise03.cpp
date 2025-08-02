#include <cassert>
#include <iostream>
#include <limits>
using namespace std;

double celsius_to_kelvin(double celsius)
{
    assert(celsius > -273.15 && "REASON: Temperature cannnot below absolute 0");
    return celsius + 273.15;
}

int main()
{
    cout << "Enter a temperature in Celsius: " << endl;
    double celsius = 0;
    while(!(cin>>celsius)){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cerr << "Wrong input. Try again" << endl;
    }
    cout << "You entered Celsius: " << celsius << endl;
    double kelvin = celsius_to_kelvin(celsius);
    cout << celsius << " celsius in kelvin is: " << kelvin << endl;
}