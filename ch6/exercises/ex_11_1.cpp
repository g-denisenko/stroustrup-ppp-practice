/*
CHAPTER 3 : Exercise 5
----------------------------------------------------------------------------
Write a program to play a numbers guessing game.
The user thinks of a number between 1 and 100
and your program asks questions to figure out
what the number is (e.g., “Is the number you are thinking of less than 50?”).
Your program should be able to identify
the number after asking no more than seven questions.
----------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

const vector<string> dict_answer_yes = {"Y", "y", "Yes", "yes", "YES"};
const vector<string> dict_answer_no = {"N", "n", "No", "no", "NO"};

bool user_input() {
    string s;
    char c;
    // Compiling user input from cin.
    while(true) {
        cin.get(c);
        if(isalpha(c))
            s += c;
        else break;
    }
    // Check if compiled answer recognized as Yes.
    for(string answer : dict_answer_yes) {
        if(answer == s)
            return true;
    }
    // Check if compiled answer recognized as No.
    for(string answer : dict_answer_no) {
        if(answer == s)
            return false;
    }
    // If no proper answer, ask user again.
    return user_input();
}

int low = 1;
int high = 100;

bool ask_user(int guess) {
    guess = (low+high)/2;
    cout << "The guessing number is less than " << guess << " ?\n> ";
    return user_input();
}

int guess_answer(int guess) {
    if(ask_user(guess)) {
        high = guess;
        guess = (low+high)/2;
    }
    else {
        low = guess;
        guess = (low+high)/2;
    }
    return guess;
}

bool check_answer(int guess) {
    cout << "Is guessing number: " << guess << " ?\n> ";
    return user_input();
}

void game() {
    int attempt = 0;
    int guess = 50;
    while(true) {
        attempt++;
        guess = guess_answer(guess);
        if(check_answer(guess))
            break;
    }
    cout << "Guessign number: " << guess << endl;
    cout << "Attempts: " << attempt << endl;
}

int main() {
    game();
    return 0;
}