//Description: This program collects data to calculate the average rainfall over a period of years.

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int years = 0;
    const int month = 12;
    float totalr = 0.0f;
    float rain = 0.0f;
    cout << "Enter number of years: " << endl;
    cin >> years;
    //Needs to be at least a year
    while (years < 1){
        cout << "Must be at least 1 year";
        cin >> years;
    }
    //Years looped
    for (int i = 1; i <= years; i++){
        //Months looped
        for (int months = 1; months <= month; months++){
            //Recorded rainfall for the month
            cout << "Enter the rainfall for " << months << " month: ";
            cin >> rain;
            //Negative rainfall
            while (rain < 0){
                cout << "This cannot be a negative value ";
                cin >> rain;
            }
            //Total recorded rainfall
            totalr += rain;
        }
    }
    cout << "Number of months: " << years * 12 <<endl;
    cout << "Total rainfall: " << setprecision(2) << fixed << totalr << " inches" << endl;
    cout << "Average rainfall: " << setprecision(2) << fixed << totalr / (years * 12) << " inches";
    return 0;
}
