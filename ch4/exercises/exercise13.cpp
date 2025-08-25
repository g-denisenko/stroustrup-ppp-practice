#include <iostream>
#include <cassert>
#include <climits>
#include <random>

using namespace std;

bool check_digit_repetition(vector<int> n) {
    assert(n.size()==4 && "Not a 4-digit number. ERROR");

    for(int i=0; i<n.size(); i++) {
        for(int j=0; j<n.size(); j++) {
            if(i!=j && n[i]==n[j]) return true;
        }
    }
    return false;
}

vector<int> user_guess() {
    cout << "Enter an 4-digit integer: " << endl;
    int n = 0;
    while(true) {
        cin >> n;
        if(!cin) {
            cout << "Not an integer. Please, try again" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }

        assert(n<INT_MAX && "OUT OF RANGE of maximum");

        if(n>9999) {
            cout << "Not a 4-digit integer. Please, try again." << endl;
            continue;
        }

        if(n<1000) {
            cout << "Not a 4-digit integer (or started from '0' -zero). Please, try again." << endl;
            continue;
        }

        vector<int> result;
        result.push_back((n%10000)/1000);
        result.push_back((n%1000)/100);
        result.push_back((n%100)/10);
        result.push_back((n%10)/1);

        if(check_digit_repetition(result)) {
            cout << "Duplicate digit was found. Please, try again." << endl;
            continue;
        }

        // cout << "User input confirmed as: " << n << endl;
        return result;
    }
}

bool ask_play_again() {
    cout << "Are you wanna play again? (Y/N): " << endl;
    string answer = "\0";
    while(true) {
        cin >> answer;
        if(answer=="Y" || answer=="y" || answer=="Yes" || answer=="YEs") return false;
        if(answer=="n" || answer=="No" || answer=="NO") return true;
        else {
            cout << "Not an answer.\nPlease, enter 'Y' for play or 'N' for exit." << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
    }
}

int random_int() {
    random_device rd;  // a seed source for the random number engine
    mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(0, 9);
    int n = distrib(gen);
    return n;
}

vector<int> secret_num() {
    vector<int> result;
    bool a, b, c, d, e, f, g, h, i, j;
    a = b = c = d = e = f = g = h = i = j = false;  // Flag for repeated digit encounter
    for(int item=0; item<4; item++) {
        int rand = random_int();
        if(rand==0 && !a && i!=0) {a=true; result.push_back(0); continue;}
        if(rand==1 && !b) {b=true; result.push_back(1); continue;}
        if(rand==2 && !c) {c=true; result.push_back(2); continue;}
        if(rand==3 && !d) {d=true; result.push_back(3); continue;}
        if(rand==4 && !e) {e=true; result.push_back(4); continue;}
        if(rand==5 && !f) {f=true; result.push_back(5); continue;}
        if(rand==6 && !g) {g=true; result.push_back(6); continue;}
        if(rand==7 && !h) {h=true; result.push_back(7); continue;}
        if(rand==8 && !i) {i=true; result.push_back(8); continue;}
        if(rand==9 && !j) {j=true; result.push_back(9); continue;}
        item--; // In case if no digit added for 4-digit number
    }
    assert(!check_digit_repetition(result) && "Wrong secret 4-digit number. Was generated number with digit repetition.");
    return result;
}

void print_vector_ints(vector<int> v) {
    for(int i=0; i<v.size(); i++) {
        cout << v[i];
    }
}

int how_many_cows(vector<int> guess, vector<int> secret) {
    int cows = 0;
    for(int i=0; i<secret.size(); i++) {
        for(int j=0; j<guess.size(); j++) {
            if(guess[j]==secret[i] && guess[j]!=secret[j]) cows++;
        }
    }
    return cows;
}

int how_many_bulls(vector<int> guess, vector<int> secret) {
    int bulls = 0;
    for(int i=0; i<secret.size(); i++) {
        if(guess[i]==secret[i]) bulls++;
    }
    return bulls;
}

bool game_cycle(vector<int> guess, vector<int> secret, int cycle_counter) {
    int bulls = how_many_bulls(guess, secret);
    int cows = how_many_cows(guess, secret);
    if(bulls == 4) return false;
    cout << "\nCycle #" << cycle_counter << endl;
    cout << "User guess: ";
    print_vector_ints(guess);
    cout << endl;
    cout << "Bulls: " << bulls << endl;
    cout << "Cows: " << cows << endl;
    return true;
}

bool game() {
    vector<int> secret = secret_num();
    int cycle_counter = 1;

    // print_vector_ints(secret);   // Show SECRET number
    cout << endl;

    while(true) {
        vector<int> guess = user_guess();
        if(!game_cycle(guess, secret, cycle_counter)) {
            cout << "Congrats!\nYou found all bulls.\nSecret number is: ";
            print_vector_ints(secret);
            cout << "\nAttempts: " << cycle_counter << endl;
            return false;
        }
        cycle_counter++;
        cout << "___\n\n";
    }
}

void play_game() {
    bool play_again = false;
    while(!play_again) {
        cout << "\nNew Game Started!" << endl;
        if(!game()) {
            play_again = ask_play_again();
            continue;
        }
    }
}

int main() {
    play_game();
    return 0;
}