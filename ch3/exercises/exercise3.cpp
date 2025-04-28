#include <iostream>
using namespace std;

int main () {
    vector<double> temps;
    for(double temp; cin>>temp;) {
        temps.push_back(temp);
        cout << "\nEntered elements: " << temps.size() << endl;
        
        cout << "Sorted sequence: ";
        sort(temps.begin(), temps.end());
        for(double temp : temps) {
            cout << temp << '\t';
        }

        cout << "\nNew median temperature is: ";
        if(temps.size()%2 == 1) cout << temps[temps.size()/2] << endl;
        else cout << (temps[temps.size()/2] + (temps[temps.size()/2-1])) / 2 << endl;
    }
    return 0;
}