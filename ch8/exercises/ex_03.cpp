#include <iostream>
#include <map>
using namespace std;

class Name_pair{
    public:
    Name_pair() : name(0), age(0) { };

    void read_names();
    void read_ages();       // (!) rewrites current ages
    void sort();
    vector<string> get_name() const { return name; }
    vector<double> get_age() const { return age; }

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

ostream& operator<<(ostream& os, const Name_pair& np) {
    for(size_t i=0; i<np.get_name().size(); ++i) {
        cout << np.get_name()[i] << " -> " << np.get_age()[i] << endl;
    }
    return os;
}

bool operator==(const Name_pair& obj_1, const Name_pair& obj_2) {
    for(size_t i=0; i<obj_1.get_name().size(); ++i) {
        if(obj_1.get_name()[i]!=obj_2.get_name()[i] || obj_1.get_age()[i]!=obj_2.get_age()[i])
            return false;
    }
    return true;
}

bool operator!=(const Name_pair& obj_1, const Name_pair& obj_2) {
    for(size_t i=0; i<obj_1.get_name().size(); ++i) {
        if(obj_1.get_name()[i]!=obj_2.get_name()[i] || obj_1.get_age()[i]!=obj_2.get_age()[i])
            return true;
    }
    return false;
}

void Name_pair::read_names() {
    cout << "Enter a name ('e' or 'q' line for exit)\n";
    while(true) {
        cout << "> ";
        string str{""};
        cin >> str;
        if(str=="q" || str=="e")
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
    Name_pair np;           // use default constructor
    np.read_names();        // use read_names() member
    np.read_ages();         // use read_ages() member

    Name_pair other;        // create another obj of Name_pair
    other.read_names();
    other.read_ages();

    np.sort();              // use sort() member
    other.sort();
    cout << "Pairs one:\n" << np << endl;
    cout << "Pairs two:\n" << other << endl;                // use overloaded <<
    if(np == other) cout << "Pairs sets are equal.\n";      // use overloaded ==
    if(np != other) cout << "Pairs sets are differ.\n";     // use overloaded !=
    return 0;
}