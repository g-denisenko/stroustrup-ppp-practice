#include <iostream>
using namespace std;

int count_repetition(vector<int> series, int n) {
    int repetition = 0;
    for(int i : series) {
        if(i == n) repetition++;
    }
    return repetition;
}

int find_mode_positive(vector<int> series) {
    int mode = series[0];
    int repetition_larger = 0;
    for(int i=0; i<series.size(); i++) {
        int tmp = count_repetition(series, series[i]);
        if( tmp>=repetition_larger && series[i]>0) {
            repetition_larger = tmp;
            mode = series[i];
        }
    }
    if(mode > 0) return mode;
    else return -1;
}

int main() {
    vector<int> series = {6, -2, -2, -2, 0, 1, 1, 1, -2, -2, 3,};

    int pos_mod = find_mode_positive(series);
    if(pos_mod > 0) cout << "The POSITIVE mode of series is: " << pos_mod << endl;
    else cout << "POSITIVE mode of series not found." << endl;

    return 0;
}