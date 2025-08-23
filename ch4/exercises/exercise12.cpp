#include <iostream>
#include <cassert>
#include <climits>
#include <random>

using namespace std;

bool check_digit_repetition(int n) {
    assert(n>999 && n<10000 && "Not a 4-digit number. ERROR");
    vector<int> digits;
    digits.push_back((n%10000)/1000);
    digits.push_back((n%1000)/100);
    digits.push_back((n%100)/10);
    digits.push_back((n%10)/1);

    for(int i=0; i<digits.size(); i++) {
        for(int j=0; j<digits.size(); j++) {
            if(i!=j && digits[i]==digits[j]) return true;
        }
    }
    return false;
}

int user_guess() {
    cout << "Enter an 4-digit integer: " << endl;
    int n = 0;
    while(true) {
        cin >> n;
        if(!cin) {
            cout << "Not an integer. Please, try again" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }

        assert(n<INT_MAX && "OUT OF RANGE of maximum");

        if(n<1000 || n>9999) {
            cout << "Not a 4-digit integer. Please, try again." << endl;
            continue;
        }

        if(check_digit_repetition(n)) {
            cout << "Duplicate digit was found. Please, try again." << endl;
            continue;
        }

        cout << "User input confirmed as: " << n << endl;
        return n;
    }
}

int random_int() {
    random_device rd;  // a seed source for the random number engine
    mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(0, 9);
    int n = distrib(gen);
    return n;
}

int secret_four_digit() {
    int secret_four_digit = 0;
    bool a, b, c, d, e, f, g, h, i, j;
    a = b = c = d = e = f = g = h = i = j = false;  // Flag for repeated digit encounter
    int multy = 1000; 
    for(int i=0; i<=4; i++) {
        int rand = random_int();
        if(rand==0 && !a && multy!=1000) {a=true; multy /= 10; continue;}
        if(rand==1 && !b) {b=true; secret_four_digit = secret_four_digit+multy*rand; multy /= 10; continue;}
        if(rand==2 && !c) {c=true; secret_four_digit = secret_four_digit+multy*rand; multy /= 10; continue;}
        if(rand==3 && !d) {d=true; secret_four_digit = secret_four_digit+multy*rand; multy /= 10; continue;}
        if(rand==4 && !e) {e=true; secret_four_digit = secret_four_digit+multy*rand; multy /= 10; continue;}
        if(rand==5 && !f) {f=true; secret_four_digit = secret_four_digit+multy*rand; multy /= 10; continue;}
        if(rand==6 && !g) {g=true; secret_four_digit = secret_four_digit+multy*rand; multy /= 10; continue;}
        if(rand==7 && !h) {h=true; secret_four_digit = secret_four_digit+multy*rand; multy /= 10; continue;}
        if(rand==8 && !i) {i=true; secret_four_digit = secret_four_digit+multy*rand; multy /= 10; continue;}
        if(rand==9 && !j) {j=true; secret_four_digit = secret_four_digit+multy*rand; multy /= 10; continue;}
        i--;    // In case if no digit added for 4-digit number
    }
    assert(!check_digit_repetition(secret_four_digit) && "Wrong secret 4-digit number. Was generated number with digit repetition.");
    return secret_four_digit;
}

int main() {
    int guess = user_guess();
    int secret = secret_four_digit();
    cout << secret << ':' << guess << endl;
  
    return 0;
}