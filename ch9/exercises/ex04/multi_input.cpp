#include <iostream>
#include <fstream>
using namespace std;

// Predefined paths for simplisity
const string path_in = "ch9/exercises/ex04/input.txt";
const string path_out = "ch9/exercises/ex04/output.txt";

struct Hex {
    string pref{""};
    string number{""};
    Hex(string s): pref(s), number() {};
};

struct Octo {
    string pref{""};
    string number{""};
    Octo(string s): pref(s), number() {};
};

void get_number() {
    ifstream ifs{path_in};
    if(!ifs)
        cerr << "Can't open file to read.\n";
    else cout << "File to read opened succesfully.\n" << path_in << endl;
    ofstream ofs{path_out};
    if(!ofs)
        cerr << "Can't open file to white.\n";
    else cout << "File to write opened succesfully.\n" << path_out << endl;
    
    while(ifs) {
        try {
            // Below is just a draft of solution
            // Still not complited yet (under development)

            char c1, c2;
            Hex h{"0x"};
            Octo o{"0o"};
            int i{0};
            ifs >> c1 >> c2;
            if(c1==h.pref[0] && c2==h.pref[1]) {
                for(char c; ifs.get(c); ) {
                    if(isdigit(c) || (tolower(c)>='a' && tolower(c)<='f'))
                        h.number += c;
                    else break;
                }
                ofs << "HEX: " << h.number << endl;
            }
            if(c1==o.pref[0] && c2==o.pref[1]) {
                for(char c; ifs.get(c); ) {
                    if(isdigit(c) && c>='0' && c<='7')
                        o.number += c;
                    else break;
                }
                ofs << "OCT: " << o.number << endl;
            }
            if(isdigit(c1) && c1!='0') {
                for(char c; ifs.get(c); ) {
                    if(isdigit(c))
                        i = i*10 +(c-'0');
                    else break;
                }
                ofs << "DEC: " << i << endl;
            }

        }
        catch(...) {
            cerr << "cannot recognize input.\n";
        }
    }
    if(ifs.eof())
        cout << "\nEnd of file reached. Success\n" ;
    return;
}

int main(){
    get_number();
    return 0;
}