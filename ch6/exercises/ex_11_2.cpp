/*
CHAPTER 3 : Exercise 11
-------------------------------------------------------------
Re-write a program that plays the game “Rock, Paper, Scissors.”
-------------------------------------------------------------
*/

#include <iostream>
#include <map>
#include <stdexcept>
#include <random>

using namespace std;

const map<int, string> table = {
    {1, "Rock"},
    {2, "Paper"},
    {3, "Scissors"}
};

constexpr char symbol_player = 'p';
constexpr char symbol_bot = 'b';
constexpr char symbol_draw = 'd';
constexpr char symbol_yes = 'y';
constexpr char symbol_no = 'n';
constexpr char symbol_error = 'e';
const string auto_choice = "auto";
const string manual_choice = "manual";
const string help = "1. Rock\n2. Peper\n3. Scissors\n";

int user_choice() {
    cout << "\nEnter a choice (1,2 or 3)\n" << help << "> ";
    string s;
    while(cin>>s) {
        try {
            int i = stoi(s);
            if(!i || i<1 || i>3)
                throw runtime_error("Bad choice");
            else return i;
        }
        catch(exception& e) {
            cerr << "Bad choice. Try again." << endl;
        }
        catch(...) {
        }
        cout << help << "> ";
    }
}

string ask_confirmation() {
    string s;
    char c;
    // Compiling user input from cin.
    while(true) {
        cin.get(c);
        if(isalpha(c))
            s += c;
        if(c=='\n' || c=='\0' || c==' ') break;
    }
    return s;
}

const vector<string> dict_answer_yes = {"Y", "y", "Yes", "yes", "YES"};
const vector<string> dict_answer_no = {"N", "n", "No", "no", "NO"};

char is_exit() {
    while(true) {
        string s = ask_confirmation();
        // Check if compiled answer in dict's
        for(string answer : dict_answer_yes) {
            if(answer == s)
                return symbol_yes;
        }
        for(string answer : dict_answer_no) {
            if(answer == s)
                return symbol_no;
        }
    }
    return symbol_error;
}

class Gamer {
    public:
    string name;
    int score;
    int choice;
    map<int, string> table;

    Gamer(string s, map<int, string> t)
        :name(s), score(0), choice(0), table(t) { };
        
    int make_choice(string type);
};

int random_int() {
    random_device rd;   // a seed source for the random number engine
    mt19937 gen(rd());  // mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(1, 3);
    return distrib(gen);
}

int Gamer::make_choice(string type) {
    if(type == auto_choice)
        return random_int();
    if(type == manual_choice)
        return user_choice();
    else return -1;             // Error code
}

Gamer bot("Bot", table);
Gamer player("Player", table);

char winner_logic(int p, int b) {
    //  Uses choices of both player & bot for evaluation
    //  Return sign of winner or draw when choices are equal
    //  1.Rock - 2.Paper - 3.Scissors
    switch(p) {
        case 1:
            if(b == 2) { bot.score++; return symbol_bot; }
            if(b == 3) { player.score++; return symbol_player; }
            return symbol_draw;
        case 2:
            if(b == 3) { bot.score++; return symbol_bot; }
            if(b == 1) { player.score++; return symbol_player; }
            return symbol_draw;
        case 3:
            if(b == 1) { bot.score++; return symbol_bot; }
            if(b == 2) { player.score++; return symbol_player; }
            return symbol_draw;
        default:
            return symbol_error; // sign for error
    }
}

void print_game_stats() {
    cout << "\n____ GAME SCORE ____\n";
    cout << player.name << " : " << player.score << " - " << bot.score << " : " << bot.name << endl; 
    cout << "\n" << endl;
}

void print_gamers_choices() {
    cout << endl;
    cout << player.name << " : " << table.at(player.choice) << endl;
    cout << bot.name << " : " << table.at(bot.choice) << endl;
}

int game_loop() {
    player.choice = player.make_choice(manual_choice);
    bot.choice = bot.make_choice(auto_choice);
    print_gamers_choices();

    char winner = winner_logic(player.choice, bot.choice);
    switch(winner) {
        case symbol_player:
            cout << player.name << " won." << endl;
            break;
        case symbol_bot:
            cout << bot.name << " won." << endl;
            break;
        case symbol_draw:
            cout << "It's a draw." << endl;
            break;
        case symbol_error:
            cerr << "error with winner_logic()" << endl;
        default:
            cerr << "Something went wrong..." << endl;
    }
    print_game_stats();
    return 1;   // sign all is going well
}

int game() {
    int count = 0;
    cout << "The Game 'Rock.Paper.Scissors'" <<endl;
    while(true) {
        if(game_loop())
            count++;
        cout << "Do you wanna proceed? (Y/N)" << endl;
        if(is_exit() == symbol_no)
            break; 
    }
    cout << "Game exit.\nTimes played: " << count << endl;
    return count;
}

int main() {
    game();
}