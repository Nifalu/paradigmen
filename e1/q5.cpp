#include <iostream>

// enum containing all supported operations
enum operations {
    addition,
    subtraction,
    multiplication,
    division,
    modulo
};

// do the given operation on the two numbers a and b.
double calculate(operations op, int a, int b) {
    switch (op) {
        case addition:
            return a+b;
        case subtraction:
            return a-b;
        case multiplication:
            return a*b;
        case division:
            return a/b;
        case modulo:
            return a%b;
    }
}

// example union for 5c
union test {
    int x;
    double y;
};


int main() {
    int a = 10;
    int b = 5;

    test q;
    q.x = 1;
    q.y = 2.5;
    std::cout << q.x << std::endl;
    std::cout << q.y << std::endl;

    std::cout << calculate(addition, a, b) << std::endl;
    std::cout << calculate(subtraction, a, b) << std::endl;
    std::cout << calculate(multiplication, a, b) << std::endl;
    std::cout << calculate(division, a, b) << std::endl;
    std::cout << calculate(modulo, a, b) << std::endl;

    return 0;
}