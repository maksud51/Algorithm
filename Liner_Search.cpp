#include<iostream>
using namespace std;

 int LS(int arr[],int s,int item)
 {

    for(int i=0;i<s;i++)
    {
        if(arr[i]==item)
        {
            cout<<"Found in index no:- "<<i;
            return 0;
        }
    }
     cout<<"Element don't exist in this array";
 }

int main()
{
 int s,item;
 cout<<"ENTER THE SIZE OF ARRAY: ";
 cin>>s;
 int arr[s];
  cout<<"ENTER THE ELEMENTS: ";
 for(int i=0;i<s;i++)
 {
     cin>>arr[i];
 }
 cout<<"Which element you wants to search: ";
 cin>>item;
 LS(arr,s,item);

}

