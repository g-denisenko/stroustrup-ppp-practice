#include <iostream>
#include <sstream>
#include <climits>
#include <cassert>
using namespace std;

int user_num() {
    cout << "Enter an integer for the first N numbers: " << endl;
    int n;
    while(true) {
        cin >> n;
        if(!cin) {
            cout << "Not an integer.\nPlease, try again" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }

        assert(n<INT_MAX && "OUT OF RANGE of maximum");

        if(n < 0) {
            cout << "N items cannot be negative.\nPlease, enter a positive number." << endl;
            continue;
        }
        if(n == 0) {
            cout << "You're entered 0(zero).\nPlease, enter a positive number." << endl;
            continue;
        }
        return n;
    }
}

vector<int> user_sequence() {
    cout << "Enter a sequence of integers. Use '|' for end: " << endl;
    vector<int> sequence;
    char stop;  // 124 for '|'-shymbol stop
    while(stop!='|') {
        int n;
        cin >> n;
        if(!cin) {
            cin.clear();
            if(cin.peek()=='|') {
                stop = '|';
                cout << "STOP symbol was meet." << endl;
                break;
            }
            cin.ignore();
            continue;
        }
        else sequence.push_back(n);
    }
    return sequence;
}

void print_sequence(vector<int> sequence) {
    if(sequence.size()>0) {
        cout << "The sequence: " << endl;
        for(int i=0; i<sequence.size(); i++) {
            cout << sequence[i] << endl;
        }
    }
    else cout << "Sequence is empty." << endl;
}

void assert_check_range_sum(int a, int b) {
    assert(a+b<INT_MAX && "OUT OF RANGE of maximum");
    assert(a+b>INT_MIN && "OUT OF RANGE of minimum"); 
}

void print_sum(int n, vector<int> sequence) {
    int sum = 0;
    if(sequence.size() < n) {
        cout << "Sequence of ints is less than asked " << n << " elements.\nSum for all elements of sequence:";

        for(int i=0; i<sequence.size(); i++) {
            assert_check_range_sum(sum, sequence[i]);
            sum+=sequence[i];
        }
    }
    else { 
        cout << "Sum for " << n << " first numbers:";
        for(int i=0; i<n; i++) {
            assert_check_range_sum(sum, sequence[i]);
            sum+=sequence[i];
        }
    }
    cout << sum << endl;
}

int main() {
    int count = user_num();
    vector<int> sequence = user_sequence();
    print_sequence(sequence);
    print_sum(count, sequence);

    return 0;
}