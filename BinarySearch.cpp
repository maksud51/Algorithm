#include<iostream>
using namespace std;


 int BS(int arr[],int s,int item)
 {
     int left=0;
     int right=s-1;

    while(left<=right)
    {
        int mid=(right+left)/2;
        if(arr[mid]==item)
        {
            cout<<"Found in index no:- "<<mid;
            return 0;
        }
        else if(arr[mid]<item)
        {
            left=mid+1;
        }
        else if(arr[mid]>item)
        {
            left=mid-1;
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
