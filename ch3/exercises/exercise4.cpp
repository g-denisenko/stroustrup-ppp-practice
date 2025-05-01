#include <iostream>
using namespace std;

void print_dist(vector<double> v) {
    cout << "All distances entered: ";
    for(double element : v) {
        cout << element << '\t';
    }
    cout << endl;
}

void print_sum(vector<double> v) {
    double sum = 0;
    for(int i=0; i<v.size(); i++) {
        sum += v[i];
    }
    cout << "The sum of all distances is: " << sum << endl;
}

void print_mean(vector<double> v) {
    double sum = 0;
    for(int i=0; i<v.size(); i++) {
        sum += v[i];
    }
    cout << "The mean distance between two neighboring cities is: " << sum/v.size() << endl;
}

void print_smallest(vector<double> v) {
    auto smallest = v[0];
    for(int i=0; i<v.size(); i++) {
        if(smallest > v[i]) smallest = v[i];
    }
    cout << "The smallest distance between cities is: " << smallest << endl;
}

void print_greatest(vector<double> v) {
    auto greatest = v[0];
    for(int i=0; i<v.size(); i++) {
        if(greatest < v[i]) greatest = v[i];
    }
    cout << "The greatest distance between cities is: " << greatest << endl;
}

int main() {
    vector<double> distances;
    double smallest, greatest, current, previous;

    cout << "Please, enter a sequance of distances (double precision):" << endl;
    for ( ;cin>>current; ) {
        if(current > 0) {
            distances.push_back(current);
            print_dist(distances);
            print_sum(distances);
            print_mean(distances);
            print_smallest(distances);
            print_greatest(distances);
        }
        else cout << "Distance cannot be '0' or negative. Try again..." << endl;
    }
    return 0;
}