#include <iostream>
using namespace std;

double ask_number() {
    double num;
    if(cin>>num) return num;
    std::cin.ignore(1000, '\n');
    cin.clear();
}

char ask_operation_symbol() {
    char symbol;
    cin >> symbol;
    if(symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/') return symbol;
    std::cin.ignore(1000, '\n');
    cin.clear();
}

void print_operation(double a, double b, char operation_symbol) {
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

void calculation() {
    cout << "Enter two numbers and operation symbol (+,-,*,/): ";
    double a,b;
    char operation_symbol;
    a = ask_number();
    b = ask_number();
    operation_symbol = ask_operation_symbol();
    print_operation(a, b, operation_symbol);
}

int main() {
    while(true) {
        calculation();
    }
    return 0;
}