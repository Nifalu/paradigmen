#include "DynamicArray.h"
#include <string>
#include <iostream>

using namespace std;

/*
The Arrays are all initialized with length 0 except for the string array which is set to length 20
When filling the Arrays with data, the first three arrays are going to increase their length from
1 to 2 to 4 to 8 to 16 while the string arrays stays at length 20.
*/

int main()
{
    DynamicArray<char>* charArray = new DynamicArray<char>();
    DynamicArray<int>* intArray = new DynamicArray<int>();
    DynamicArray<double>* doubleArray = new DynamicArray<double>();
    DynamicArray<string>* stringArray = new DynamicArray<string>(20);
    

    char chars[12] = {'H', 'E', 'L', 'L', 'O', ' ', 'W', 'O', 'R', 'L', 'D', '!'};
    string strings[12] = {"This ", "is ", "a ", "Dynamic ", "Array! ", "It ", "is ", "really " , "a ", "lot ", "of ", "fun!"};

    cout << "------- New Arrays: -------" << endl;
    cout << "length: " << "charArray: " << charArray->get_length() << charArray << endl;
    cout << "length: " << "intArray: " << intArray->get_length() <<intArray << endl;
    cout << "length: " << "doubleArray: " << doubleArray->get_length() <<doubleArray << endl;
    cout << "length: " << "stringArray: " << stringArray->get_length() <<stringArray << endl;

    for (int i = 0; i < 12; ++i) {
        charArray->append(chars[i]);
        intArray->append(i);
        doubleArray->append(i + double(i)/10);
        stringArray->append(strings[i]);
    }

    cout << "------- Filled Arrays: -------" << endl;
    cout << "length: " << "charArray: " << charArray->get_length() << charArray << endl;
    cout << "length: " << "intArray: " << intArray->get_length() <<intArray << endl;
    cout << "length: " << "doubleArray: " << doubleArray->get_length() <<doubleArray << endl;
    cout << "length: " << "stringArray: " << stringArray->get_length() <<stringArray << endl;

    cout << "------- [] Access -------" << endl;
    cout << "This is a " << (*stringArray)[3] << (*stringArray)[4] << endl;

    delete charArray;
    delete intArray;
    delete doubleArray;
    delete stringArray;
}