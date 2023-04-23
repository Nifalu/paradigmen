#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "DynamicPrint.h"

using namespace std;

// Constructors / Destructor
template <typename T>
DynamicArray<T>::DynamicArray()
{
    this->array = nullptr;
    this->size = 0;
}
template <typename T>
DynamicArray<T>::DynamicArray(int s)
{
    this->array = new T[s];
    this->size = s;
}
template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] array;
}

template <typename T>
T &DynamicArray<T>::operator[](int i) const
{
    if (i < 0 || i >= size)
    { // if array index is out of bounds
        cerr << "Index out of Bounds. Index: " << i << " Array length: " << size << endl;
        exit(1);
    }
    return array[i];
}
template <typename T>
int DynamicArray<T>::getSize() const
{
    return size;
}
template <typename T>
void DynamicArray<T>::resize(int newSize)
{
    if (newSize == size) { return; }
    if (newSize < size) { size = newSize; }

    T* newArray = new T[newSize];
    
    for (int i = 0; i < size; i++) 
    {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    size = newSize;
}


int main()
{
    DynamicArray<int> intArray = DynamicArray<int>(5);
    DynamicArray<double> doubleArray = DynamicArray<double>(5);
    DynamicArray<char> charArray = DynamicArray<char>(5);

    char chars[12] = {'H', 'E', 'L', 'L', 'O',' ', 'W', 'O', 'R', 'L', 'D', '!'};


    for (int i = 0; i < 5; i++) {
        intArray[i] = i;
        doubleArray[i] = 1 + 0.1 * i;
        charArray[i] = chars[i];
    }
    cout << "--------ORIGINAL---------" << endl;
    cout << intArray << endl;
    cout << doubleArray << endl;
    cout << charArray << endl;
    
    intArray.resize(4);
    doubleArray.resize(12);
    charArray.resize(12);

    for (int i = 5; i < doubleArray.getSize(); i++) {
        doubleArray[i] = 1 + 0.1 * i;
    }

    for (int i = 5; i < charArray.getSize(); i++) {
        charArray[i] = chars[i];
    }
    cout << "--------RESIZED----------" << endl;
    cout << intArray << endl;
    cout << doubleArray << endl;
    cout << charArray << endl;

    return 0;
}
