#include<iostream>
using namespace std;
int main()
{
    int i,n,index,j;
    cout<<"array Size:-";
    cin>>n;
    int age[n];
    for(i=0;i<n;i++)
    {
        cin>>age[i];
    }
    cout<<"input index number(remove):-";
    cin>>index;
    for(j=index;j<n-1;j++)
    {
        age[i]=age[i+1];
    }
    for(i=0;i<n-1;i++)
    {
        cout<<age[i]<<endl;
    }
}
