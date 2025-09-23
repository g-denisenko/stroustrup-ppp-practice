#include "foo.h"
#include <iostream>
using namespace std;

int foo = 5;

void print_foo() { cout << "print foo()" << endl; }

void print(int) { cout << foo << endl; }