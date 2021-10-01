#include<iostream>
#include<fstream>
using namespace std;

int main(){
    char arr[100];
    cout<<"Enter your name and age: "<<endl;
    cin.getline(arr,100);

    fstream myfile("xyz.txt",ios::out|ios::app);
    myfile<<arr;
    myfile.close();
    cout<<"File written successfully\n";

    cout<<"Reading operation started\n";
    char arr1[100];
    ifstream obj("xyz.txt");
    obj.get(arr1,100);
    cout<<"Array content is: "<<arr1<<endl;
    obj.close();
    cout<<"File has been successfully read\n";

    return 0;
}
