#include<bits/stdc++.h>
using namespace std;
struct process{
	int arr; int brst; int brs2; int id; int flg;
	int tat; int wt; int end;
};

bool comp(const process a,const process b){
	if(a.brst==b.brst)
		return a.arr<b.arr;
	return a.brst<b.brst;
}

int main(){
	int n,mnarr=1000; 
	cin>>n;
	struct process pr[n];
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		if(a<mnarr)
			mnarr=a;
		pr[i].arr=a; pr[i].brst=b; pr[i].brs2=b; pr[i].id=i+1;
		pr[i].end=0; pr[i].wt=0; pr[i].tat=0;
	}
	int k=n;
	cout<<endl;
	sort(pr,pr+n,comp);
	for(int i=mnarr;k>0;i++){
		int j=n-k;
		while(pr[j].arr>i)
			j++;
		pr[j].brst--;
		if(pr[j].brst==0){
			k--;
			pr[j].end=i+1;
		}
		cout<<i<<" "<<i+1<<" "<<pr[j].id<<endl;
		sort(pr,pr+n,comp);
	}
	double avtt=0,avwt=0;
	cout<<"id arr brst strt comp tat wt\n";
	for(int i=0;i<n;i++){
		pr[i].tat=pr[i].end-pr[i].arr;
		pr[i].wt=pr[i].tat-pr[i].brs2;
		cout<<pr[i].id<<"     "<<pr[i].arr<<"   "<<pr[i].brs2<<"    "<<pr[i].end<<"   "<<pr[i].tat<<"  "<<pr[i].wt<<"  "<<endl;
		avtt+=pr[i].tat;
		avwt+=pr[i].wt;
	}
	avtt/=n;
	avwt/=n;
	cout<<avtt<<" "<<avwt<<" "<<endl;
	return 0;
}