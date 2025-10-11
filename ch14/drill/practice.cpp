/*
Polishing skills and testing different mechanics and ficilites of the language.
*/

#include <iostream>
using namespace std;

class A {
public:
    A() : val_(0) {}
    A(int v) : val_(v) {}

    void set(int v) { val_ = v; }
    int get() const { return val_; }

    int pub = 888;
    virtual int mul(int x) { return x * 2; }

protected:
    int prot = 123;

private:
    int val_ = 0;
};


class B : public A {
public:
    using A::pub;
    int derived_pub = A::pub;

    B() = default;
    B(int v) : A(v) {}

    int mul(int x) override { return x * 4; }

    void set(int v) { b_ = v; }
    int get() const { return b_; }
    char ch() const { return c_; }
    int base_val() const { return A::get(); }
    int prot_val() const { return A::prot; }

private:
    int b_ = 99;
    char c_ = 'x';
};

class C : public A {
public:
    C(int v) : c_(v) {}

    void set(int v) { c_ = v; }
    int get() const { return c_; }
    int base_val() const { return A::get(); }

private:
    int c_ = 0;
};

inline string get_str(const string& t) { return t; }

int main() {
    auto custom_sqrt = [](int x) { return x * x; };

    B b1(12);
    int b_mul = b1.mul(9999);
    b1.pub = 1234;

    A a;
    a.set(custom_sqrt(23));

    B b2;
    C c1(44);

    cout << b2.get() << '\n';          // prints 99 (default B::b_)
    cout << b1.base_val() << '\n';     // prints 12 (value passed to A ctor)
    cout << b1.derived_pub << '\n';    // prints 888 (copied from A::pub)
    cout << b_mul << '\n';             // prints 39996 (9999 * 4)
    cout << a.get() << '\n';           // prints 529
    cout << b1.pub << '\n';            // prints 1234
    cout << a.pub << '\n';             // prints 888
    cout << b1.ch() << '\n';           // prints x
    cout << b1.prot_val() << '\n';     // prints 123
    cout << c1.get() << '\n';          // prints 44
    cout << c1.base_val() << '\n';     // prints 0 (C didn't set A's value)
    cout << get_str("title") << '\n';

    return 0;
}
