#include <iostream>
using namespace std;

int check_name_twice(string name, vector<string> names) {
    for(string i : names) {
        if(i==name) return 1;
    }
    return 0;
}

string find_name(int score, vector<string> names, vector<int> scores) {
    for(int i=0; i<scores.size(); i++) {
        if(scores[i]==score) return names[i];
    }
    return "\0";
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

    cout << "Enter a score to check corresponding name: " << endl;
    cin >> score;
    name = find_name(score, names, scores);
    if(name != "\0") cout << name << " " << score << endl;
    else cout << "Score not found." << endl;

    return 0;
}