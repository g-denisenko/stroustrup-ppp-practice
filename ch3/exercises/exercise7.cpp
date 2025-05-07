#include <iostream>
using namespace std;

int spell_to_digit(string str, vector<string> spelled, int count_succeed) {
    for(int i=0; i<spelled.size(); i++) {
        if(spelled[i] == str) {
            cout << spelled[i] << " as integer: " << i << endl;
            ++count_succeed;
        }
    }
    return count_succeed;
}

int digit_to_spell(string str, vector<string> spelled, int count_succeed) {
    for(int i=0; i<spelled.size(); i++) {
        if(to_string(i) == str) {
            cout << i << " is spelled as: " << spelled[i] << endl;
            return ++count_succeed;
        }
    }
    return 0;
}
int main() {
    vector<string> spelled = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string str;
    while(cin>>str) {
        int count_succeed = 0;
        count_succeed += spell_to_digit(str, spelled, count_succeed);
        count_succeed += digit_to_spell(str, spelled, count_succeed);
        if(count_succeed < 1) cout << "Not able to recognize it yet." << endl;
    }
    return 0;
}