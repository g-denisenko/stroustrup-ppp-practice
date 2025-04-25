#include<iostream>
using namespace std;

double smaller(double a, double b) {
    if(a < b) return a;
    return b;
}

double larger(double a, double b) {
    if(a > b) return a;
    return b;
}

bool isEqual(double a, double b) {
    if(a == b) return true;
    return false;
}

bool isAlmostEqual(double a, double b, double threshold) {
    double diff = abs(a-b);
    if((diff < threshold) && (diff!=0)) return true;
    return false;
}

double trackSmallerEver(double smallerEver, double currentValue) {
    if(smallerEver > currentValue) return currentValue;
    return smallerEver;
}

double trackLargerEver(double largerEver, double currentValue) {
    if(largerEver < currentValue) return currentValue;
    return largerEver;
}

bool isNewSmallerEver(double smallerEver, double currentValue) {
    if(smallerEver > currentValue) return true;
    return false;
}

bool isNewLargerEver(double largerEver, double currentValue) {
    if(largerEver < currentValue) return true;
    return false;
}

string whichUnits(string units) {
    if(units=="cm" || units==" cm") return "cm";
    if(units=="in" || units==" in") return "in";
    if(units=="ft" || units==" ft") return "ft";
    if(units=="m" || units==" m") return "m";
    return "--- ERR. not a defined unit yet.";
}

void printLog(double currentValue, double previousValue, double threshold, double smallerEver, double largerEver) {
    cout << "the smaller is: " << smaller(currentValue, previousValue) << endl;
    cout << "the larger is: " << larger(currentValue, previousValue) << endl;
    if(isEqual(currentValue, previousValue)) cout << "the numbers are equal."<< endl;
    if(isAlmostEqual(currentValue, previousValue, threshold)) cout << "the numbers are almost equal." << endl;
    if(isNewSmallerEver(smallerEver, currentValue)) cout << currentValue << " the smallest so far." << endl;
    if(isNewLargerEver(largerEver, currentValue)) cout << currentValue << " the largest so far." << endl; 
    cout << endl;
}

int main() {
    double threshold = 1.0/100;
    double currentValue = 0;
    double previousValue = 0;
    double smallerEver = 0;
    double largerEver = 0;
    char exitCode = '|';
    string currentUnit;
    string previousUnit;

    while(true) {
        if(!(cin>>currentValue)) {
            cin.clear();
            if(!(cin>>exitCode)) {
                cin.clear();
                cin >> currentUnit;
                currentUnit = whichUnits(currentUnit);
            }
            else {
                if(exitCode == '|') {
                    cout << "Symbol '|' was met. Program terminated." << endl;
                    break;
                }
                else cout << "Uknown symbol entered." << endl;
            }
        }
        else {
            cin.clear();
            cin >> currentUnit;
            cout << whichUnits(currentUnit) << endl;
            printLog(currentValue, previousValue, threshold, smallerEver, largerEver);
            smallerEver = trackSmallerEver(smallerEver, currentValue);
            largerEver = trackLargerEver(largerEver, currentValue);
            previousValue = currentValue;
        }
    }
}