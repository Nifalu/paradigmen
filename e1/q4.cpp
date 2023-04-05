#include <iostream>


// define vector 2d
typedef struct{double x, y;} vec2d;

// define matrix 2d
typedef struct{double a, b, c, d;} mat2d;

// solver function takes a vector and a matrix
// and multiplicates them together.
vec2d solve(vec2d v, mat2d m) {

    vec2d u;

    // Transform matrix
    m.c = m.c - m.a * (m.c / m.a);  // m.c should now be 0
    m.d = m.d - m.b * (m.c / m.a);
    v.y = v.y - v.x * (m.c / m.a);

    // solve
    u.y = v.y / m.d;
    u.x = (v.x - (m.b * u.y))/m.a;

    return u;
}



int main() {
    // create a vector
    vec2d v;
    v.x = 2;
    v.y = 1;

    // create a matrix
    mat2d m;
    m.a = 1;
    m.b = 1;
    m.c = 0;
    m.d = 5;

    // solve
    vec2d w = solve(v, m);

    // should print out the vector (11/5)
    std::cout << w.x << std::endl << w.y << std::endl;
    
    return 0;
}