//  main.cpp
//  Textbook_grades


//This program will calculate statistics about student's grades from an online textbook.

#include <iostream>
using namespace std;

int main()
{
    int grades_amount=0, grade, passing_amout=0, failing_amount=0;
    float total_of_grades=0, avarage_grade;
    char user_response;
    
    cout <<"Is there any grade? (Y/y for yes) "; // If the user will type anything else than "y" or "Y" the                                             program will assume that it is "no".
    cin >> user_response;
    
    while( user_response == 'y' or user_response == 'Y') // While loop because program can not run at all.
    {
        cout << "Enter received grade ";
        cin >> grade;
        while (grade < 0 || grade > 100) // If the user enters an incorrect grade, the program will ask to                                  try again until it receives a valid one.
        {
            cout << "The grade have to be between 0 and 100." << endl;
            cout << "Please input a valid value for the grade: ";
            cin >> grade;
        }
        
        if(grade>=60)
            passing_amout ++;
        else
            failing_amount ++;
        
        grades_amount ++;
        total_of_grades += grade;
        
        cout <<"Do you have another grade? (Y/y for yes) ";
        cin >> user_response;
    }
    
    if(grades_amount==0)
        cout << "No students have tried the assignment yet" << endl;
    else
    {
        avarage_grade = total_of_grades/grades_amount;
        cout << "Your avarage of all grades is "<< avarage_grade << endl;
        cout << "The number of attempts is " << grades_amount << endl;
        cout << "The number of failing grades is " << failing_amount << endl;
        cout << "The number of passing grades is " << passing_amout << endl;
    }
        
    return 0;
}
