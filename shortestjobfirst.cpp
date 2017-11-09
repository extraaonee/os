#include<bits/stdc++.h>
using namespace std;
struct Node{
    int jobno;
    int at,bt,ct,wt,tat;
};
bool comp1(Node a,Node b){
 return a.at<b.at;
}
bool comp2(Node a,Node b){
 return a.bt<b.bt;
}
bool comp3(Node a,Node b){
 return a.ct<b.ct;
}
int main(){
    int n,i;
    double avgwt=0,avgtat=0;
    cout<<"Enter the Number of Processes:";
    cin>>n;
    Node A[n];
    int x,y;
    cout<<"Enter Arrival Time and Burst Time for each Process:"<<endl;
    for(i=0;i<n;i++){
        cin>>x>>y;
        A[i].jobno=i+1;
        A[i].at=x,A[i].bt=y;
        A[i].wt=0,A[i].ct=0,A[i].tat=0;
    }
    sort(A,A+n,comp1);
    int c=0;
    i=0;
    while(i<n){
        if(i==0){
            c=A[0].at+A[0].bt;
        }else{
        	if(c<A[i].at)
            	c=A[i].at+A[i].bt;
        	else
            	c=A[i-1].ct+A[i].bt;
        }
        int j=i+1;
        for(;j<n;j++)
            if(A[j].at>c)
                break;
        if(i!=j)
            sort(A+i+1,A+j,comp2);
        A[i].ct=c;
        A[i].tat=A[i].ct-A[i].at;
        A[i].wt= A[i].tat-A[i].bt;
        avgwt+=A[i].wt;
        avgtat+=A[i].tat;
        i++;
    }
    sort(A,A+n,comp3);
    cout<<"Average Turnaround Time is: "<<avgtat/n<<endl;
    cout<<"Average Waiting Time is: "<<avgwt/n<<endl;
    cout<<"ProcessNo\tArrTime\tBurstTime\tCompTime\tTATime\tWaitingTime"<<endl;
    for(i=0;i<n;i++)
	cout<<A[i].jobno<<"\t"<<A[i].at<<"\t"<<A[i].bt<<"\t"<<A[i].ct<<"\t"<<A[i].tat<<"\t"<<A[i].wt<<endl;
    return 0;
}
