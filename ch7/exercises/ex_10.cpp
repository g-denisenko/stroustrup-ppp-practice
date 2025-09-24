#include <iostream>
using namespace std;

int maxv(const vector<int>& v)
{   // return max element of a given vector
    if(!v.size()) { cout << "vector<int> is empty. "; return 0; }
    int max = v[0];
    for(int i : v) 
        if(i > max)
            max = i;
    return max;
}

int main() {
    vector<int> v1 = {12,14,2,46,8,5};
    vector<int> v2 = {0,5,-1,1};
    vector<int> v3(0);

    cout << "Vector {12,14,2,46,8,5}: " << maxv(v1) << endl;
    cout << "Vector {0,5,-1,1}: " <<maxv(v2) << endl;
    cout << "Vector (0): " << maxv(v3) << endl;
}