#include<bits/stdc++.h>
using namespace std;
struct Node{
    int priority;
    int index;
    int jobno;
    int at,bt,rt,ct,tat,wt;
    int isvisited;

};
struct Comp{
    bool operator()(const Node& a,const Node& b){
        return a.priority<b.priority;
    }
};
priority_queue<Node,vector<Node>,Comp> pq;
bool comp(Node a,Node b){
    if(a.at==b.at)
        return a.jobno<b.jobno;
    return a.at<b.at;
}
bool comp2(Node a,Node b){
    return a.ct<b.ct;
}
bool check(Node A[],int n){
    for(int i=0;i<n;i++)
        if(A[i].rt)
            return true;
    return false;
}
void addtoqueue(Node A[],int n,int c){
    for(int i=0;i<n;i++){
        if(A[i].at<=c && A[i].rt!=0 && !A[i].isvisited){
            A[i].isvisited=1;
            pq.push(A[i]);
        }
    }
}
int main(){
    cout<<"Enter the Number of Processes"<<endl;
    int n;
    cin>>n;
    Node Job[n];
    cout<<"Enter Priority, Arrival Time and Burst Time"<<endl;
    int x,y,i,priority;
    for(i=0;i<n;i++){
        cin>>priority>>x>>y;
        Job[i].jobno=i+1;
        Job[i].priority=priority;
        Job[i].at=x;
        Job[i].bt=y;
        Job[i].rt=y;
        Job[i].ct=0,Job[i].tat=0,Job[i].wt=0,Job[i].isvisited=0;
        Job[i].index=0;
    }
    //Sort According to Arrival Time
    sort(Job,Job+n,comp);
    for(i=0;i<n;i++)
        Job[i].index=i;
    //Priority Scheduling
    double avgwt=0,avgtat=0;
    int c=Job[0].at;
    addtoqueue(Job,n,c);
    while(check(Job,n) || pq.empty()==false){
        int nd=pq.top().index;
        pq.pop();
        c++;
        addtoqueue(Job,n,c);
        Job[nd].rt--;
        if(Job[nd].rt==0){
            Job[nd].ct=c;
            Job[nd].tat=Job[nd].ct-Job[nd].at;
            Job[nd].wt=Job[nd].tat-Job[nd].bt;
            avgwt+=Job[nd].wt;
            avgtat+=Job[nd].tat;
        }else{
            pq.push(Job[nd]);
        }
        if(pq.empty()){
            for(i=0;i<n;i++)
                if(Job[i].isvisited==false)
                    break;
            int temp=c-Job[i].at-1;
            c+=temp;
        }
    }
    sort(Job,Job+n,comp2);
    cout<<"Average waiting time "<<avgwt/n<<endl;
    cout<<"Average TAT time "<<avgtat/n<<endl;
    cout<<"JobNo\tAT\tBT\tCT\tTAT\tWT"<<endl;
    for(i=0;i<n;i++)
        cout<<Job[i].jobno<<"\t"<<Job[i].at<<"\t"<<Job[i].bt<<"\t"<<Job[i].ct<<"\t"<<Job[i].tat<<"\t"<<Job[i].wt<<endl;
return 0;
}
