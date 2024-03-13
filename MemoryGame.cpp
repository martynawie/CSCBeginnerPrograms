#include <iostream>
#include <stdio.h>  
#include <stdlib.h> 
#include <time.h> 
using namespace std;

class memory
{
public:

  string name;
  int age;
  string objects[3];

  string set1[3] = {"horse", "pig", "cow"};
  string set2[3] = {"bed", "pillow", "blanket"};
  string set3[3] = {"TV","sofa","table"};

  string arr[3]={"","",""}; 

  memory()
  {
    name = "";
    age = 0;
    objects[0] = "";
    objects[1] = "";
    objects[2] = "";
  }

  void setRandomObjects()
  {
    srand(time(NULL));
    objects[0] = set1[rand() % 3];
    objects[1] = set2[rand() % 3];   
    objects[2] = set3[rand() % 3];
  }

  void welcome()
  {
    cout<< "I will give you 3 words, you need to memorize them, repead them once aout loud and then I will ask you some other questions about you"<<endl;
  }
  
  void randomQuestion()
  {
    int number;
    string S;
    cout<< "What is you name? "<<endl;
    cin>> name;
    cout<< "How old are you?"<<endl;
    cin>> age;
    cout<< "What is your favorite number?"<<endl;
    cin>> number;
    cout<<"Do you preffer dog or cat?"<<endl;
    cin>>S;
    cout<<"Do you preffer coffee or tea?"<<endl;
    cin>> S;
    cout<<"What color is milk?"<<endl;
    cin>> S;
    cout<<"What is your favorite day of the week"<<endl;
    cin>> S;
  }

  void printObjects()
  {    
    cout<< "The 3 objects are:"<<endl;
    for(int i = 0; i < 3; i ++)
    {
      cout<< i+1<<"- "<<objects[i]<<endl;    
    }
    cout<<endl;
  }

  void answers()
  {
    int num;
    cout<< "How many object do you remember out of the 3 objects? (1-3)";
    cin>> num;
    cout<< "What were the objects"<<endl;
    for(int i = 0; i < num; i++)
    {
      cout<< "enter object "<<i+1<<": ";
      cin>> arr[i];
    }
    comparre(arr); // Pass arr to comparre function
  }

  void comparre(string arr[]) // Add arr as parameter
  {
    int correct_guesses = 0;
    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        if(objects[i] == arr[j])
        {
          correct_guesses++;
          break;
        }
      }
    }
    cout << "You guessed " << correct_guesses << " out of 3 objects correctly." << endl;
  }
  int missing()
  {  
    return 0;
  }

};



int main() {

  memory p;
  p.welcome();
  p.setRandomObjects();
  p.printObjects();
  p.randomQuestion();
  p.answers();
 
  return 0;
}  