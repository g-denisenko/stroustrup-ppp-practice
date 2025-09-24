#include <iostream>
using namespace std;

void f(const int);

void f(const int a) {
    // a += 3; error, since a-value protected from modifying
    int res = a + 3;
    cout << "Result: " << res << "\na: " << a << endl;
}

int main() {
    f(4);
}