//  --------------------------------------
//  "Buggy" code! Practice's playground. 
//  --------------------------------------

#include <iostream>
using namespace std;

class Vector {
    long int sz;
    double* elem;

    public:
    explicit Vector(int n)
        : sz{n}, elem{new double[n]} {
            for(int i=0;i<n;++i)
                elem[i] = 0.0;
            cout << this <<" Vector constructed with " << n << " elements.\n";
        }
    Vector(initializer_list<double> lst)
        : sz{lst.end()-lst.begin()}, elem{new double[sz]} {
            cout << this << " Vector constructed with list of " << sz << " elements.\n";
            copy(lst.begin(),lst.end(), elem);
        }

    // COPY Semantic
    Vector(const Vector& arg)
        : sz{arg.sz}, elem{new double[arg.sz]} {
            cout << this << " Copy constructor called.\n";
            copy(arg.elem, arg.elem+sz, elem);
        }
    Vector& operator=(const Vector&);

    // MOVE Semantic
    Vector(Vector&& arg)
        : sz{arg.sz}, elem{arg.elem} {
            cout << this << " Move constructor called.\n";
            arg.sz = 0;
            arg.elem = nullptr;
        }
    Vector& operator=(Vector&&);

    ~Vector() {delete[] elem; cout << this << " Vector deleted.\n";}

    size_t size() {return sz;}
    double* begin() const {return elem;}
    double* end() const {return elem+sz;}
    double& operator[](int n) {return elem[n];}
    const double& operator[](int n) const {return elem[n];}
};

Vector& Vector::operator=(const Vector& a) {
    double* p = new double[a.sz];
    copy(a.elem, a.elem+sz, p);
    delete[] elem;
    elem = p;
    sz = a.sz;
    return *this;
}

Vector& Vector::operator=(Vector&& a) {
    if(this != &a){
        delete[] elem;
        elem = a.elem;
        sz = a.sz;
        a.elem = nullptr;
        a.sz = 0;
    }
    return *this;
}

Vector make_large(const int size) {
    Vector result(size);
    for(int i=0; i<size; ++i)
        result[i] = 0.1*i;
    return result;
}

int main() {
    Vector v {1.2, 3.4, 5.6};
    for(size_t i=0; i<v.size(); ++i)
        cout << &v[i] << ":" << v[i] << " | ";
    cout << endl;
    for(size_t i=0; i<v.size(); ++i)
        cout << &v[i] << ":" << v[i] << " | ";
    cout << endl;
    v[3] = .99;
    cout << "Out-of-range: " << &v[3] << ":" << v[3] << endl;
    
    Vector v2 = v;
    v2[0] = 11.1;
    v2[1] = 12.1;
    v2[2] = 13.1;
    for(size_t i=0; i<v2.size(); ++i)
        cout << &v2[i] << ":" << v2[i] << " | ";
    cout << endl;

    Vector vlarge = std::move(make_large(100000000));   // Explicitly call move semantic
    auto vvv = vlarge;
    return 0;
}