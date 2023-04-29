#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

template <typename T> 
class DynamicArray
{
    public:
        /* --- Constructors and Destructor --- */

        DynamicArray() // Construct Array of length 1
        {
            this->size = 0;
            this->length= 1;
            this->array = new T[this->length];
        }

        DynamicArray(size_t length) { // Construct array of a given length
            this->size = 0;
            this->length = length;
            this->array = new T[length];
        }

        ~DynamicArray() { 
            delete[] array;
        }

        /* --- Overloading [] operator for easy access --- */
        // Writing to the array this way does NOT increase the Array length!!

        T& operator[](size_t index)
        {
            if (index >= size) {
                throw out_of_range("Index out of range");
            }
            return array[index];
        }

        const T& operator[](size_t index) const
        {
            if (index >= size) {
                throw out_of_range("Index out of range");
            }
            return array[index];
        }
        
        /* --- Overloading the << operator to easily print the entire Array */
        template<typename U>
        friend ostream& operator<<(ostream& os, const DynamicArray<U>* arr);
        


        /* --- append and delete methods --- */
        void append(const T& value) {
            if (size == length) { // if the array is full, double its length!
                resize(2 * length);
            }
            array[size++] = value;
        }

        void delete_last() { // only allows overwriting data. It deletes nothing!
            if (size == 0)
            {
                throw length_error("Cannot delete from empty array");
            }
            --size;
        }

        /* --- Getters --- */
        size_t get_size() const {
            return size;
        }

        size_t get_length() {
            return length;
        }

    
    private:
        size_t size;    // current number of elements in the array
        size_t length;  // current length of the array
        T* array;       // pointer to the array on the heap

        void resize(size_t new_length) {
            T* new_array = new T[new_length];
            for (size_t i = 0; i < size; ++i)
            {
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
            length = new_length;
        }
};

template<typename U>
ostream& operator<<(ostream& os, const DynamicArray<U>* arr)
{
    os << "[";
    for (int i = 0; i < arr->get_size(); i++) {
        os << (*arr)[i];
        if (i != arr->get_size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
