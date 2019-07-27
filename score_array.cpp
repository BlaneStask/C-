//Description: This program calculates the average of 5 test scores while the lowest is dropped

#include <iostream>
#include <iomanip>

using namespace std;

void getScores(int scorearray[5]);
void calcAverage(int scorearray[5]);
int findLowest(int scorearray[5]);

int main()
    {
        int scorearray[5];
        getScores(scorearray);
        findLowest(scorearray);
        calcAverage(scorearray);
    
    return 0;
    }
    
    void getScores(int scorearray, int size, int total, int testscore)
    {
        cout << "Enter exam score: ";
        for (int i = 0; i < size; ++i)
        {
            cin >> scorearray;
        }
        
        //validate input
        while (testscore < 0 || testscore > 100)
        {
            cout << "Enter a valid score: ";
            cin >> testscore;
        }
        total += testscore;
    }
    
    void calcAverage(int lowest, int total)
    {
        int sum = 0;
        float avg = 0;
        
        //average of sum
        sum = total - lowest;
        avg = sum / 4;
        
        cout << "The average of the four largest scores is: " << setprecision(2) << fixed << avg;
    }
    
    int findLowest(int scorearray[5])
    {
        //loops for lowest integer
        int lowest = scorearray[0];
        for (int i = 1; i < 5; i++)
        {
            if (scorearray[i] < lowest)
                lowest = scorearray[i];
        }
        
        return lowest;
    }
