#include <iostream>
using namespace std;

int check_name_twice(string name, vector<string> names) {
    for(string i : names) {
        if(i==name) return 1;
    }
    return 0;
}

int main() {
    vector<string> names;
    vector<int> scores;

    string name;
    int score;

    while(cin >> name >> score) {
        if(name=="NoName" && score==0) break;
        if(check_name_twice(name, names)) {
            cout << "ERROR. Name '" << name << "' entered twice. Terminaded." << endl; 
            break;
        }
        names.push_back(name);
        scores.push_back(score);
    }

    for(int i=0; i<names.size(); i++) {
        cout << names[i] << ' ' << scores[i] << endl;
    }

    return 0;
}