#include <iostream>
using namespace std;

void print_vector(vector<int> v, string label) {
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

int main() {
    vector<int> v(0);
    print_vector(v, "Test label");
}