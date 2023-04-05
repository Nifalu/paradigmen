#include <iostream>

using namespace std;

int main() {
    int a = 4;
    int b = a + 6;
    int *p = &a, **q = &p;
    *p *= 4**&b***q;  // Never write such minified lines in your code!
    p = &b;
    *p = a + 5;
    (*p)++;
    //p *= 2; cannot multiply pointers or addresses
    cout << a << " " << b << " " << p << " " << /*(p - p - 8)) << */ endl; // cannot substract pointers either.
    
    return 0;
}