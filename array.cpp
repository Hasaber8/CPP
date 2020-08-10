// Program to take 5 values from the user and store them in an 1D and 2D array
// Print the element stored in the array
#include <iostream>
using namespace std;
int main() 
{
    
    int values[5];
    cout<<"Enter 5 intergers:-\n";
    //taking input and storing it in array
    for(int i = 0; i < 5; i++){
        cin>>values[i];
    }
    cout<<"Display integers:-\n";
    // Printing elements of any array
    for(int i = 0; i < 5; i++){
        cout<<values[i];
    }

    int numbers[2][3];

    cout << "Enter 6 numbers: " << endl;

    // Storing user input in the array
    for (int i = 0; i < 2; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            cin >> numbers[i][j];
        }
    }

    cout << "The numbers are: " << endl;

    //  Printing array elements
    for (int i = 0; i < 2; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            cout << "numbers[" << i << "][" << j << "]: " << numbers[i][j] << endl;
        }
    }
    return 0;
}    