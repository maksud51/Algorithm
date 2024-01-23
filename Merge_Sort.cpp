#include <iostream>
using namespace std;
void Merge(int arr[], int p, int q, int r){
    int n1=q-p+1;
    int n2=r-q;
    int L[n1];
    int R[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[p+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[q+1+j];
    }

    int i=0;
    int j=0;
    int k=p;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
}
        else{
            arr[k]=R[j];
            j++;
       }
       k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        Merge(arr, l, m, r);
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
    mergeSort(arr,0,s);
    for(int i=0;i<s;i++){
        cout<<"---|"<<arr[i]<<"|";
    }

    return 0;
}
