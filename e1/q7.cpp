#include <iostream>
#include <math.h>

// Compares two double numbers
int compareDouble(double d1, double d2) {
    if (d1 == d2) {return 0;}
    return (d1 > d2) ? 1 : -1;
}

// compares according to the sinus value of the second element in the array.
int compare_sin(double* arr1, double* arr2) {
    return compareDouble(sin(arr1[1]), sin(arr2[1]));
}

// compares according to their respective L1 values.
int compare_taxicab(double* arr1, double* arr2) {
    double manh_d1 = sqrt(arr1[0] * arr1[1] * arr2[2]);
    double manh_d2 = sqrt(arr2[0] * arr2[1] * arr2[2]);
    return compareDouble(manh_d1, manh_d2);
}

// main compare function
int compare(double* arr1, double* arr2, int (*fptr)(double*, double*)) {
    return fptr(arr1, arr2);
}

int main() {
    double arr2[] = {75, 5, 29};
    double arr1[] = {1, 6, 7};
    
    std::cout << compare(arr1, arr2, compare_sin) << std::endl;
    std::cout << compare(arr1, arr2, compare_taxicab) << std::endl;
}