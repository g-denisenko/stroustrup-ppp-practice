#include <iostream>
#include <map>
using namespace std;

class Name_pair{
    public:
    Name_pair() : name(0), age(0) { };

    void read_names();
    void read_ages();       // (!) rewrites current ages
    void print() const;
    void sort();

    private:
    vector<string> name;
    vector<double> age;

    double get_double();    // Helper for read_ages()
};

void Name_pair::sort() {
    // simple check for equal size
    if(name.size()!=age.size()) {
        cerr << "name's and age's are differ. can't sort()\n";
        return;
    }

    // create map to sort names and keep indexes
    map<string,int> name_tbl;
    for(size_t i=0; i<name.size(); ++i) {
        name_tbl.emplace(name[i], age[i]);
    }

    // apply changes for origin name and age
    int iter = 0;
    for(auto pair : name_tbl) {
        name[iter] = pair.first;
        age[iter] = pair.second;
        ++iter;
    }
}

void Name_pair::print() const {
    if(name.size() != age.size())
        cerr << "sizes of names & ages are differ.\n";
    for(int i=0; i<name.size(); ++i) {
        cout << name[i] << ": ";
        if(!age[i])
            cout << "No age" << endl;
        else
            cout << age[i] << endl;
    }
}

void Name_pair::read_names() {
    cout << "Enter a name (empty line for exit)\n";
    while(true) {
        cout << "> ";
        string str{""};
        getline(cin, str);
        if(str=="" || str=="\0" || str=="\n" || str=="exit" || str=="stop")
            return;
        else name.push_back(str);
    }
}

double Name_pair::get_double() {
    while(true) {
        string s{""};
        cin >> s;
        double d{0};
        try {
            d = stod(s);
            return d;
        }
        catch(...) {
            cin.clear();
            cin.ignore();
            return -1;  // error code
        }
    }
}

void Name_pair::read_ages() {
    cout << "Enter an age for names\n";
    int iter = 0;
    age.clear(); // re-writing here
    while(iter<name.size()) {
        cout << name[iter] <<": ";
        double d = get_double();
        if(d <= 0) {
            cerr << "wrong input. try again.\n";
            continue;
        }
        age.push_back(d);
        ++iter;
    }
}

int main() {
    Name_pair np;
    np.read_names();
    np.read_ages();
    cout << "Before Sort()\n";
    np.print();
    np.sort();
    cout << "After Sort()\n";
    np.print();
    return 0;
}