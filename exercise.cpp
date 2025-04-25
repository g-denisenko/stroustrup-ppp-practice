#include<iostream>
using namespace::std;

int main() {
    vector<string> dict;
    vector<string> disliked {"cake", "juice", "candy"};
    for(string str; cin>>str; )
        dict.push_back(str);

    sort(begin(dict), end(dict));

    for(int i=0; i<dict.size(); i++) {
        for(int j=0; j<disliked.size(); j++) {
            if(disliked[j] == dict[i]) {
                cout << i+1 << ". ***\n";
                ++i;
            }
        }
        cout << i+1 << ". " << dict[i] <<'\n';
    }
    cout << endl;
    return 0;
}