#include <iostream>

void foo (int *&ptr) {
    int a = 5;
    ptr = &a;
}

int main() {
   int b = 7;
   int *ptr;
   *ptr = b;
   std::cout << *ptr << std::endl;
   foo(ptr);
   std::cout << *ptr << std::endl;
   return 0;
}