#include <iostream>
#include <cassert>
using namespace std;

double discriminant(double a, double b, double c) {
    double d = (b*b) - (4*a*c);
    if(d < 0) cout << "An equation with no real roots" << endl;
    assert(d>=0 && "No have real root: discriminant < 0. There're no real-number solution");
    return d;
}

void solution_one_root(double a, double b, double c) {
    double x = -b/(2*a);
    cout << "x= " << x << endl;
    assert(a*x*x+b*x+c==0 && "Solution for 'x' is wrong!");
}

void solution_two_root(double a, double b, double c, double d) {
    vector<double> result;
    result.push_back((-b + sqrt(d))/(2*a));
    result.push_back((-b - sqrt(d))/(2*a));
    cout << "x1= " << result[0] << "\t x2= " << result[1] << endl;
    assert(a*result[0]*result[0]+b*result[0]+c==0 && "Check failed! Possibly, wrong rounding operation for x1");
    assert(a*result[1]*result[1]+b*result[1]+c==0 && "Check failed! Possibly, wrong rounding operation for x2");
}

vector<int> user_nums() {
    vector<int> result;
    int i = 0;
    while(i<3) {
        int x;
        cin >> x;
        if(!cin) {
            cout << "Wrong input. Try again." << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        result.push_back(x);
        i++;
    }
    cout << "a: " << result[0] 
        << "\nb: " << result[1] 
        << "\nc: " << result[2] 
        << endl;
    return result;
}

int main() {
    cout << "Enter a, b, c for quadratic equation: " << endl;
    
    vector<int> nums = user_nums();
    int a = nums[0];
    int b = nums[1];
    int c = nums[2];

    double d = discriminant(a, b, c);
    cout << "Discrimintant is " << d << endl;
    if(d) cout << "Square root of discriminant is " << sqrt(d) << endl;
    
    if(d > 0) solution_two_root(a, b, c, d);
    if(d == 0) solution_one_root(a, b, c);

    return 0;
}