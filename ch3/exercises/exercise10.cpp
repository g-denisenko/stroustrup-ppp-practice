#include <iostream>
using namespace std;

int main() {
    int shift_ascii_code = 48;
    unsigned long int grains = 1;
    for(double i=1; i<=64; i++) {
        grains *=2;
        if(i==64) cout << "Sum of all grains inventor asked are: " << grains*2-1 << endl;
    }
    return 0;
}