#include <iostream>
using namespace std;

bool is_prime(int n) {
    for(int i=2; i<n; i++) {
        if(n%i==0) return false;
    }
    return true;
}

vector<int> finds_n_primes(int n) {
    vector<int> primes;
    int counter_primes = 0;
    for(int i=2; counter_primes<n; i++){
        if(is_prime(i)) {
            primes.push_back(i);
            counter_primes++;
        }
    }
    return primes;
}

int main() {
    vector<int> n_primes;
    n_primes = finds_n_primes(1024);

    for(int i=0; i<n_primes.size(); i++) {
        cout << i+1 << ". " << n_primes[i] << endl;
    }
    
    return 0;
}