#include <iostream>
void foo (int *ptr) {
    int *a = 5; // can't assign an int to a pointer
    *ptr = *a; // can't derefence a variable
}

int main() {
    int b = 7;
    int *ptr;
    *ptr = b; // runtime error: can't derefence a non-initialized pointer.
    foo(ptr);

    std::cout << *ptr << std::endl;
    return 0;
} 