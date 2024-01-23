#include <iostream>
using namespace std;

struct Activity{
    int startTime;
    int finishTime;
};

void activitySelection(Activity a[], int n){
    int i,j;
    cout<<a[0].startTime<<" "<<a[0].finishTime<<endl;
    i=0;
    for(j=i+1;j<n;j++){
        if(a[j].startTime >= a[i].finishTime){
            cout<<a[j].startTime<<" "<<a[j].finishTime<<endl;
            i=j;
        }
    }

}

int main()
{
    int n;
    cout << "Number of activities: " << endl;
    cin>>n;
    Activity act[n];
    Activity temp;
    for(int i=0;i<n;i++){
        cout<<"Enter start time of the ride no: "<<i+1<<endl;
        cin>>act[i].startTime;
        cout<<"Enter the finish time of the ride"<<endl;
        cin>>act[i].finishTime;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(act[i].finishTime > act[j].finishTime){
                temp=act[i];
                act[i]=act[j];
                act[j]=temp;
            }
        }
    }

    activitySelection(act,n);

    return 0;
}

