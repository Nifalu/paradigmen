#include <iostream>

using namespace std;

int main() {
   int a = 4; // a is now 4
   int b = a + 6; // b is now 10
   int *p = &a, **q = &p; // p points to a, q points to p
   *p *= 4**&b***q;  // a *= 4 * b * q --> a = 4 * 4 * 10 * 4 = 640
   p = &b; // p now points to b instead of a
   *p = a + 5; // b is now 645
   (*p)++; // b is incremented by 1 --> b = 646
   cout << p << " " << (*p + (*p - 8)) << endl;
   // ["address of b" 1284]
   *p *= 2; // b is multiplied by 2
   cout << a << " " << b << " " << p << " " << (*p + (*p - 8)) << endl;
   // [640 1292 "address of b" 2576]
    
    return 0; // tell OS that program completed successfully
}