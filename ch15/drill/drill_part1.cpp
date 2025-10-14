#include <iostream>
using namespace std;

void print_array(ostream& os, int* a, int n) {
    for(int i=0; i<n; ++i) 
        os << a[i] << "\n";
}

int main() {

    int range = 10;
    int* arr = new int[range];

    for (int i=0; i<range; ++i)
        arr[i] = i*range;       // Asing by ten's like 10, 20, 30 ...
    
    print_array(cout, arr, range);
    delete[] arr;
    return 0;
}
