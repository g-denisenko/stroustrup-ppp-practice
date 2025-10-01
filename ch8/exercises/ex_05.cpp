#include <iostream>
using namespace std;

class Book {
    public:
    Book() : isbn("-"), title("-"), author("-"), copydate(2001) {};
    Book(string, string, string, int);

    auto get_isbn() const -> string {return isbn;}
    auto set_isbn(string s) -> void {isbn = s;}

    auto get_title() const -> string {return title;}
    auto set_title(string s) -> void {title = s;}

    auto get_author() const -> string {return author;}
    auto set_author(string s) -> void {author = s;}

    auto get_copydate() const -> int {return copydate;}
    auto set_copydate(int i) -> void {copydate = i;}

    auto is_checked_out() -> bool const {return checked_out;}
    auto book_in() -> bool {checked_out=true; return true;}
    auto book_out() -> bool {checked_out=false; return false;}

    private:
    string isbn{""};
    string title{""};
    string author{""};
    int copydate{0};
    bool checked_out{false};
};

bool isbn_validation(const string& str) {
    if(str.size()<7 || str.size()>13) {
        cerr << "ISBN size is invalid.\n";
        return false;
    }
    int dashes = 0;
    for(size_t i=0; i<str.size(); ++i) {  
        // to count dashes in respect: n-n-n-x
        if(str[i] == '-')
            ++dashes;
        if(dashes<3 && (str[i]==isalpha(str[i]))) {
            cout << "ISBN is not respect n-n-n-x format: (digit expected).\n";
            return false;
        }
        if(dashes==3 && (str[i]==isdigit(str[i]))) {
            cout << "ISBN is not respect n-n-n-x format: (letter expected).\n";
            return false;
        }
    }
    if(dashes != 3) {
        cout << "ISBN is not respect n-n-n-x format: (wrong times dashes '-').\n";
        return false;
    }
    return true;
}

Book::Book(string i, string t, string a, int cd) {
    if(!isbn_validation(i)) {
        cerr << "Wrong ISBN. Input book is failed.\n";
        return;
    }
    int current = 2026;     // date of publish cannot be newer then current year
    if(cd > current) {
        cerr << "Wrong Copyright year. Input book is failed.\n";
        return;
    }
    set_isbn(i);
    set_title(t);
    set_author(a);
    set_copydate(cd);
}

ostream& operator<<(ostream& os, Book& b) {
    cout << "----------------------\n";
    cout << "ISBN: " << b.get_isbn() << "\n";
    cout << "Title: " << b.get_title() << "\n";
    cout << "Author: " << b.get_author() << "\n";
    cout << "Copyright: " << b.get_copydate() << "\n";
    cout << "Booked Status: " << ((b.is_checked_out()) ? "Yes" : "No") << "\n";
    return os;
}

int main() {
    Book b{"0-3006-4105-X", "Anathomy of Code", "J.Lourance", 1998};        // GOOD example
    Book c{"0-3000006-4105-X", "Anathomy of Code", "J.Lourance", 2045};     // BAD example

    cout << b << c << endl;
}