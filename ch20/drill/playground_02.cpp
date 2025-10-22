#include <iostream>
#include <set>

using namespace std;

struct Fruit {
    string name;
    int count;
    double unit_price;
};

struct Fruit_order {
        bool operator()(const Fruit& a, const Fruit& b) const
        {
                return a.name<b.name;
        }
};

int main() {

    set<Fruit, Fruit_order> inventory;

    inventory.insert(Fruit{"quince",5});
    inventory.insert(Fruit{"apple", 5, 0.50});
    inventory.insert(Fruit{"banana", 7, 0.60});

    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
    cout << it->name 
         << ", Count: " << it->count 
         << ", Price: " << it->unit_price
         << endl;
    }
}