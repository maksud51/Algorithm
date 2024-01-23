#include<iostream>
using namespace std;


void swaping(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(int arr[],int a,int b)
{
    int pivot=arr[b];
    int i=a-1;
    for(int j=a;j<b;j++)
    {
        if(arr[j]<pivot)
        {
           i++;
           swaping(arr,i,j);
        }
    }
    swaping(arr,i+1,b);
    return i+1;

}
void quicksort(int arr[],int a,int b)
{

   if(a<b)
   {
    int piv=partition(arr,a,b);
    quicksort(arr,a,piv-1);
    quicksort(arr,piv+1,b);
   }
}

int main()
{
 int s,i;
 cout<<"ENTER THE SIZE OF ARRAY: ";
 cin>>s;
 int arr[s];
  cout<<"ENTER THE ELEMENTS: ";
 for(i=0;i<s;i++)
 {
     cin>>arr[i];
 }
   int a=0;
   int b=i-1;
  quicksort(arr,a,b);
  cout<<"SORTED ARRAY:-  ";
   for(int j=0;j<s;j++)
 {
     cout<<"---|"<<arr[j]<<"|";
 }
}

