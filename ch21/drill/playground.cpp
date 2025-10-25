#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
using namespace std;

struct Record {
    double unit_price;
    int units;
    Record(double d, int i) : unit_price{d}, units{i} {};
};

ostream& operator<<(ostream& os, const Record& r) {
    return os   << "Price: " << r.unit_price
                << "\tSales: " << r.units
                << endl;
}

double cost(double v, Record& r) { return v + r.unit_price * r.units; }

bool odd(int& x) { return x%2; }
bool great_then(int& x, int& y) { return x>y; }

template<typename T>
void print(const vector<T>& v) {
    for(T t: v) cout << t << " ";
    cout << endl;
}

int main() {
    vector<int> s(10);
    iota(s.begin(), s.end(), 1);
    vector<int> s2(10);
    iota(s2.begin(), s2.end(), 12);
    print(s2);
    
    auto pb = find(s.begin(), s.end(), 5);
    cout << "Before shuffle(): " << *pb << " was found in " << &pb << endl;

    shuffle(
        s.begin(),
        s.end(),
        std::mt19937{std::random_device{}()}
    );

    auto pa = find(s.begin(), s.end(), 5);
    cout << "After shuffle(): " << *pa << " was found in " << &pa << endl;

    if (pb == pa) {
        cout << "Values 'pa' & 'pb' still same" << endl;
    } else {
        cout << "Values 'pa' & 'pb' differ" << endl;
        cout << &(*pb) << " " << &(*pa) << endl;
    }
    print(s);
    
    vector<int>::iterator fi = find_if(s.begin(), s.end(), odd);
    cout << "First odd after shuffle(): " << *fi << endl;

    cout << "Sort with function obj (great_then): "<< endl;
    sort(s.begin(), s.end(), great_then);
    print(s);
    
    cout << "Sort with Lambda function (x<y): "<< endl;
    sort(s.begin(), s.end(), [](auto x,auto y){ return x<y; });
    print(s);

    auto x = accumulate(s.begin(), s.end(), 0);
    cout << "Accumulate() of vector 's': " << x << endl;

    auto xm = accumulate(s.begin(), s.end(), 1, multiplies<int>());
    cout << "Accumulate() with multi of vector 's': " << xm << endl;

    vector<Record> vr {
        {1.1, 4},
        {2.2, 12},
        {1.8, 2},
        {5.3, 8}
    };

    cout << "Show vector of records: \n";
    print(vr);
    auto vra = accumulate(vr.begin(), vr.end(), 0.0, cost);
    cout << "Accumuladed cost of Records: " << vra << "\n" << endl;

    print(s);
    print(s2);
    
    auto ip = inner_product(s.begin(), s.end(), s2.begin(), 0);
    cout << "Inner product of two vectors: " << ip << endl;

    vector<int> sc(10);
    cout << "Copy_if() x>15 from 's2' items to 'sc' vector: \n";
    copy_if(s2.begin(), s2.end(), sc.begin(), [](int x){return x>15;});
    print(sc);

    return 0;
}