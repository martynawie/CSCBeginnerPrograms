
//This is the program that can help small stores to keep track of the product informations..

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printProductNames(const string[], int);
int binaryProductSearch( int  , const int[], int);
void printInventory(int, const string [], const int[], int);

int main()
{
    const int MAX_PRODUCT_NUM = 100; //max number of products
    int product_num = 0;
    int product_ID_num[MAX_PRODUCT_NUM];
    string product_name[MAX_PRODUCT_NUM];
    int product_counts[MAX_PRODUCT_NUM];
    float price[MAX_PRODUCT_NUM];
    int user_input, user_inputId, found_id_index, min_count;
    ifstream infile("product_inventory.txt");//opening the file
    
    if (infile)//creating loop to be able to check if the program was able to read the file
    {
        while(infile >> product_ID_num[product_num] && product_num <= MAX_PRODUCT_NUM) //reading and assigning first value to product ID
        {
            infile >> product_name[product_num]; //reading and assigning the second value to product name
            infile >> product_counts[product_num]; //reading and assigning the second value to product count
            infile >> price[product_num]; //reading and assigning the second value to product price
            product_num++;
        }
        
        do
        {
            cout << "Choose one option: " << endl << "1. Print all product names" << endl << "2. Search for product by ID number" << endl << "3. Create list of low inventory items"<< endl << "0. Exit" << endl << endl;
                
            cout << "Your choice is (enter the number from 0-3) ";
            cin >> user_input;
            
            if(user_input==0) // if user type "O", the program print information that the program ended.
                cout << "You choose \"" << user_input << ". Exit\", the program ended." << endl;
            
            switch(user_input)
            {
                case 1:
                    printProductNames(product_name, product_num);
                    cout << endl;
                    break;
                case 2:
                    cout << "What is the product Id number? ";
                    cin >> user_inputId;
                    found_id_index = binaryProductSearch(user_inputId , product_ID_num, product_num);
                    if(found_id_index == -1)
                    {
                        cout << "Your search Id " << user_inputId << " can not be found in the array." << endl << endl;
                    }
                    else
                    {
                        cout << "Your search Id " << user_inputId << " was found." << endl << endl << "Product name: " << endl << product_name[found_id_index] << "." << endl << "Product amount: " << endl << product_counts[found_id_index] << endl << "Product price: " << endl << price[found_id_index] << endl << endl;
                    }
                    break;
                case 3:
                    cout << "What is the minimum amount of the product, to be consider as sufficient inventory? ";
                    cin >> min_count;
                    cout << "The low inventory have: " << endl;
                    printInventory(min_count, product_name, product_counts, product_num);
                    cout << endl;
                    break;
                default:
                    break;
            }
            
        }while(user_input!=0);
        
        
    }
    else// when the program won't open the file succesfully
    {
        cout << "error reading" << endl;
    
    }
    return 0;
}


void printProductNames(const string nameArr[], int SIZE)
{
    for(int i = 0; i< SIZE; i++)
    {
        cout <<nameArr[i] << endl;
    }
}

int binaryProductSearch( int productId , const int productIDArr[], int SIZE)
{
    int firstIdindex = 0;
    int lastIdindex = SIZE - 1;
    bool found = false;
    int position = -1;
   
    
    while(!found && firstIdindex <= lastIdindex)
    {
        int middleIdindex = (firstIdindex+lastIdindex)/2;
        if(productIDArr[middleIdindex] == productId)
        {
            found = true;
            position = middleIdindex;
        }
        else if(productIDArr[middleIdindex] > productId)
            lastIdindex = middleIdindex-1;
        else
            firstIdindex = middleIdindex +1;
    }

    return position;
}

void printInventory(int lowInventory, const string nameArr[], const int productCountArr[], int SIZE)
{
    for(int i =0; i<SIZE; i++)
    {
        if(productCountArr[i]<lowInventory)
            cout << nameArr[i] << endl;
    }
}
