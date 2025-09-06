#include <iostream>
#include <random>

using namespace std;

char random_char() {
    random_device rd;   // a seed source for the random number engine
    mt19937 gen(rd());  // mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(65, 90);
    char n = distrib(gen);
    return n;
}

bool check_duplication(string s) {
    for(int i=0; i<s.size(); i++) {
        for(int j=0; j<s.size(); j++) {
            if(i!=j && s[i]==s[j]) return true;
        }
    }
    return false;
}

bool check_letter_caps(string s) {

    for(int i=0; i<s.size(); i++) {
        if(s[i]<'A' || s[i]>'Z') return true;
    }
    return false;
}

string word_generation() {
    string word;
    while(true) {
        for(int i=0; i<4; i++) {
            word.push_back(random_char());
        }
        if(!check_duplication(word))
            break;
    }
    return word;
}

string user_guess() {
    cout << "Enter 4 various lettes (from A to Z):\n> ";
    string s;
    while(cin>>s) {
        if(s.size()!=4) {
            cout << "Not a 4 letters entered. Try again." << endl;
            cin.ignore();
            cin.clear();
            continue;
        }
        if(check_duplication(s)) {
            cout << "Letters are duplicated. Try again." << endl;
            cin.ignore();
            cin.clear();
            continue;
        }
        if(check_letter_caps(s)) {
            cout << "Lowercase letter or other symbol was found. Try again." << endl;
            cin.ignore();
            cin.clear();
            continue;
        }
        break;
    }
    return s;
}

int bulls(string g, string s) {
    int bulls = 0;
    for(int i=0; i<g.size(); i++) {
        for(int j=0; j<g.size(); j++) {
            if(i==j && s[i]==g[i]) bulls++;
        }
    }
    return bulls;
}

int cows(string g, string s) {
    int cows = 0;
    for(int i=0; i<g.size(); i++) {
        for(int j=0; j<g.size(); j++) {
            if(i!=j && s[i]==g[j]) cows++;
        }
    }
    return cows;
}

vector<int> game_cycle(string g, string s) {
    vector<int> v;
    v.push_back(bulls(g,s));
    v.push_back(cows(g,s));
    return v;
}

int game_play() {
    string secret = word_generation();
    // cout << "Debug Line: " << secret << endl;
    int attempt = 1;
    while(true) {
        string guess = user_guess();
        vector<int> result = game_cycle(guess, secret);
        if(result[0] == guess.size()) {    // If true - the game is end.
            cout << "You won! The secret word is: " << secret << endl;
            cout << "Attempts: " << attempt << endl; 
            break;
        }
        cout << "\nBulls: " << result[0] << "\nCows: " << result[1] << endl;
        attempt++;
    }
    return 0;   // Code all is going well
}

int main() {
    int code = game_play();
    return code;
}