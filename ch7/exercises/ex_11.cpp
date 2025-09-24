#include <iostream>
using namespace std;

struct VectorInfo {
    double median;
    int max;
    int min;
    VectorInfo() :median(0), max(0), min(0) { };
};

void vector_analize(vector<int> v, VectorInfo& obj)
{   // return max element of a given vector
    if(v.empty()) return;   // left function if empty
    obj.max = v[0];
    obj.min = v[0];
    for(int i : v) {
        if(i > obj.max)
            obj.max = i;
        if(i < obj.min)
            obj.min = i;
    }
    sort(v.begin(), v.end());
    if(v.size()%2 == 1) obj.median = (double)v[v.size()/2];
    if(v.size()%2 == 0) obj.median = (double)(v[(v.size()/2)-1] +v[(v.size()/2)])/2;
}

int main() {
    vector<int> v1 = {12,14,2,46,8,5};
    vector<int> v2 = {0,5,-1,1};
    vector<int> v3(0);

    VectorInfo obj1;
    vector_analize(v1, obj1);

    VectorInfo obj2;
    vector_analize(v2, obj2);

    VectorInfo obj3;
    vector_analize(v3, obj3);

    cout << "{12,14,2,46,8,5}\nMax: " << obj1.max << " min: " << obj1.min << " median: " << obj1.median << endl;
    cout << "{0,5,-1,1}\nMax: " << obj2.max << " min: " << obj2.min << " median: " << obj2.median << endl;
    cout << "(0)\nMax: " << obj3.max << " min: " << obj3.min << " median: " << obj3.median << endl;
}