### 📚 DRILL Chapter 7

---

1. Write three functions `swap_v(int,int)`, `swap_r(int&,int&)`, and `swap_cr(const int&, const int&)`. Each should have the body
`{ int temp; temp = a, a=b; b=temp; }` 
where `a` and `b` are the names of the arguments. Try calling each swap like this
```c++
    int x = 7;
    int y = 9;
    swap_?(x,y);             // replace ? by v, r, or cr
    swap_?(7,9);
    const int cx = 7;
    const int cy = 9;
    swap_?(cx,cy);
    swap_?(7.7,9.9);
    double dx = 7.7;
    double dy = 9.9;
    swap_?(dx,dy);
    swap_?(7.7,9.9);
```
Which functions and calls compiled, and why? After each swap that compiled, print the value of the arguments after the call to see if they were actually swapped. If you are surprised by a result, consult __`§7.5`__.

2. Write a program using a single file containing three namespaces `X`, `Y`, and `Z` so that the following `main()` works correctly:
```c++
    int main()
    {
            X::var = 7;
            X::print();                  // print X’s var
            using namespace Y;
            var = 9;
            print();                       // print Y’s var
            {
                    using Z::var;
                    using Z::print;
                    var = 11;
                    print();              // print Z’s var
            }
            print();                       // print Y’s var
            X::print(); // print X’s var
    }
```
Each namespace needs to define a variable called `var` and a function called `print()` that outputs the appropriate `var` using `cout`.

3. Create a module `foo` with the suffix appropriate to your system:
```c++
    int foo = 0;
    export void print_foo() { ... };
    export void set_foo(int x} { foo = x; }
    export int get_foo() { return x; }
```
Add what it takes to get the ... part to print `foo`. Write file `use.cpp` that `import`s `foo` and tests it. Get the resulting program to compile and run.

4. Create a header file: foo.h:
```c++
    extern int foo;
    void print_foo();
    void print(int);
```
Write a file `foo.cpp` that implements the functions declared in `foo.h`. Write file `use.cpp` that `#include`s `foo.h` and tests it. Get the resulting program to compile and run.