#include<bits/stdc++.h>
using namespace std;

int main(){
	int j,n,m,i;
	cin>>n>>m;
	vector<int> mem(n),pm(m);
	vector<bool> f(n,false);
	for(i=0;i<n;i++)	cin>>mem[i];
	for(i=0;i<m;i++)	cin>>pm[i];
	//First Fit
	cout<<"\nFirst Fit\n";
	for(i=0;i<m;i++){
		bool fl=false;
		for(j=0;j<n;j++){
			if(!f[j] and mem[j]>=pm[i]){
				cout<<"Process "<<i+1<<" in memory "<<j+1<<"\n";
				fl=true;
				f[j]=true;
				break;
			}
		}
		if(!fl)	cout<<"Process "<<i+1<<" didn't get the memory.\n";
	}
	//Best Fit
	cout<<"\nBest Fit\n";
	f.clear();
	f.resize(n,false);
	for(i=0;i<m;i++){
		int k=-1;
		for(j=0;j<n;j++){
			if(!f[j] and mem[j]>=pm[i] and (k==-1 or mem[j]<mem[k])){
				k=j;
			}
		}
		if(k==-1)	cout<<"Process "<<i+1<<" didn't get the memory.\n";
		else{
			cout<<"Process "<<i+1<<" in memory "<<k+1<<"\n";
			f[k]=true;
		}
	}
	//Worst Fit
	cout<<"\nWorst Fit\n";
	f.clear();
	f.resize(n,false);
	for(i=0;i<m;i++){
		int k=-1;
		for(j=0;j<n;j++){
			if(!f[j] and mem[j]>=pm[i] and (k==-1 or mem[j]>mem[k])){
				k=j;
			}
		}
		if(k==-1)	cout<<"Process "<<i+1<<" didn't get the memory.\n";
		else{
			cout<<"Process "<<i+1<<" in memory "<<k+1<<"\n";
			f[k]=true;
		}
	}
	return 0;
}
