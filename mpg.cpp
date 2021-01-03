//Description: This program calculates a car's gas mileage.

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int gallons;
    int miles;
    int mpg;
    cout << "How many gallons of gas can the car hold? " ;
    cin >> gallons;
    cout << "How many miles can be driven on a full tank of gas? " ;
    cin >> miles;
    //Calculate the miles per gallon
    mpg = miles / gallons;
    cout << setprecision(3) << fixed;
    cout << "The miles per gallon of your car is " << mpg << ".\n";
    return 0;
}
