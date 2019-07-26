//Description: This program accepts and int array and doubles the size of it and its contents.

#include <iostream>
#include <iomanip>

using namespace std;

int *extendArray(int*, int);
void initArray(int*, int);
void printArray(int*, int);

int main()
{
    const int SIZE = 10;
    int *values = new int[SIZE];
    
    initArray(values, SIZE);
    
    cout << "Contents of original array:\n\n";
    
    values = extendArray(values, SIZE);
    printArray(values, (SIZE*2));
    
    cout << "\n\nContents of resized array:\n\n";
    
    return 0;
}

int *extendArray(int*, int size)
{
    for (int i = 0; i < 2*size; i++)
        cout << new int[i] << " ";
    
    return 0;
}

void initArray(int *nums, int size)
{
    for (int i = 0; i < size; ++i)
        nums[i] = i;
}

void printArray(int *nums, int size)
{
    for (int i = 0; i < size; ++i)
        cout << nums[i] << " ";
}

