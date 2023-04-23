#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <string>

using namespace std;

template <typename T> class DynamicArray
{
    private:
        T* array;
        int size;
    
    public:
        // Constructors / Destructor
        DynamicArray();

        DynamicArray(int s);

        ~DynamicArray();

        T& operator[](int i) const;

        int getSize() const;

        void resize(int newSize);
};


#endif