#include <iostream>
using namespace std;

class Name_value {
    public:
        string name;
        int value;
        Name_value() : name("\0"), value(0) { }
};

int check_name_twice(Name_value entity, vector<Name_value> list) {
    for(Name_value i : list) {
        if(entity.name == i.name) return 1;   // if met twice
    }
    return 0;   // if have no duplicate
}

Name_value find_by_value(vector<Name_value> list) {
    Name_value token;
    cout << "Enter a value to find a name: ";
    int value;
    while(cin >> value) {
        if(!cin) {
            cout << "Not a value. Try again." << endl;
            cin.ignore();
            cin.clear();
            continue;
        }
        for(int i=0; i<list.size(); i++) {
            if(list[i].value==value) return list[i];
        }
    }
    return token;
}

vector<Name_value> list_input() {
    vector<Name_value> result;
    Name_value token;
    while(cin >> token.name >> token.value) {
        if(token.name=="NoName" && token.value==0) break;
        if(check_name_twice(token, result)) {
            cout << "ERROR. Name '" << token.name << "' entered twice. Terminaded." << endl; 
            break;
        }
        result.push_back(token);
    }
    return result;
}

int main() {
    vector<Name_value> list = list_input();
    Name_value found = find_by_value(list);
    if(found.name != "\0") cout << "Was found: " << found.name << " " << found.value << endl;
    else cout << "Value not found." << endl;

    return 0;
}