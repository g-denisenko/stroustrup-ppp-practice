#include <iostream>
using namespace std;

int check_name_twice(string name, vector<string> names) {
    for(string i : names) {
        if(i==name) return 1;
    }
    return 0;
}

int find_score(string name, vector<string> names, vector<int> scores) {
    for(int i=0; i<names.size(); i++) {
        if(names[i]==name) return scores[i];
    }
    return -1;
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

    cout << "Enter a name to check corresponding score: " << endl;
    cin >> name;
    score = find_score(name, names, scores);
    if(score != -1) cout << name << " " << score << endl;
    else cout << "Name not found." << endl;

    return 0;
}