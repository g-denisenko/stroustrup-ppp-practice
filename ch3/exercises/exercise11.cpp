#include <iostream>
using namespace std;

void print_message(vector<string> dict) {
    cout << "In order to play, choice one option. 0 - for exit..." << endl;
    for(int i=0; i<dict.size(); i++) {
        cout << i+1 << '.' << dict[i] << endl;
    }
}

int game_start(int player_choice, vector<string> dict) {
    --player_choice;
    int bot_choice = rand()%3;
    cout << "You: " << dict[player_choice] << endl;
    cout << "Bot: " << dict[bot_choice] << endl;
    if(player_choice == bot_choice) {
        cout << "It's a tie!\n" << endl;
        return 0;
    }
    else if(player_choice==0 && bot_choice==2 || player_choice==1 && bot_choice==0 || player_choice==2 && bot_choice==1) {
        cout << "You win!\n" << endl;
        return 1;
    }
    else {
        cout << "Bot win!\n" << endl;
        return 2;
    }
}
void print_score(int player_score, int bot_score) {
    cout << "Player: " << player_score << '-' << bot_score << " :Bot" << endl;
}

int main() {
    int player_choice;
    int player_score;
    int bot_score;
    int result_flag = -1;
    vector<string> dict = {"Rock", "Paper", "Scissors"};

    print_message(dict);

    while(cin>>player_choice) {
        switch(player_choice) {
            case 0:
                return 0;
            case 1:
                result_flag = game_start(player_choice, dict);
                break;
            case 2:
                result_flag = game_start(player_choice, dict);
                break;
            case 3:
                result_flag = game_start(player_choice, dict);
                break;
            default: cout << "Something went wrong." << endl;
                break;
        }
        if(result_flag == 1) ++player_score;
        else if(result_flag == 2) ++bot_score;
        print_score(player_score, bot_score);
    }
    
    return 0;
}