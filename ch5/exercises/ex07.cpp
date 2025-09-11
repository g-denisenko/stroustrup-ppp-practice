#include <iostream>
using namespace std;

class Token {
    public:
        int digit;
        char kind;
        Token(char ch) :digit(0), kind(ch) { };
        Token(int i) :digit(i), kind('i') { }; 
};

class Token_stream {
    public:
        Token get();
        void putback(Token t);
        Token_stream();
    private:
        bool full;
        Token buffer;
};

Token_stream::Token_stream() :full(false), buffer('\0')
{
}

void Token_stream::putback(Token t) {
    if(full) cerr << "buffer already full." << endl;
    buffer = t;
    full = true;
}

Token Token_stream::get() {
    if(full) {
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;
    switch(ch) {
        case '=': case 'x':
            return Token(ch);
        case '0': case '1': case '2': case '3': case '4': 
        case '5': case '6': case '7': case '8': case '9': {
            int i = static_cast<int>(ch-48);
            return Token(i);
        }
        default:
            cerr << "A digit expected." << endl;
            return Token(ch);
    }
}

Token_stream ts;
vector<string> dict = {" ones."," tens "," hundreds "," thousand "};

int parse_integer() {
    int result = 0;
    int idx = 10;
    while(cin) {
        Token t = ts.get();
        if(t.kind == 'i') result = result*idx+t.digit;
        if(t.kind == '=') break;
    }
    return result;
}

void spell_intger(int number) {
    string str;
    int devider = 10;
    int scaler = 1;
    for(int i=0; i<dict.size(); i++) {
        if(number>9999){
            cout << "Cannot spell it yet. Try number lower then 10000." << endl;
            break;
        }
        if(number%devider) {
            int tmp = (number/scaler)%devider;
            scaler *=10;
            if(tmp) {
                str = to_string(tmp)+dict[i]+str;
            }
        }
    }
    cout << str << endl;
}

int main() {
    while(true) {
        cout << "\nEnter an integer (positive only).\nFinish line by '='\n'x' for exit.\n> ";
        Token t = ts.get();
        if(t.kind != 'x') {
            ts.putback(t);
            int n = parse_integer();
            cout << n << " is ";
            spell_intger(n);
        }
        else {
            cout << "Program terminaded." << endl;
            break;
        }
    }
    return 0;
}