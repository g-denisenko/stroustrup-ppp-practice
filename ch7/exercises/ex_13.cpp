#include <iostream>
using namespace std;

struct VectorData {
    vector<int> counter;
    string longest;
    string shortest;
    string first;
    string last;
    VectorData(): counter(0), longest(""), shortest(""), first(""), last("") {};

    void print_data(const vector<string>& v);
};

void VectorData::print_data(const vector<string>& v) {
    cout << "Vector Data\n\nOrigin: | ";
    for(string s : v) cout << s << " | ";
    cout << "\nCounting chars: | ";
    for(int i : counter) cout << i << " | ";
    cout << "\nLongest: " << longest << endl;
    cout << "Shortest: " << shortest << endl;
    cout << "lexic. First: " << first << endl;
    cout << "lexic. Last: " << last << endl;
}

vector<int> count_chars(const vector<string>& v) {
    // Counting chars in each string and save result
    vector<int> res(0);
    if(v.empty()) return res;
    for(int i=0; i<v.size(); ++i)
        res.push_back(v[i].size());
    return res;
}

string find_longest(const vector<string>& v) {
    if(v.empty()) return "";
    string res = v[0];
    int res_length = v[0].size();
    for(int i=0; i<v.size(); ++i)
        if(res_length < v[i].size()) {
            res_length = v[i].size();
            res = v[i];
        }
    return res;
}

string find_shortest(const vector<string>& v) {
    if(v.empty()) return "";
    string res = v[0];
    int res_length = v[0].size();
    for(int i=0; i<v.size(); ++i)
        if(res_length > v[i].size()) {
            res_length = v[i].size();
            res = v[i];
        }
    return res;
}

string lexic_first(vector<string> v) {
    sort(v.begin(),v.end());
    return v[0];
}

string lexic_last(vector<string> v) {
    sort(v.begin(),v.end());
    return v[v.size()-1];
}

int main() {
    vector<string> v = {"one","two","three","four","five","another example"};
    vector<string> v2 = {"vf","twso","tasdhree","fosaur","aa","aaavds exdample"};
    VectorData vd;
    vd.counter = count_chars(v);
    vd.longest = find_longest(v);
    vd.shortest = find_shortest(v);
    vd.first = lexic_first(v);
    vd.last = lexic_last(v);
    vd.print_data(v);
}