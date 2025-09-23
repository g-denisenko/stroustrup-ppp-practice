#include <iostream>
using namespace std;

void print_vector(const vector<int>& v, string label) {
    if(!v.size()) {
        cerr << "Vector of int's is empty." << endl;
        return;
    }
    cout << label << endl;
    for(int i=0; i<v.size(); ++i) {
        cout << v[i] << '\n';
    }
    cout << endl;
}

vector<int> fibonacci(int x, int y, vector<int>& v, int n) {
    if(x==y) {
        cerr << "X & Y numbers are equal." << endl;
        return v;
    }
    if(x<0 || y<0) {
        cerr << "X or Y number is less then 0." << endl;
        return v;
    }
    if(x>y) {
        cerr << "X is greater of Y." << endl;
        return v;
    }
    if(n<2) {
        cerr << "The count of Fibo's sequence cannot be less then 2." << endl;
        return v;
    }
    if(v.size()) {
        cerr << "Vector of int's is not empty." << endl;
        return v;
    }
    v.push_back(x);
    v.push_back(y);
    for(int i=0; i<n-2; ++i) {
        int tmp = v[i]+v[i+1];
        v.push_back(tmp);
    }
    return v;
}

int main() {
    vector<int> v(0);
    fibonacci(4,23,v,5);
    print_vector(v, "Print Fibo's");
}