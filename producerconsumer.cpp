#include<bits/stdc++.h>
using namespace std;

int process[50];
int counti, rear, front,n;

void produce(int item)
{
	if(counti==n) { cout<<"Buffer Full !!\n"; return; }
	
	rear = (rear+1)%n;
	process[rear] = item;
	counti++;
}

void consume()
{
	if(counti==0){ cout<<"Buffer Empty !!\n"; return ;}
	
	cout<<"Item "<<process[front]<<" executed !\n";
	front = (front+n-1)%n;
	counti--;
	
}

int main()
{
	int cont=1,choice, item;
	cout<<"Please enter the Buffer size : ";
	cin>>n;
	
	counti=0; front=0;rear=-1;
	
	cout<<"Enter your choice : ";
	cin>>choice;
	while(cont)
	{
		switch(choice){
			case 1: cin>>item;
					produce(item);
					break;
			
			case 2:	consume();
					break;
					
			case 3: cont=0;
					exit(0);
				
			case 4: cout<<"Items remaining : " << counti <<endl;
			
		}
	cout<<"Enter your choice : ";
	cin>>choice;
	}
}
