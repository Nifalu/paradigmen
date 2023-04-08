#include <iostream>

void foo (int *ptr) {
    *ptr = 5; // dereferenced ptr holds value 7 which is changed to 5
}

int main() {
    int b = 7; // define int b
    int *ptr = &b; // pointer points to address of b
    foo(ptr);   // pass pointer to foo

    std::cout << *ptr << std::endl;
    return 0;
}