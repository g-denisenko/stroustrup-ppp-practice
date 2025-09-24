#include <iostream>
using namespace std;

void print_vector(const vector<int>& v, const string& label) {
    if(!v.size()) { cerr << "Empty vector.\n"; return; }
    cout << label << ": ";
    for(int i : v) cout << i << ' ';
    cout << endl;
}

vector<int> create_reverse_vector(const  vector<int>& v) {
    vector<int> reverse;
    for(int i=v.size()-1; i>=0; --i)
        reverse.push_back(v[i]);
    return reverse;
}

void origin_reverse_vector(vector<int>& v) {
    for(int i=0; i<v.size()/2; ++i) {
        int tmp = v[i];
        v[i] = v[v.size()-1-i];
        v[v.size()-1-i] = tmp;
    }
}

int main() {
    vector<int> vo = {1,2,3,4,5};    // Odd
    vector<int> ve = {1,2,3,4,5,6};  // Even
    print_vector(vo, "Original Odd");
    print_vector(ve, "Original Even");

    vector<int> ro = create_reverse_vector(vo);
    print_vector(ro, "The reversed copy of origin odd");
    vector<int> re = create_reverse_vector(ve);
    print_vector(re, "The reversed copy of origin even");

    origin_reverse_vector(vo);
    print_vector(vo, "The reversed of origin odd");
    origin_reverse_vector(ve);
    print_vector(ve, "The reversed of origin even");
}