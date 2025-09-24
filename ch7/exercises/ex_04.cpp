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
    const int min_numbers = 2;  // x and y are 2 initial numbers
    if(x == y) {
        cerr << "X & Y numbers are equal." << endl;
        return v;
    }
    if(x<0 || y<0) {
        cerr << "X or Y number is less then 0." << endl;
        return v;
    }
    if(x > y) {
        cerr << "X is greater of Y." << endl;
        return v;
    }
    if(n < min_numbers) {
        cerr << "The count of Fibo's sequence cannot be less then 2." << endl;
        return v;
    }
    if(v.size()) {
        cerr << "Vector of int's is not empty." << endl;
        return v;
    }
    v.push_back(x);
    v.push_back(y);
    for(int i=0; i<n-min_numbers; ++i) {
        int tmp = v[i]+v[i+1];
        if(tmp < 0) {   // Find max int in Range of int
            cerr << "New item " <<  tmp << " is out-of-range of int." << endl;
            cout  << "Max int was met as " << v[i+1] << endl;
            break;
        }
        v.push_back(tmp);
    }
    return v;
}

int main() {
    vector<int> v(0);
    fibonacci(1,2,v,500);
    print_vector(v, "Print Fibo's sequence");
}