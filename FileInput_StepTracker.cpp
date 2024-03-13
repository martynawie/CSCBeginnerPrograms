// The program will read from outside source amount of steps per day and compare it to the user's daily goal. The program will do simple calculations like the number of trucking days and the total number of steps, and will also check on how many days the user met the daily goal.
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream step_tracker;
    int steps, stepgoal, total_steps=0, number_of_days=0, days_met_goal=0, days_dindt_meet_goal=0;
    float average_day_steps; // dividing two numbers may return the decimal point
    
    step_tracker.open("daily_step_count_data.txt"); //reading from the file
  
    cout << "What is your step count goal for a day? ";
    cin >> stepgoal;
    
    if(step_tracker)
    {
        while(step_tracker >> steps) // assigning a value from a file to the number of steps
        {
            number_of_days ++; // every number is one day
            total_steps += steps;
            if(steps>=stepgoal)
            {
                days_met_goal ++;
            }
            else
            {
                days_dindt_meet_goal ++;
            }
        }
        cout << "Total of your steps is " << total_steps << " in " << number_of_days << " days." << endl;
        cout << "Your daily goal was " << stepgoal << " steps." << endl;
        cout << "You met your goal on " << days_met_goal << " days." << endl;
        cout << "You didnt meet your goal on " << days_dindt_meet_goal << " days." << endl;
        if(total_steps>0)//you cannot divide by 0, and the number of steps cannot be negative
        {
            days_met_goal ++;
            average_day_steps = static_cast<float>(total_steps)/number_of_days;
            cout << "Avarage of your steps is " << average_day_steps << " per day." << endl;
        }
    }
    else
    {
        cout << "The program didnt open correctly" << endl;
    }
    step_tracker.close();
    return 0;
}
