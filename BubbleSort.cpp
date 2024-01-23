#include<iostream>
using namespace std;

void BubbleSort(int arr[],int s)
{
    for(int i=0;i<s-1;i++)
    {
        for(int j=0;j<s-1;j++)
        {
            if(arr[j+1]<arr[j])
            {
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
       cout<<"SORTED ARRAY";
    for(int i=0;i<s;i++)
    {
        cout<<"------|"<<arr[i]<<"|";
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
 BubbleSort(arr,s);
}

