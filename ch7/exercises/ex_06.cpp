#include <iostream>
using namespace std;

void print_vector(const vector<string>& v, const string& label) {
    if(!v.size()) { cerr << "Empty vector.\n"; return; }
    cout << label << ": ";
    for(string i : v) cout << i << ' ';
    cout << endl;
}

vector<string> create_reverse_vector(const  vector<string>& v) {
    vector<string> reverse;
    for(int i=v.size()-1; i>=0; --i)
        reverse.push_back(v[i]);
    return reverse;
}

void origin_reverse_vector(vector<string>& v) {
    for(int i=0; i<v.size()/2; ++i) {
        string tmp = v[i];
        v[i] = v[v.size()-1-i];
        v[v.size()-1-i] = tmp;
    }
}

int main() {
    vector<string> vo = {"one", "two", "three"};           // Odd
    vector<string> ve = {"one", "two", "three", "four"};   // Even
    print_vector(vo, "Original Odd");
    print_vector(ve, "Original Even");

    vector<string> ro = create_reverse_vector(vo);
    print_vector(ro, "The reversed copy of origin odd");
    vector<string> re = create_reverse_vector(ve);
    print_vector(re, "The reversed copy of origin even");

    origin_reverse_vector(vo);
    print_vector(vo, "The reversed of origin odd");
    origin_reverse_vector(ve);
    print_vector(ve, "The reversed of origin even");
}