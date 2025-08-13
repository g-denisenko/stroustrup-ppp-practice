#include <iostream>
#include <sstream>
#include <climits>
#include <cassert>
#include <cfloat>
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

vector<double> user_sequence() {
    cout << "Enter a sequence of integers. Use '|' for end: " << endl;
    vector<double> sequence;
    char stop;  // 124 for '|'-shymbol stop
    while(stop!='|') {
        double n;
        cin >> n;
        if(!cin) {
            cin.clear();
            if(cin.peek()=='|') {
                stop = '|';
                cout << "STOP symbol was meet.\n" << endl;
                break;
            }
            cin.ignore();
            continue;
        }
        else sequence.push_back(n);
    }
    return sequence;
}

void print_sequence(vector<double> sequence) {
    if(sequence.size()>0) {
        cout << "The sequence: " << endl;
        for(int i=0; i<sequence.size(); i++) {
            cout << sequence[i] << endl;
        }
    }
    else cout << "Sequence is empty." << endl;
}

void assert_check_range_sum_int(int a, int b) {
    assert(a+b<INT_MAX && "INT: OUT OF RANGE of maximum");
    assert(a+b>INT_MIN && "INT: OUT OF RANGE of minimum"); 
}

void print_sum(int n, vector<double> sequence) {
    double sum = 0;
    if(sequence.size() < n) {
        cout << "Sequence of double's is less than asked " << n << " elements.\nSum of all elements of sequence:";

        for(int i=0; i<sequence.size(); i++) {
            assert_check_range_sum_int(sum, sequence[i]);
            sum+=sequence[i];
        }
    }
    else { 
        cout << "Sum for " << n << " first numbers:";
        for(int i=0; i<n; i++) {
            assert_check_range_sum_int(sum, sequence[i]);
            sum+=sequence[i];
        }
    }
    cout << sum << endl;
}

vector<double> adjacent_differences(int n, vector<double> sequence) {
    double diff = 0;
    int counter = n;
    if(sequence.size() < n) counter = sequence.size();
    vector<double> result;
    for(int i=0; i<counter; i++) {
        if(sequence[i+1]){
            diff = sequence[i]-sequence[i+1];
        }
        result.push_back(diff);
    }
    return result;
}

void print_adjacent_differences(int n, vector<double> sequence) {
    vector<double> diff = adjacent_differences(n-1, sequence);
    if(sequence.size() < n) {
        cout << "Sequence of double's is less than asked " << n << " elements. Adjacent diff for all elements is:" << endl;

        for(int i=0; i<diff.size()-1; i++) {
            cout << diff[i] << endl;
        }
    }
    else { 
        cout << "Adjacent Difference for " << n << " first numbers:" << endl;
        for(int i=0; i<n-1; i++) {
            cout << diff[i] << endl;
        }
    }
}

int main() {
    int count = user_num();
    vector<double> sequence = user_sequence();
    print_sequence(sequence);
    print_sum(count, sequence);
    print_adjacent_differences(count, sequence);

    return 0;
}