#include <iostream>
using namespace std;

double get_double() {
    double value;
    while(true) {
        cout << "Enter a double: ";
        cin >> value;
        if(cin.good()) break;
        else {
            cerr << "Invalid input. Please enter a numerical value." << std::endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return value;
}

bool ask_proceed() {
    cout << "Do you wanna procced? (y/n): ";
    char ch;
    while(true) {
        cin >> ch;
        if(ch=='y') return true;
        if(ch=='n') return false;
        else {
            cout << "Invalid input. Try again.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void fill_vector_double(vector<double>& v) {
    while(true) {
        double d = get_double();
        v.push_back(d);
        if(!ask_proceed()) break;
    }
} 

void fill_vectors() {
    fill_vector_double(price);
    fill_vector_double(weight);
}

double get_index(const vector<double>& p, const vector<double>& w) {
    if(p.size()!=w.size()) {
        cerr << "vector are differrent sizes.\n";
        return -1;
    }
    double index = 0;
    for(int i=0; i<p.size(); ++i) {
        index += p[i]*w[i];
    }
    return index;
}

int main() {
    vector<double> price(0);
    vector<double> weight(0);
    fill_vectors();
    cout << get_index(price, weight);
}