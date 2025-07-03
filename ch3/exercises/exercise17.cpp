#include <iostream>
using namespace std;

double discriminant(double a, double b, double c) {
    return b*b - 4*a*c;
}

vector<double> solution(double a, double b, double c) {
    vector<double> result;
    result.push_back((-b+sqrt(abs(discriminant(a, b, c))))/2*a);
    result.push_back((-b-sqrt(abs(discriminant(a, b, c))))/2*a);
    return result;
}

int main() {
    cout << "Enter A, B, C for Quadratic equation ( Axx+Bx+c = 0 ): " << endl;
    double  a, b, c;
    cin >> a >> b >> c;
    cout << "Solution for quadratic equation: " << a << "xx+" << b << "x+" << c << "=0" << endl;
    vector<double> answer= solution(a, b, c);
    cout << "x1: " << answer[0] << "\tx2: " << answer[1] << endl;

    return 0;
}