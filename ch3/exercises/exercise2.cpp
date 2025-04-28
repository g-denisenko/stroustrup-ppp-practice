#include <iostream>
using namespace std;

int main() {
    while(true) {
        cout << "Please, enter a string: " << endl;
        string str;
        cin >> str;
        for(int i=0; i<str.size(); i++) {
            int code = str[i];
            cout << str[i] << " - " << code << endl;
        }
    }
    return 0;
}