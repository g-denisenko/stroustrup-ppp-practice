#include <cassert>
#include <iostream>
#include <limits>
using namespace std;

auto user_input_check_int() {
    int input;
    while(!(cin>>input)){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cerr << "Wrong input of type 'int'. Try again" << endl;
    }
    return input;
}

auto user_input_check_double() {
    double input;
    while(!(cin>>input)){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cerr << "Wrong input of type 'double'. Try again" << endl;
    }
    return input;
}

double celsius_to_kelvin(double celsius)
{
    assert(celsius > -273.15 && "REASON: Temperature cannnot below absolute 0");
    return celsius + 273.15;
}

double kelvin_to_celsius(double kelvin)
{
    assert(kelvin > 0 && "REASON: Temperature cannnot below absolute 0");
    return kelvin - 273.15;
}

int main()
{
    cout << "Choose a units to convert: \n\t1.Celsius to Kelvins\n\t2.Kelvins to Celsius" << endl;
    int input = user_input_check_int();
    double celsius;
    double kelvin;

    switch(input) {
        case 1:
            cout << "Enter a Celsius: " << endl;
            celsius = user_input_check_double();
            cout << celsius << " Celsius in Kelvins is: " << celsius_to_kelvin(celsius) << endl;
            break;
        case 2:
            cout << "Enter a Kelvins: " << endl;
            kelvin = user_input_check_double();
            cout << kelvin << " Kelvins in Celsius is: " << kelvin_to_celsius(kelvin) << endl;
            break;
        default:
            cout << "Something went wront..." << endl;
            break;
    }
}