#include <iostream>
#include <fstream>
using namespace std;

// Predefined paths for simplisity
const string path_in = "ch9/exercises/ex06/input.txt";
const string path_out = "ch9/exercises/ex06/output.txt";

const vector<char> symbols_tbl = {'.', ';', ',', '?', '-', '\''};


void get_number() {
    ifstream ifs{path_in};
    if(!ifs)
        cerr << "Can't open file to read.\n";
    else cout << "File to read opened succesfully.\n" << path_in << endl;
    ofstream ofs{path_out};
    if(!ofs)
        cerr << "Can't open file to white.\n";
    else cout << "File to write opened succesfully.\n" << path_out << endl;

    for(char c;ifs;) {
        char spec;
        spec = ifs.peek();
        if(spec=='\n')
            c = '\n';
        ifs.get(c);
        for(char x : symbols_tbl)
            (c==x || isspace(c)) ? c=' ' : c;
        ofs << c;
    }
    if(ifs.eof())
        cout << "\nEnd of file reached. Success\n" ;
    return;
}

int main(){
    get_number();
    return 0;
}