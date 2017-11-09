#include<bits/stdc++.h>
using namespace std;

struct process{
	int id,at,bt,ct,wt,tat,pri;
};

bool comp(process a, process b){
	if(a.pri != b.pri)
		return a.pri < b.pri;
	else if(a.at != b.at)
		return a.at < b.at;
	else return a.id < b.id;  
}

bool com(process a, process b){
	return a.id<b.id;
}

int main(){
	vector <process> p;
	int i,n;
	cin>>n;
	i=n;
	vector<int> completed(n+1,0);
	while(i--){
		process temp;
		cout<<"Enter Arrival time and Burst time for process: "<<n-i<<endl;
		temp.id = n-i;
		cin>>temp.at>>temp.bt;
		p.push_back(temp);
	}
	int time = 0,count=0,taken=0;
	while(count<n)
	{
		float mm = INT_MIN;
		int maxIndex=0;
		for(int i=0;i<n;i++){
			if(p[i].at<time && completed[i]==0)
				if((time-p[i].at+p[i].bt)/p[i].bt  > mm){
					mm=(time-p[i].at+p[i].bt)/p[i].bt;
					maxIndex=i;
					taken=1;
				}
		}
		
		if(taken){
			cout<<"take: "<<maxIndex<<", ";
			p[maxIndex].ct = time + p[maxIndex].bt - 1 ;
			time += p[maxIndex].bt;
			completed[maxIndex]=1;
			count++;
		}
	
		if(taken==0) time++;
		taken=0;
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		p[i].tat = p[i].ct-p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
	}	
	sort(p.begin(),p.begin(),com);
	cout<<"Id	|  A.T. |  B.T. | C.T.  | W.T.  | T.A.T. \n";
	for( int i=0;i<n;i++)
		cout<<p[i].id<<"	|"<<p[i].at<<"	|"<<p[i].bt<<"	|"<<p[i].ct<<"	|"<<p[i].wt<<"	|"<<p[i].tat<<endl;
	return 0;
}
