#include <iostream>
using namespace std;
int getMax(int x, int y)
{
    if(x>y)
    {
        return x;
    }
    else
        return y;

}
void knapsack(int v[], int wt[], int n, int M)
{

    int K[n+1][M+1];
    int i,w;


    for(w=0; w<=M; w++)
    {
        K[0][w]=0;
    }


   for(i=0; i<=n; i++)
    {
        K[i][0]=0;
    }
      int totalCheck=0;
      int updateValue=0;
      int sameValue=0;
    for(i=1; i<=n; i++)
    {  K[i][w]=0;

        for(w=1; w<=M; w++)
        {   totalCheck++;
            if(wt[i]<=w)
            {
                K[i][w] = getMax(K[i-1][w], v[i] + K[i-1][w - wt[i]]);
                updateValue++;

            }
            else

                K[i][w]= K[i-1][w];
        }
    }


    int r = K[n][M];
    for(int item = n; item >0; item--){
        bool found =false;
        for(int j=1; j<= M; j++){
            if(K[item-1][j] == r){
                found =true;
            }
        }

        if(found == false){
            r = r - v[item];
        }
    }

    cout<<"Maximum profit: "<<K[n][M]<<endl;
}
int main()
{
    int n,i,M;
    cout<<"Enter number of items: ";
    cin>>n;
    int wt[n+1], v[n+1];
    for(i=1; i<=n; i++)
    {
        cout<<"Enter weight for item "<<i<<": ";
        cin>>wt[i];
        cout<<"Enter value for item "<<i<<": ";
        cin>>v[i];
    }
    cout<<"Enter Knapsack Capacity: ";
    cin>>M;
    knapsack(v,wt,n,M);
}

