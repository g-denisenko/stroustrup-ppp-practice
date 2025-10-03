#include <iostream>
#include <fstream>
using namespace std;

string get_file_name(string way) {
    cout << "Enter a name of file for " << way << ":\n> ";
    string fname;
    cin >> fname;
    return fname;
}

void produce_lowercase() {
    ifstream ifs{get_file_name("in")};
    if(!ifs)
        cout << "Can't open input -file.\n";
    else cout << "File for reading succeed.\n";

    ofstream ofs{get_file_name("out")};
    if(!ofs)
        cout << "Can't open output -file.\n";
    else cout << "File for writting succeed.\n";

    char ch;
    while(ifs.get(ch)) {
        ofs << (unsigned char)tolower(ch);
        if(ifs.fail())
            cout << "Something wrong.\n";
    }
    if(ifs.eof())
        cout << "Succed. End of file reached.\n";
}

int main() {
    produce_lowercase();
    return 0;
}