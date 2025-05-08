#include <iostream>
using namespace std;

int spell_to_digit(string str, vector<string> spelled_map, int error_code) {
    for(int i=0; i<spelled_map.size(); i++) {
        if(spelled_map[i] == str) {
            return i;
        }
    }
    return error_code;
}

int digit_to_spell(string str, vector<string> spelled_map, int error_code) {
    for(int i=0; i<spelled_map.size(); i++) {
        if(to_string(i) == str) {
            return i;
        }
    }
    return error_code;
}

int define_number(int defined, string str, vector<string> spelled_map, int error_code) {
    if(spell_to_digit(str, spelled_map, error_code)!=error_code) {
        defined = spell_to_digit(str, spelled_map, error_code);
        return defined;
    }
    if(digit_to_spell(str, spelled_map, error_code)!=error_code) {
        defined = digit_to_spell(str, spelled_map, error_code);
        return defined;
    }
    return error_code;
}

char ask_operation_symbol(string str) {
    if(str[0]=='+' || str[0]=='-' || str[0]=='*' || str[0]=='/') {
        return str[0];
    }
    return '_';
}

void print_operation(int a, int b, char operation_symbol) {
    switch(operation_symbol) {
        case '+':
            cout << "The sum of " << a << " and " << b << " is " << a+b << endl;
            break;
        case '-':
            cout << "The difference of " << a << " and " << b << " is " << a-b << endl;
            break;
        case '*':
            cout << "The multiply of " << a << " and " << b << " is " << a*b << endl;
            break;
        case '/':
            cout << "The division of " << a << " and " << b << " is " << a/b << endl;
            break;
        default:
            cout << "ERROR. Wrong input possibly." << endl;
            break;
    }
}

int main() {
    vector<string> spelled_map = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string str;
    vector<int> numbers;
    int error_code = 111;
    char operation_symbol;

    while(true) {
        cout << "Enter two numbers and operation symbol (+,-,*,/): ";
        while(cin>>str) {
            int defined = define_number(defined, str, spelled_map, error_code);
            if(defined != error_code) {
                numbers.push_back(defined);
            }
            if(ask_operation_symbol(str)!='_'){
                operation_symbol = ask_operation_symbol(str);
                break;
            }
        }
        print_operation(numbers[0], numbers[1], operation_symbol);
        numbers.clear();
    }
    return 0;
}