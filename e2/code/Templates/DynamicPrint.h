#ifndef DYNAMICPRINT_H
#define DYNAMICPRINT_H

#include "DynamicArray.h"
#include <iostream>

template<typename U>
ostream& operator<<(ostream& os, DynamicArray<U>& arr);

#include "DynamicPrint.cpp"

#endif // DYNAMICPRINT_H
