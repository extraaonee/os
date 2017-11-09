#include<bits/stdc++.h> 
using namespace std; 
struct s{ 
        int a[3],b[3]; 
        int p; 
};
void fun(int a,int b,int c,vector<s> ar,vector <int> v){ 
        if(ar.size()==0){ 
                for(int i=0;i<v.size();i++) 
                cout<<"P "<<v[i]<<"  "; 
                cout<<endl; 
                return; 
        } 
        for(int i=0;i<ar.size();i++){ 
                if(ar[i].b[0]<=a&&ar[i].b[1]<=b&&ar[i].b[2]<=c){ 
                        v.push_back(ar[i].p); 
                        s arr=ar[i]; 
                        a+=ar[i].a[0]; 
                        b+=ar[i].a[1]; 
                        c+=ar[i].a[2]; 
                        ar.erase(ar.begin()+i); 
                        fun(a,b,c,ar,v); 
                        v.pop_back(); 
                        a-=arr.a[0]; 
                        b-=arr.a[1]; 
                        c-=arr.a[2]; 
                        ar.insert(ar.begin()+i,arr); 
                } 
        } 
} 
int main(){ 
        int n; 
        cout<<"Enter no. of programs "; 
        cin>>n; 
        vector<s> ar(n); 
        vector <int> v;          
        cout<<"Enter pID, MaxReq and Resources allocated"; 
        for(int i=0;i<n;i++){ 
        		cin>>ar[i].p>>ar[i].b[0]>>ar[i].b[1]>>ar[i].b[2]>>ar[i].a[0]>>ar[i].a[1]>>ar[i].a[2]; 
                ar[i].b[0]=ar[i].b[0]-ar[i].a[0]; 
                ar[i].b[1]-=ar[i].a[1]; 
                ar[i].b[2]-=ar[i].a[2]; 
        } 
        cout<<"Enter available resources: "; 
        int a,b,c; 
        cin>>a>>b>>c; 
        fun(a,b,c,ar,v);          
}
