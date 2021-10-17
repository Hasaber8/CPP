#include <iostream>
using namespace std;

class Car
{
    public :
    string model ;
    string colour;
    double speed;


};


int main ()
{

Car BMW;
BMW.model = "325";
BMW.colour = "black";
BMW.speed = 320;
cout<<BMW.model << BMW.colour <<BMW.speed ;
return 0 ;

}
