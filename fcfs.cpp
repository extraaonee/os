#include<bits/stdc++.h>
using namespace std;
struct Node{
    int jobno;
    int at,bt,ct,wt,tat;
};
bool cmp(Node a,Node b){
    if(a.at==b.bt)
        return a.jobno<b.jobno;
    return a.at<b.at;
}
int main(){
    int n,i;
    double avgwt=0,avgtat=0;
    cout<<"Enter the Number of Processes:";
    cin>>n;
    Node Job[n];
    int x,y;
    cout<<"Enter Arrival Time and Burst Time for each Process:"<<endl;
    for(i=0;i<n;i++){
        cin>>x>>y;
        Job[i].jobno=i+1;
        Job[i].at=x,Job[i].bt=y;
        Job[i].wt=0,Job[i].ct=0,Job[i].tat=0;
    }
    //Sort Job According to Arrival Time
    sort(Job,Job+n,cmp);
    //Computing Completion Time of Job
    Job[0].ct=Job[0].bt+Job[0].at;
    for(i=1;i<n;i++){
        if(Job[i-1].ct>Job[i].at)
            Job[i].ct=Job[i].bt+Job[i-1].ct;
        else
            Job[i].ct=Job[i].at+Job[i].bt;
    }
    //Calculating Turnaround Time and Waiting Time of Job
    for(i=0;i<n;i++){
        Job[i].tat=Job[i].ct-Job[i].at;
        Job[i].wt=Job[i].tat-Job[i].bt;
        avgtat+=Job[i].tat;
        avgwt+=Job[i].wt;
    }
    cout<<"Average Turnaround Time is: "<<avgtat/n<<endl;
    cout<<"Average Waiting Time is: "<<avgwt/n<<endl;
    cout<<"ProcessNo\tArrTime\tBurstTime\tCompTime\tTATime\tWaitingTime"<<endl;
    for(i=0;i<n;i++)
	cout<<Job[i].jobno<<"\t"<<Job[i].at<<"\t"<<Job[i].bt<<"\t"<<Job[i].ct<<"\t"<<Job[i].tat<<"\t"<<Job[i].wt<<endl;
    return 0;
}
