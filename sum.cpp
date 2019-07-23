//Description: This program finds the sum of all integers from 1 to the users input positive integer value.

#include <iostream>
using namespace std;

int main()
{
    int value = 0;
    int sum = 0;
    
    cout << "Enter a positive integer value." ;
    cin >> value;
    
    //For positive integers
    for (int i = 1; i <= value; i++)
        {
            sum += i;
            
            cout << "Sum of the integers 1 - " << value << " is " << sum << endl;
        }
    //For negative integers
    while (value < 0)
        {
            cout << value << "is a negative integer.";
        }
    
    return 0;
}
