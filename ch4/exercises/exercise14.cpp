#include <iostream>
#include <cassert>
#include <climits>
#include <vector>

using namespace std;

const vector<string> day_monday = {"Monday", "Mon", "monday", "mon"};
const vector<string> day_tuesday = {"Tuesday", "Tue", "tuesday", "tue"};
const vector<string> day_wednesday = {"Wednesday", "Wed", "Wwdnesday", "wed"};
const vector<string> day_thursday = {"Thursday", "Thu", "thursday", "thu"};
const vector<string> day_friday = {"Friday", "Fri", "friday", "fri"};
const vector<string> day_saturday = {"Saturday", "Sat", "saturday", "sat"};
const vector<string> day_sunday = {"Sunday", "Sun", "sunday", "sun"};

const vector<int> days_of_week = {1, 2, 3, 4, 5, 6, 7};

int get_day_number(string day) {
    for(int i=0; i<4; i++) {
        if(day_monday[i] == day) return days_of_week[0];
        if(day_tuesday[i] == day) return days_of_week[1];
        if(day_wednesday[i] == day) return days_of_week[2];
        if(day_thursday[i] == day) return days_of_week[3];
        if(day_friday[i] == day) return days_of_week[4];
        if(day_saturday[i] == day) return days_of_week[5];
        if(day_sunday[i] == day) return days_of_week[6];
    }
    return -1;  // Code when day not recognized;
}
string get_day_str(int day) {
    if(day == days_of_week[0]) return day_monday[1];
    if(day == days_of_week[1]) return day_tuesday[1];
    if(day == days_of_week[2]) return day_wednesday[1];
    if(day == days_of_week[3]) return day_thursday[1];
    if(day == days_of_week[4]) return day_friday[1];
    if(day == days_of_week[5]) return day_saturday[1];
    if(day == days_of_week[6]) return day_sunday[1];
    return "not a day";  // Code when day not recognized;
}

bool ask_to_finish() {
    cout << "Do you wanna proceed? (Y/N): " << endl;
    string answer;
    while(true) {
        cin.clear();
        cin.ignore();
        cin >> answer;
        if(answer=="Y" || answer=="y" || answer=="Yes" || answer=="YEs") return true;
        if(answer=="n" || answer=="No" || answer=="NO") return false;
        else {
            cout << "Not an answer.\nPlease, enter 'Y' for play or 'N' for exit." << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
    }
}

vector<int> input_day_score_attempt() {
    vector<int> dict;
    string day;
    int day_number;
    int score;
    int attempt = 0;
    while(true) {
        cin >> day;
        day_number = get_day_number(day);
        if(day_number == -1) {
            cout << "Not a day." << endl;
            cin.clear();
            cin.ignore();
            attempt++;
            continue;
        }
        if(!cin>>score) {
            cout << "Not a score." << endl;
            cin.clear();
            cin.ignore();
            attempt++;
            continue;
        }
        else cin >> score;
        cout << day << " : " << score << " - " << attempt << endl; // DEBUG LINE
        dict.push_back(day_number);
        dict.push_back(score);
        dict.push_back(attempt);
        return dict;
    }
    return {0,0,-1};
}

vector<int> input_loop() {
    vector<int> dict;
    bool flag = true;
    while(flag) {
        cout << "Ented a day(s) and score(s): " << endl;
        vector<int> tmp = input_day_score_attempt();
        for(int i=0; i<tmp.size(); i+=3) {
            dict.push_back(tmp[i]);
            dict.push_back(tmp[i+1]);
            dict.push_back(tmp[i+2]);
        }
        if(cin.peek() == 10) flag = ask_to_finish();
    }
    return dict;
}

void print_dict(vector<int> dict) {
    int attempt = 0;
    for(int i=0; i<dict.size(); i+=3) {
        cout << get_day_str(dict[i]) << "(" << dict[i] << ") - " << dict[i+1] << endl;
        attempt += dict[i+2];
    }
    cout << "Wrong inputs: " << attempt << endl;
}

void print_sum(vector<int> dict) {
    int sum_days = 0;
    int sum_scores = 0;
    for(int i=0; i<dict.size(); i+=3) {
        sum_days += dict[i];
        sum_scores += dict[i+1];
    }
    cout << "Days sum: " << sum_days << endl;
    cout << "Scores sum: " << sum_scores << endl;
}

int main() {
    vector<int> dict = input_loop();
    print_dict(dict);
    print_sum(dict);
    return 0;
}