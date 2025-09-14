
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "libs/std_lib_facilities.h"

class Token {
    public:
        char kind;
        double value;
        string name;
        Token(char ch) :kind(ch), value(0) { }
        Token(char ch, double val) :kind(ch), value(val) { }
        Token(char ch, string n) :kind(ch), name(n) { }
};

class Token_stream {
    public:
        bool full;
        Token buffer;
        Token_stream() :full(false), buffer('\0') { }

        Token get();
        void putback(Token t) { buffer = t; full = true; }

        void ignore(char);
};

const char let = 'L';
const char quit = 'q';
const char print = ';';
const char number = '8';
const char name = 'a';
const string declkay = "let";

Token Token_stream::get()
{
	if (full) {
        full = false;
        return buffer;
    }

	char ch;
	cin >> ch;
	switch (ch) {
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
		case '=':
        case print:
		case quit:
            return Token(ch);
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);
            double val;
            cin >> val;
            return Token(number, val);
        }
        default:
            if (isalpha(ch)) {
                string s;
                s += ch;
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) 
					s += ch;
                cin.putback(ch);
                if (s == declkay) 
					return Token(let);
                return Token{name, s};
            }
            error("Bad token");
        }
}

void Token_stream::ignore(char c)
{
	// c represents the kind of Token
	if (full && c==buffer.kind) {	// first look in buffer
		full = false;
		return;
	}
	full = false;

	// Now, search input:
	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

class Variable {
	public:
		string name;
		double value;
		Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

double get_value(string s)
{
	// return the value of the Variable named s
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{
	// set the Variable names s to d	
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("'(' expected");
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double declaration()
{
	// assume we have seen "let"
	// handling : name = expression
	// decalre a varialbe called 'name'  with the initial value 'expression'

	Token t = ts.get();
	if (t.kind != name)
		error("name expected in declaration");	
	string name = t.name;
	if (is_declared(name))
		error(name, " declared twice");

	Token t2 = ts.get();
	if (t2.kind != '=')
		error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.putback(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.putback(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

double define_name(string var, double val)
         // add {var,val} to var_table
{
         if (is_declared(var))
                 error(var," declared twice");
         names.push_back(Variable{var,val});
         return val;
}

int main() {
	try {
		define_name("pi",3.1415926535);
		define_name("e",2.7182818284);	
		define_name("k",1000);	
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >> c && c != ';');
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin >> c && c != ';');
		return 2;
	}
}