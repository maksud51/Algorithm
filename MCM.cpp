#include<iostream>
#include<climits>
#include<stdlib.h>
#include<time.h>

using namespace std;
int s[10][10];

void split(int i, int j){
    if(j-i > 1){
        cout<<"Splitting: T"<<i<<"-T"<<j<<endl;
        int k=s[i][j];
        cout<<"(T"<<i<<"-T"<<k<<")"<<"(T"<<k+1<<"-T"<<j<<")"<<endl;
        split(i,k);
        split(k+1,j);
    }
}

int MatrixChainMultiplication(int p[], int n)
{
    int count=0;
    int m[n+1][n+1];

    for(int i=1; i<=n; i++){
        m[i][i]=0;
    }
    // s matrix
    int i, j, k, L, q;

    for (L=2; L<=n; L++)
    {
        cout<<"L="<<L;
        for (i=1; i<=n-L+1; i++)
        {
            j = i+L-1;
            cout<<"\nM["<<i<<","<<j<<"] ";
            m[i][j] = INT_MAX; //assigning to maximum value
            for (k=i; k<=j-1; k++)
            {
                //simulation
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                cout<<"="<<"M["<<i<<","<<k<<"]+"<<"M["<<k+1<<","<<j<<"]+"<<"d"<<i-1<<"*"<<"d"<<k<<"*"<<"d"<<j<<"\t";
                cout<<"="<<m[i][k]<<"+"<<m[k+1][j]<<"+"<<p[i-1]<<"*"<<p[k]<<"*"<<p[j]<<"="<<q<<"\t";
                cout<<"[k="<<k<<",q="<< q<<"] "<<"\n";


                // print q
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    // s matrix
                    s[i][j]=k;

                }
            }
        }
        cout<<"\n";
    }
    // print M and s matrix
    for(int i=1;i<=n;i++){
        for(int j=1; j<i; j++)
            cout<<"\t";
        for(int j=i;j<=n;j++){
            cout<<m[i][j]<<"\t";
        }
        cout<<"\n";
    }

    cout<<"\n";
    for(int i=1;i<=n;i++){
        for(int j=1; j<i; j++)
            cout<<"\t";
        for(int j=i;j<=n;j++){
            cout<< s[i][j]<<"\t";
        }
        cout<<"\n";
    }

    // show the split
    split(1,n);

   // print operation counts
    return m[1][n];
}

int main()
{
    int n;
    cout<<"Enter number of matrices: ";
    cin>>n;
    int arr[n+1];

    cout<<"Random Input: 0\nUser Input: 1\nOption: ";
    int choice=0;
    cin>>choice;
    if(choice == 0)
    {
        time_t t;
        srand(time(&t));
        for(int i=0; i<=n; i++)
        {
            arr[i]=5+rand()%10;
        }
    }
    else //user input
    {
        for(int i=0; i<=n; i++)
        {
            cout<<"d"<<i<<": ";
            cin>>arr[i];
        }
    }

    cout<<"The matrices are as below:\n";
    for(int i=1; i<=n; i++){
        cout<<"T"<<i<<": "<<arr[i-1]<<" x "<<arr[i]<<endl;
    }
    cout<<"Minimum number of multiplications is "<<MatrixChainMultiplication(arr, n);
    return 0;
}
