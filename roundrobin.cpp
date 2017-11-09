#include<bits/stdc++.h>
using namespace std;

struct process{
int arr; int brst; int brs2; int id; int flg;
int tat; int wt; int end; int strt; int rsp;
};

bool comp(const process a,const process b){
if(a.arr==b.arr)
return a.id<b.id;
return a.arr<b.arr;
}

int main(){
	int n,q,h=0,t=0,mxarr=0; 
	cin>>n>>q;
	queue<int> qe;
	struct process pr[n];
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		if(a>mxarr)
			mxarr=a;
		pr[i].arr=a; pr[i].brst=b; pr[i].brs2=b; pr[i].id=i+1; pr[i].flg=0; pr[i].end=0;
		pr[i].wt=0; pr[i].tat=0; pr[i].strt=-1; pr[i].rsp=0;
	}
	int k=n;
	cout<<endl;
	sort(pr,pr+n,comp);
	qe.push(0);
	pr[0].flg=1;
	int ii=0,jj=1;
	for(int i=pr[0].arr;k>0;i+=q){
		cout<<i<<" ";
		if(i<=mxarr){
			while(jj<n&&pr[jj].arr<=i+q&&pr[jj].flg==0){
				qe.push(jj);
				pr[jj].flg=1;
				jj++;
			}
		}
		int j=qe.front();
		qe.pop();
		if(pr[j].strt==-1)
			pr[j].strt=i;
		pr[j].flg=0;
		pr[j].brst-=q;
		if(pr[j].brst<=0){
			k--;
			pr[j].end=i+q+pr[j].brst;
			i=i+pr[j].brst;
		}
		else
			qe.push(j);
		cout<<i+q<<" "<<pr[j].id<<endl;
	}
	double avtt=0,avwt=0,avrp=0;
	cout<<"id arr brst strt comp tat wt rsp\n";
	for(int i=0;i<n;i++){
		pr[i].tat=pr[i].end-pr[i].arr;
		pr[i].wt=pr[i].tat-pr[i].brs2;
		pr[i].rsp=pr[i].strt-pr[i].arr;
		cout<<pr[i].id<<"     "<<pr[i].arr<<"   "<<pr[i].brs2<<"  "<<pr[i].strt<<"    "<<pr[i].end<<"   "<<pr[i].tat<<"  "<<pr[i].wt<<"  "<<pr[i].rsp<<"  "<<endl;
		avtt+=pr[i].tat;
		avwt+=pr[i].wt;
		avrp+=pr[i].rsp;
	}
	avtt/=n;
	avwt/=n;
	avrp/=n;
	cout<<avtt<<" "<<avwt<<" "<<avrp<<endl;
	return 0;
}