#include <iostream>
using namespace std;

int main(){
    int num,den,result;
    cout<<"Enter Numerator"<<endl;
    cin>>num;
    cout<<"Enter Denominator"<<endl;
    cin>>den;

    try
    {
        if (den==0)
        {
            throw den;
        }
        result=num/den;
    }
    catch(int exception)
    {
        cout<<"Dividing by zero not allowed"<<endl;
    }
    cout<<"Division is: "<<result;
    return 0;
}
