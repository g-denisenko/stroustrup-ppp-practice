#include <iostream>
using namespace std;

enum class Genre {
    fiction=1, nonfiction, periodical, biography, children
};

const vector<string> genre_tbl = {"No genre","Fiction", "Non-fiction", "Periodical", "Biography", "Children"};

class Book {
    public:
    Book() : isbn("-"), title("-"), genre((Genre)0), author("-"), copydate(2001) {};
    Book(string, string, Genre, string, int);

    auto get_isbn() const -> string {return isbn;}
    auto set_isbn(string s) -> void {isbn = s;}

    auto get_title() const -> string {return title;}
    auto set_title(string s) -> void {title = s;}

    auto get_genre() const -> Genre {return genre;}
    auto set_genre(Genre g) -> void {genre = g;}

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
    Genre genre{(Genre)0};
    string author{""};
    int copydate{0};
    bool checked_out{false};
};

bool isbn_validation(const string& str) {
    if(str.size()<7 || str.size()>13) {     // ISBN's format has a 10 symbols +-3 for dash template
        cerr << "ISBN size is invalid.\n";
        return false;
    }
    int dashes = 0;
    for(size_t i=0; i<str.size(); ++i) {  
        // to count dashes correspond to: n-n-n-x
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

Book::Book(string i, string t, Genre g, string a, int cd) {
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
    set_genre(g);
    set_author(a);
    set_copydate(cd);
}

ostream& operator<<(ostream& os, Book& b) {
    cout << "\n";
    cout << "ISBN: " << b.get_isbn() << "\n";
    cout << "Title: " << b.get_title() << "\n";
    cout << "Genre: " << genre_tbl[(int)b.get_genre()] << "\n";
    cout << "Author: " << b.get_author() << "\n";
    cout << "Copyright: " << b.get_copydate() << "\n";
    cout << "Booked Status: " << ((b.is_checked_out()) ? "Yes" : "No") << "\n";
    cout << "\n";
    return os;
}

bool operator==(const Book& a, const Book& b) {
    return a.get_isbn()==b.get_isbn();
}

bool operator!=(const Book& a, const Book& b) {
    return a.get_isbn()!=b.get_isbn();
}

int main() {
    cout << "Selected genre -> "<< genre_tbl[(int)Genre::children] << "\n";                 // Test Genre
    Book b{"0-3006-4105-X", "Anathomy of Code", Genre::nonfiction, "J.Lourance", 1998};     // GOOD example
    Book d{"0-3006-4105-X", "Anathomy of Code", Genre::nonfiction, "J.Lourance", 1998};     // GOOD example
    Book c{"0-3000006-4105-X", "Anathomy of Code",(Genre)0 ,"J.Lourance", 2045};            // BAD example
    cout << '\n' << b.get_isbn() << " and " << d.get_isbn() << " are same? " << ((b == d) ? "Yes" : "No") << '\n';  // Test overloaded oper.
    cout << "\nPrint GOOD example:" << b;
    cout << "Print BAD example:" << c;
}