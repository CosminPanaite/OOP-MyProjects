#include <iostream>
#include "ComplexNumber.h"
#include "DynamicArray.h"

using namespace std;

int main()
{
    DynamicArray arr1; 
    arr1.insertAtEnd(1); 
    arr1.insertAtEnd(2);
    DynamicArray arr2 = arr1; 
    DynamicArray arr3; 
    arr3 = arr2; // arr3 = 1, 2
    arr2[0] = 10; // arr3 = 1, 2
    arr3[1] = 7; // arr3 = 1, 7
    cout << "The first array is: " << arr1 << endl; 
    cout << "The second array is: " << arr2 << endl; 
    cout << "The third array is: " << arr3 << endl;
    return 0;
}


