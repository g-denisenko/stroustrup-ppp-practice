#include <iostream>
#include <cassert>
#include <climits>
using namespace std;

int user_num() {
    cout << "Enter an integer for the first N numbers: " << endl;
    int n;
    while(true) {
        cin >> n;
        if(!cin) {
            cout << "Not an integer.\nPlease, try again" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }

        assert(n<INT_MAX && "OUT OF RANGE of maximum");

        if(n < 0) {
            cout << "N items cannot be negative.\nPlease, enter a positive number." << endl;
            continue;
        }
        if(n == 0) {
            cout << "You're entered 0(zero).\nPlease, enter a positive number." << endl;
            continue;
        }
        return n;
    }
}

int fibo_int_max() {
    int last = 0;
    int penult = 1;
    int current = last+penult;
    for(int i=current; i<=INT_MAX; i=current) {
        penult = last;
        last = current;
        current = last+penult;
        if(last<=INT_MAX && current<last) return last;  // Return last fibo number in range of INT
    }
    return -1;   // Code when something wrong
}

int fibo_iterator(int n) {
    int last = 0;
    int penult = 1;
    int current = last+penult;
    for(int i=1; i<=n; i++) {
        cout << i << ". " << current << endl;
        penult = last;
        last = current;
        current = last+penult;
        if(last<INT_MAX && current<last) {
            cerr << "ERROR: boundary reached. Out of Range (INT)" << endl;
            return -1;  // Code for out-of-range
        }
    }
    return 0;   // Code for fine completion
}

int main() {
    cout << "max int: " << INT_MAX << endl;
    int count = user_num();
    fibo_iterator(count);
    cout << "Max fibo number in range of INT: " << fibo_int_max() << endl;

    return 0;
}