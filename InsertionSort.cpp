#include<iostream>
using namespace std;

 void InsertionSort(int arr[],int s)
 {
    int value, hole;
    for(int i=1;i<s;i++)
    {
        value= arr[i];
        hole=i;
        while(hole>0 && arr[hole-1]>value)
        {
            arr[hole]=arr[hole-1];
            hole--;
        }
        arr[hole]=value;

    }
    for(int i=0;i<s;i++)
    {
        cout<<"|"<<arr[i]<<"|---";
    }
 }

int main()
{
 int s;
 cout<<"ENTER THE SIZE OF ARRAY: ";
 cin>>s;
 int arr[s];
  cout<<"ENTER THE ELEMENTS: ";
 for(int i=0;i<s;i++)
 {
     cin>>arr[i];
 }
 cout<<"Sorted Araay:- ";
 InsertionSort(arr,s);

}
