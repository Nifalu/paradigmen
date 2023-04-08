#include <iostream>

typedef struct{double x, y;} vec2d; // define vector 2d

typedef struct{double a, b, c, d;} mat2d; // define matrix 2d

// solver function takes a vector and a matrix
// and multiplicates them together.
vec2d solve(vec2d v, mat2d m) {

    vec2d u;

    // Transform matrix with gauss algorithm
    m.c = m.c - m.a * (m.c / m.a);  // m.c should now be 0
    m.d = m.d - m.b * (m.c / m.a);
    v.y = v.y - v.x * (m.c / m.a);
    u.y = v.y / m.d;
    u.x = (v.x - (m.b * u.y))/m.a;
    return u; // return vector u (solution)
}

int main() {
    vec2d v; // create example vector
    v.x = 2;
    v.y = 1;
    mat2d m; // create example matrix
    m.a = 1;
    m.b = 1;
    m.c = 0;
    m.d = 5;
    vec2d w = solve(v, m); // solve

    // should print out the vector (11/5)
    std::cout << w.x << std::endl << w.y << std::endl;
    
    return 0;
}