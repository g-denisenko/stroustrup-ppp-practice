#include <iostream>
#include <vector>
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

bool isLegalUnits(string units) {
    if(units=="cm" || units==" cm" || units=="m" || units==" m" || units=="in" || units==" in" || units=="ft" || units==" ft" ) return 1;
    else  return 0;
}

double convertToMeters(double currentValue, string units) {
    if(units=="cm" || units==" cm") return currentValue/100;
    if(units=="in" || units==" in") return currentValue/100*2.54;
    if(units=="ft" || units==" ft") return currentValue/100*2.54*12;
    if(units=="m" || units==" m") return currentValue;
    return 0.0;

}

void printLog(double currentValue, double previousValue, double threshold, double smallerEver, double largerEver) {
    cout << "the smaller is: " << smaller(currentValue, previousValue) << "m" << endl;
    cout << "the larger is: " << larger(currentValue, previousValue) << "m" << endl;
    cout << "the summ of 2 values is: " << smaller(currentValue, previousValue) + larger(currentValue, previousValue) << "m" << endl;
    if(isEqual(currentValue, previousValue)) cout << "the numbers are equal."<< endl;
    if(isAlmostEqual(currentValue, previousValue, threshold)) cout << "the numbers are almost equal." << endl;
}

void printRecord(double currentValue, double smallerEver, double largerEver) {
    if(isNewSmallerEver(smallerEver, currentValue)) cout << currentValue << "m the smallest so far." << endl;
    if(isNewLargerEver(largerEver, currentValue)) cout << currentValue << "m the largest so far." << endl;
}

void printAllValues(vector<double> valuesInMeters) {
    cout << "All entered values after sort: ";
    for(double x : valuesInMeters) {
        cout << x << "m ";
    }
    cout << endl;
}

void printSumAllValues(vector<double> valuesInMeters) {
    cout << "Sum of all entries is: ";
    double sum = 0;
    for(double x : valuesInMeters) {
        sum += x;
    }
    cout << sum << "m" << endl;
}

int main() {
    double threshold = 1.0/100;
    double currentValue = 0;
    double previousValue = 0;
    double smallerEver = 0;
    double largerEver = 0;
    char exitCode;
    string currentUnit;
    string previousUnit;
    vector<double> numbersPair;
    vector<double> valuesInMeters;

    while(true) {
        cout << "\nPlease, enter a number and units (e.g. cm, m, in, ft): " << endl;
        if(!(cin>>currentValue)) {
            cin.clear();
            cin>>exitCode;
            if(exitCode == '|') {
                cout << "Symbol '|' was met. Program will terminated." << endl;

                
                sort(valuesInMeters.begin(), valuesInMeters.end());
                printAllValues(valuesInMeters);
                printSumAllValues(valuesInMeters);
                break;
            }
            else cout << "Uknown symbol entered." << endl;
        }
        else {
            cin >> currentUnit;
            if(isLegalUnits(currentUnit)) {
                currentValue = convertToMeters(currentValue, currentUnit);
                if(numbersPair.size() < 2) {
                    numbersPair.push_back(currentValue);
                    valuesInMeters.push_back(currentValue);
                    if(numbersPair.size()==2){
                        printLog(currentValue, previousValue, threshold, smallerEver, largerEver);
                        numbersPair.clear();
                    }
                }

                printRecord(currentValue, smallerEver, largerEver);
                smallerEver = trackSmallerEver(smallerEver, currentValue);
                largerEver = trackLargerEver(largerEver, currentValue);
                previousValue = currentValue;
                previousUnit = currentUnit;
            }
            else cout << "Illigal units. Try another one." << endl;
        }
    }
}