#include <iostream>

enum operations { // enum containing all supported operations
    addition,
    subtraction,
    multiplication,
    division,
    modulo
};

double calc(operations op, int a, int b) {
    switch (op) {   // does the given operation
        case addition: return a+b;
        case subtraction: return a-b;
        case multiplication: return a*b;
        case division: return a/b;
        case modulo: return a%b;
    }
}

union test {int x; double y;}; // example union for 5c

int main() {
    int a = 10;
    int b = 5;
    std::cout << "10 + 5 = " << calc(addition, a, b) << std::endl;
    std::cout << "10 - 5 = " << calc(subtraction, a, b) << std::endl;
    std::cout << "10 * 5 = " << calc(multiplication, a, b) << std::endl;
    std::cout << "10 / 5 = " << calc(division, a, b) << std::endl;
    std::cout << "10 % 5 = " << calc(modulo, a, b) << std::endl;

    test q; // example to show how one value of a union overwrites another.
    q.x = 1;
    q.y = 2.5;
    std::cout << "q.x " << q.x << " y: " << q.y << std::endl;

    return 0;
}