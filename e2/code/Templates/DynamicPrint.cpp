#include "DynamicArray.h"
#include <iostream>

template<typename U>
        ostream& operator<<(ostream& os, DynamicArray<U>& arr) 
        {
            os << "[";
            for (int i = 0; i < arr.getSize(); i++) {
                os << arr[i];
                if (i != arr.getSize() - 1) {
                    os << ", ";
                }
            }
            os << "]";
            return os;
        }