#include <iostream>

typedef struct{ // Combine array length with array
    int *ptr;
    int len;
}arr;

// Take even numbers of reversed b and add even numbers of a.
// Return pointer to new array and length.
arr combineReverseEvenWithLength(arr a, arr b) {
    // Count even Numbers on both arrays
    int numOfEvenElem = 0;
    for (int i = 0; i < a.len; i++) {
        if ((*(a.ptr+i) % 2) == 0) { numOfEvenElem += 1; }
    }
    for (int i = 0; i < b.len; i++) {
        if ((*(b.ptr+i) % 2) == 0) { numOfEvenElem += 1; }
    }
    
    arr res; // Create new Array to fit all the even numbers of a and b
    res.ptr = new int[numOfEvenElem];
    res.len = numOfEvenElem;

    int c = 0; // Reverse the second array and add even numbers to res
    for (int i = 1; i < b.len+1; i++) {
        if ((*(b.ptr+b.len-i) % 2) == 0) {
            *(res.ptr+c) = *(b.ptr+b.len-i);
            c += 1;
        }
    }
    // Add even Numbers of first array to res
    for (int i = 0; i < a.len; i++) {
        if ((*(a.ptr+i) % 2) == 0) {
            *(res.ptr+c) = *(a.ptr+i);
            c += 1;
        }
    }
    return res;
}

//combines arrays into struct and calls other function to solve.
int* combineReverseEven(int* a1, int* b1) {
    arr a; a.ptr = a1; a.len = 3;
    arr b; b.ptr = b1; b.len = 5;
    arr res = combineReverseEvenWithLength(a, b);
    return res.ptr;
}

int main() {
    // Initialize test arrays
    int a1[] = {1, 2, 4};
    int b1[] = {4, 5, 6, 8, 11};

    // combine into arr struct
    arr a; a.ptr = a1; a.len = 3;
    arr b; b.ptr = b1; b.len = 5;
    // calculate
    arr res = combineReverseEvenWithLength(a, b);

    // Print array to check results
    for (int i = 0; i < res.len; i++) {
        std::cout << *(res.ptr + i);
    }
    std::cout << std::endl;

    return 0;
}