//This program will ask a student about the grade in CSC111 course, as well as a level of completed education, based on the input it will determine if the student qualifies for being a tutor or not.
// Based on education level the program will print a base pay rate

#include <iostream>
#include <string>

using namespace std;

int main()
{
    const float NODEG_PAYRATE = 17.45;
    const float AS_PAYRATE = 19.55;
    const float BS_PAYRATE = 21.75;
    const float MS_PAYRATE = 25.00;
    const float PHD_PAYRATE = 30.00;
    
    bool hasTutoringReq;
    
    char degree, recommendation; //a letter for opperator based on  the choices
    float grade_num;
    string grade_letter; // string because the grade can be with + or -
    int exp_in_semesters;
    float payrate; //needed only for extra practice
    
    cout << "What was your numeric grade for your CSC111 course? ";
    cin >> grade_num;
    
    if(grade_num>=93)
        grade_letter = "A";
    else if(grade_num<93 && grade_num>=90)
        grade_letter = "A-";
    else if(grade_num<90 && grade_num>=87)
        grade_letter = "B+";
    else if(grade_num<87 && grade_num>=83)
        grade_letter = "B";
    else if(grade_num<83 && grade_num>=80)
        grade_letter = "B-";
    else if(grade_num<80 && grade_num>=77)
        grade_letter = "C+";
    else if(grade_num<77 && grade_num>=73)
        grade_letter = "C";
    else if(grade_num<73 && grade_num>=70)
        grade_letter = "C-";
    else if(grade_num<70 && grade_num>=67)
        grade_letter = "D+";
    else if(grade_num<67 && grade_num>=63)
        grade_letter = "D";
    else if(grade_num<63 && grade_num>=60)
        grade_letter = "D-";
    else
        grade_letter = "F"; //we assume that the student will only use the given characters
    
    cout << "What is the highest level of education you have completed?\n\n";
    cout << "\t N - no degree\n" << "\t A - Associates Degree\n" <<"\t B - Bachelor's Degree\n" << "\t M - Master's Degree\n" << "\t D - Doctorate\n\n";
    cout << "Type a letter: ";
    cin >> degree;
    cout << endl;
    
    if(degree == 'N' || degree == 'n')
    {
        cout << "Your letter grade was a " << grade_letter << " and you have not completed a degree." << endl;
        cout << "Do you have a recommendation from a prof? (Y/N): ";
        cin >> recommendation;
        if((recommendation == 'Y' || recommendation == 'y') && (grade_num >=90))
        {
            hasTutoringReq = true;
        }
        else
        {
            hasTutoringReq = false;
        }
    }
    else if(degree == 'A' || degree == 'a')
    {
        cout << "Your letter grade was a " << grade_letter << " and you have an Associate's Degree." << endl;
        if(grade_num >=90)
            hasTutoringReq = true;
        else
            hasTutoringReq = false;
    }
    else if(degree == 'B' || degree == 'b' )
    {
        cout << "Your letter grade was a " << grade_letter << " and you have a Bachelor's Degree." << endl;
        if(grade_num >=90)
            hasTutoringReq = true;
        else
            hasTutoringReq = false;
    }
    else if(degree == 'M' || degree == 'm')
    {
        cout << "Your letter grade was a " << grade_letter << " and you have a Master's Degree." << endl;
        if(grade_num >=87)
            hasTutoringReq = true;
        else
            hasTutoringReq = false;
    }
    else if(degree == 'D' || degree == 'd' )
    {
        cout << "Your letter grade was a " << grade_letter << " and you have a Doctorate Degree." << endl;
        if(grade_num >=87)
            hasTutoringReq = true;
        else
            hasTutoringReq = false;
    }
    else
    {
        hasTutoringReq = false;
    }
        
    if(hasTutoringReq == true)
    {
        cout << "You are eligible to be a tutor" << endl;
        cout << endl;
        if(degree == 'N' || degree == 'n')
            cout << "The starting rate for tutors with no degree is $" << NODEG_PAYRATE << endl;
        else if(degree == 'A' || degree == 'a')
            cout << "The starting rate for tutors with an Associate Degree is $" << AS_PAYRATE << endl;
        else if(degree == 'B' || degree == 'b' )
            cout << "The starting rate for tutors with a Bachelor's Degree is $" << BS_PAYRATE << endl;
        else if(degree == 'M' || degree == 'm')
            cout << "The starting rate for tutors with a Master's Degree is $" << MS_PAYRATE << endl;
        else if(degree == 'D' || degree == 'd' )
            cout << "The starting rate for tutors with a Doctorate Degree is $" << PHD_PAYRATE << endl;
        
        cout << endl;
    cout << "How many semesters (Fall & Spring only) of tutoring experience do you have with CUNY? ";
    cin >> exp_in_semesters;
        cout << "Every two years is an additional 2% of this rate" << endl;
    }
    else
        cout << "You do not have requirements for tutoring. There may be other positions." << endl;
    
    return 0;
}
