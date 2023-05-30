#include <new> 
#include <iostream>
struct Foo { long a,b,c,d,e,f,g,h,i,j,k,l; }; 

void f() {
    try {
        for (;;) new Foo;
    } catch (std::bad_alloc&) {
        std::cerr << "Freispeicher erschöpft!" << std::endl; 
    }
}

int main() {
    f();
    return 0;
}