#include <iostream>
#include <fstream>
using namespace std;

const string path_in = "ch9/exercises/ex03/input.txt";
const string path_out = "ch9/exercises/ex03/output.txt";

const vector<char> vowel_tbl_eng = {'e', 'y', 'u', 'i', 'o', 'a'};

char vowel_detect(const vector<char>& vowel_tbl_eng, char& ch) {
    for(char x : vowel_tbl_eng) {
        if(x==tolower(ch))
            return '\0';
    }
    return ch;
}

void vowel_delete() {
    ifstream ifs{path_in};
    if(!ifs)
        cerr << "Can't open file to read.\n";
    else cout << "File to read opened succesfully.\n" << path_in << endl;
    ofstream ofs{path_out};
    if(!ofs)
        cerr << "Can't open file to white.\n";
    else cout << "File to write opened succesfully.\n" << path_out << endl;
    
    int iter{0};
    for(char ch; ifs.get(ch);) {
        if(vowel_detect(vowel_tbl_eng, ch)=='\0') {
            ++iter;
            ofs << "";
        }
        else ofs << ch;
    }
    if(ifs.eof())
        cout << "\nEnd of file reached. Success\n" << iter << " vowels deleted.\n" ;
    return;
}

int main(){
    vowel_delete();
    return 0;
}