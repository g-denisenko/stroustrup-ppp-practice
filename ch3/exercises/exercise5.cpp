#include <iostream>
using namespace std;

bool answer(int suggest, int count_tries) {
    cout << "Try No" << count_tries << ". Your thinking number is " << suggest << "?\n(y/n):";

    char answer;
    while(cin>>answer) {
        if(answer=='y' || answer=='Y') {
            cout << "WooHoo! Your thinking number is " << suggest << "\nI used only " << count_tries << " tries."<< endl;
            return true;
        }
        if(answer=='n' || answer=='N') return false;
        else cout << "I dont understand you. Try again.\n";
    }
}

int asking(int suggest, int convergence) {
    cout << "Is thinking number less than " << suggest << "?\n(y/n):";
    char ask;
    while(cin>>ask) {
        if(ask=='y' || ask=='Y') {
            suggest -= convergence/2;
            return suggest;
        }
        if(ask=='n' || ask=='N') {
            suggest += convergence/2;
            return suggest;
        }
        else cout << "I dont understand you. Try again.\n";
    }
}

int play(int suggest, int count_tries, int convergence) {
    count_tries++;
    if(answer(suggest, count_tries)) return 0;
    convergence = convergence/2+convergence%2;
    suggest = asking(suggest, convergence);
    play(suggest, count_tries, convergence);
}

int main() {
    int initial = 50;
    int count_tries = 0;
    int convergence = 100;

    cout << "I will guess your imaginary number between 0 & 100 using 7 tries or less\n" << endl;
    play(initial, count_tries, convergence);

    return 0;
}