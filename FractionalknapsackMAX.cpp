#include<iostream>
using namespace std;
int knapsack(int w,double price[],double weight[],double ppw[],int s,double a[])
{
   int max,temp=0;
   for(int i=0;i<s;i++)
   {
        max=i;
       for(int j=i+1;j<s;j++)
       {
           if (ppw[j]>ppw[max])
           {
               max=j;
           }
       }
       temp=ppw[max];
       ppw[max]=ppw[i];
       ppw[i]=temp;

       temp=price[max];
       price[max]=price[i];
       price[i]=temp;

       temp=weight[max];
       weight[max]=weight[i];
       weight[i]=temp;
   }
   cout<<" RATIO "<<" PRICE "<<" WEIGHT"<<endl;
   for(int i=0;i<s;i++)
   {
       cout<<" "<<ppw[i]<<"   "<<"   "<<price[i]<<"  "<<"   "<<weight[i]<<" "<<endl;
   }
   int p;
   for(p=0;p<s;p++)
   {
       if(weight[p]>w)
       {break;}
       a[p]=1;
       w=w-weight[p];
   }
   if(p<=s)
   {
       a[p]=w/weight[p];
   }
}
void cal(int s,double a[],double price[])
{
    double sum=0;
    for(int i=0;i<s;i++)
    {
        sum=sum+a[i]*price[i];
    }
    cout<<"THE PROFIT IS: "<<sum;
}

int main()
{
    int s,w,temp=0;
    cout<<"What is the size of bag: "<<endl;
    cin>>w;
    cout<<"Enter number of items"<<endl;
    cin>>s;
    double  a[s],price[s],weight[s],ppw[s];
    cout<<"Enter the prices"<<endl;
    for(int i=0;i<s;i++)
    {
        cin>>price[i];
    }
 cout<<"Enter the weights"<<endl;
     for(int i=0;i<s;i++)
    {
        cin>>weight[i];
    }
     for(int i=0;i<s;i++)
    {
        ppw[i]=price[i]/weight[i];
    }
    knapsack(w,price,weight,ppw,s,a);
    cal(s,a,price);
    return 0;
}
