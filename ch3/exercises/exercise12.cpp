#include <iostream>
using namespace std;

bool is_prime(int n) {
    for(int i=n-1; i>1;i--){
        if(n%i==0) return false;
    }
    return true;
}

vector<int> primes_range(int range) {
    vector<int> v;
    for(int i=2; i<=range; i++) {
        if(is_prime(i)) v.push_back(i);
    }
    return v;
}

int main() {
    vector<int> v;
    vector<int> primes = {2, 3, 5};

    v = primes_range(100);
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << endl;
    }
    for(int i=0; i<primes.size(); i++) {
        if(v[i]==primes[i]) cout << "Prime " << v[i] << " confirmed." << endl;
    }
    return 0;
}