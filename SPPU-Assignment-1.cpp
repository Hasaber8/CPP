#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

typedef struct student
{
    int roll_num;
    char name [20];
    float marks;
}stud;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void create(stud s[20],int n);
void display(stud s[20],int n);
void bubble_sort(stud s[20],int n);
void insertionSort(stud s[20],int n);
void quick_sort(stud s[20],int,int);
int partition(stud s[20],int,int);
void search(stud s[20],int n,float key);
int bsearch(stud s[20], char x[20],int low,int high);

int main()
{
    stud s[20];
    int ch,n,result;
    float key;
    char x[20];
    do
    {
        cout<<"\n 1) Create Student Database ";
        cout<<"\n 2) Display Student Records ";
        cout<<"\n 3) Bubble Sort (To sort Roll Number wise) ";
        cout<<"\n 4) Insertion Sort (To sort according to the Name) ";
        cout<<"\n 5) Quick Sort (To sort according to the marks)";
        cout<<"\n 6) Linear search ";
        cout<<"\n 7) Binary search  ";
        cout<<"\n 8) Exit ";
        cout<<"\n Enter Your Choice:=";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"\n Enter The Number Of Records:=";
            cin>>n;
            create(s,n);
            break;

            case 2:
            display(s,n);
            break;

            case 3:
            bubble_sort(s,n);
            break;

            case 4:
            insertionSort(s,n);
            break;

            case 5:
            cout<<"\n"<< "\t"<< "Roll No"<< "\t"<<" Name" <<"\t"<< "Marks";
            int n = sizeof(s) / sizeof(s[0]);
	        quickSort(s, 0, n - 1);
	        cout << "Sorted array: \n";
	        printArray(s, n);
            break;

            case 6:
            cout<<"\n Enter the marks which u want to search:=";
            cin>>key;
            search(s,n,key);
            break;

            case 7:
            cout<<"\n Enter the name of student which u want to search:=";
            cin>>x;
                insertionSort(s,n);
                result=bsearch(s,x,0,(n-1));
                if(result==-1)
                {
                cout<<" \n Student name you want to search for is not present ! \n";
                }
                else
                {
                cout<<" \n The student  is present :\t" << s[result].name;
                }
                break;

            case 8:return 0;
                default:cout<<"\n Invalid choice !! Please enter your choice again."<<endl;
        }
    }while(ch!=8);
}
void create(stud s[20],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<"\n Enter the roll number:=";
        cin>>s[i].roll_num;
        cout<<"\n Enter the Name:=";
        cin>>s[i].name;
        cout<<"\n Enter the marks:=";
        cin>>s[i].marks;
    }
}
void display(stud s[20],int n)
{
    int i;
    cout<<"\n"<< "\t"<< "Roll No"<< "\t"<<" Name" <<"\t"<< "Marks";
    for(i=0;i<n;i++)
    {
        cout<<"\n";
    cout<<"\t "<< s[i].roll_num<<"\t "<<s[i].name<<"\t "<<s[i].marks;
    }
}

//bubble sort to sort in ascending order on roll number

void bubble_sort(stud s[20],int n)
{
    int i,j;
    stud temp;
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(s[j].roll_num>s[j+1].roll_num)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}

// insertion sort to sort on names in ascending order

void insertionSort(stud s[20], int n)  
{  
    int i,  j;  
    stud  key;
    for (i = 1; i < n; i++) 
    {  
        key= s[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && strcmp(s[j].name, key.name) >0)
        {  
            s[j + 1]= s[j];  
            j = j - 1;  
        }  
        s[j + 1]= key;  
    }  
}  
  
//Quick sort to sort on marks 

/* The main function that implements QuickSort
stud s[20] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quick_sort(stud s[20], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, stud s[20] is now
		at right place */
		int pi = partition(s, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(s, low, pi - 1);
		quickSort(s, pi + 1, high);
	}
}
 
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (stud s[20], int low, int high)
{
	int pivot = s[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (s[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&s[i], &s[j]);
		}
	}
	swap(&s[i + 1], &s[high]);
	return (i + 1);
}

// linear search for marks if more than one student having same marks print all of them 

void search(stud s[20],int n,float key)
{
    int i;
    cout<<"\n"<< "\t"<< "Roll No"<< "\t"<<" Name" <<"\t"<< "Marks";
    for(i=0;i<n;i++)
    {
        if(key==s[i].marks)
        {
            cout<<"\n\t "<< s[i].roll_num<<"\t "<<s[i].name<<"\t "<<s[i].marks;
        }
    }
}

int bsearch(stud s[20], char x[20],int low,int high)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(strcmp(x,s[mid].name)==0)
        {
            return mid;
        }
        else if(strcmp(x,s[mid].name)<0)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return -1;
}