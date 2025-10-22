#include <iostream>
#include <map>
#include <unordered_map>
#include <chrono>
#include <algorithm>
#include <random>
#include <set>

using namespace std;
using namespace chrono;

int main() {

    vector<pair<string,int>> v(1'000'000);
    generate(v.begin(), v.end(), [i = 0]() mutable { 
        return make_pair("Item_" + to_string(i++), rand() % 100); 
    });
    string x = v[v.size()/2].first;

    auto t0 = system_clock::now();
    auto pv = std::find_if(v.begin(), v.end(), [&x](const auto& s) { return s.first == x; });
    auto t1 = system_clock::now();
    cout << "vector: " << pv->second << '\n';
    cout << duration_cast<microseconds>(t1-t0).count() << "us\n\n";

    map<string, int> m {v.begin(), v.end()};
    auto t2 = system_clock::now();
    auto vm = m[x];
    auto t3 = system_clock::now();
    cout << "map[]: " << vm << '\n';
    cout << duration_cast<microseconds>(t3-t2).count() << "us\n\n";

    auto t22 = system_clock::now();
    auto pm = std::find_if(m.begin(), m.end(), [&x](const auto& s) { return s.first == x; }); 
    auto t32 = system_clock::now();
    cout << "map find_if: " << pm->second << '\n';
    cout << duration_cast<microseconds>(t32-t22).count() << "us\n";
}