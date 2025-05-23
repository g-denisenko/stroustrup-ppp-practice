#include <iostream>
using namespace std;

int how_many_squares(long long int contain) {
    long long int grains = 1;
    for(int i=0; i<64; i++) {
        if(grains-1 >= contain) return i+1;
        grains *= 2;
    }
    return 0;
}

void print_statistic() {
    unsigned long long int grains_in_square = 1;
    unsigned long long int grains_sum = 0;
    for(int i=1; i<=64; i++) {
        grains_sum = grains_in_square-1;
        cout << "Square No: " << i << " contains " << grains_in_square << " grain(s). Sum: " << grains_sum << endl;
        grains_in_square *= 2;
    }
}

int main() {
    

    cout << "To give the inventor 1'000 grains requared at least " << how_many_squares(1000) << " squares." << endl;
    cout << "To give the inventor 1'000'000 grains requared at least " << how_many_squares(1000000) << " squares." << endl;
    cout << "To give the inventor 1'000'000'000 grains requared at least " << how_many_squares(1000000000) << " squares." << endl;

    print_statistic();
    
    return 0;
}