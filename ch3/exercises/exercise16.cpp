#include <iostream>
using namespace std;

int count_repetition(vector<string> series, int n) {
    int repetition = 0;
    for(string i : series) {
        if(i.size() == n) repetition++;
    }
    return repetition;
}

int find_mode(vector<string> series) {
    int mode = series[0].size();
    int repetition = 0;
    for(int i=0; i<series.size(); i++) {
        int tmp = count_repetition(series, series[i].size());
        if(tmp >= repetition) {
            repetition = tmp;
        }
    }
    return repetition;
}

int extremum(vector<string> series, string operation) {
    int result = series[0].size();
    for(int i=0; i<series.size(); i++) {
        int tmp = series[i].size();
        if(operation=="MAX" && result<tmp) result = tmp;
        if(operation=="MIN" && result>tmp) result = tmp;
    }
    return result;
}

int main() {
    vector<string> series = {"bb", "a", "ccc", "ccc", "ccc", "ccc", "ccc", "ccc", "ccc", "ddddd", "ddddd", "ddddd", "ddddd", "eeeeee"};
    for(string i : series) {
        cout << "'" << i << "' - size:" << i.size() << endl;
    }
    cout << endl;

    int series_mode = find_mode(series);
    cout << "The MODE of the series of strings is: " << series_mode << endl;

    int series_min = extremum(series, "MIN");
    cout << "The MIN element of series is: " << series_min << endl;
    
    int series_max = extremum(series, "MAX");
    cout << "The MAX element of series is: " << series_max << endl;

    return 0;
}