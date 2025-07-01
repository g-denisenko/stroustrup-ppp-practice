#include <iostream>
using namespace std;

vector<int> vector_init(int n) {
    vector<int> v;
    for(int i=2; i<=n; i++) {
        v.push_back(i);
    }
    return v;
}

void vector_print(vector<int> v) {
    for(int i : v) {
        cout << i << endl;
    }
}

vector<int> sieve_of_eratosthenes(vector<int> v){
    for(int i=2; i<=v.size(); i++) {
        for(int j=i+i; j<=v.size()+1; j+=i) {
            v[j-2] = 0;
        }
    }
    vector<int> primes;
    for(int i : v) {
        if(i != 0) primes.push_back(i);
    }
    return primes;
}

int main() {
    vector<int> numbers;
    numbers = vector_init(100);

    numbers = sieve_of_eratosthenes(numbers);
    vector_print(numbers);

    return 0;
}