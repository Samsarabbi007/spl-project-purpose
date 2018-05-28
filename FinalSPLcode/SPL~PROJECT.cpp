#include<bits/stdc++.h>
#include "Fcfs.cpp"
#include "Sjf_preemtive.cpp"
#include "Sjf_nonpreemtive.cpp"
#include "Priority_Scheduling.cpp"
#include "BankersAlgorithm.cpp"
#include "FIFO.cpp"
#include "Optimal.cpp"
#include "LeastRecentlyUsed.cpp"

using namespace std;
int main()
{	

	
	cout<<"1.This is Fcfs Algorithm"<<endl;
	cout<<"2.This is Sjf_preemtive Algorithm"<<endl;
	cout<<"3.This is Sjf_nonpreemtive Algorithm"<<endl;
	cout<<"4.This is Priority_Scheduling Algorithm"<<endl;	
	cout<<"5.This is Bankers_Algorithm Algorithm"<<endl;
	cout<<"6.This is Page Replaecment(FIFO) Algorithm"<<endl;
	cout<<"7.This is Page Replaecment(Optimal) Algorithm"<<endl;
	cout<<"8.This is Page Replaecment(LeastRecentlyUsed) Algorithm"<<endl;
	cout<<endl<<"press the algorithm number:";

		
	int temp;
	
	for(int i=0;i<8;i++){
		cin>>temp;
		
		if(temp==1)	
			Fcfs();
			
			
		else if(temp==2)	
			Sjf_preemtive();
			
			
		else if(temp==3)	
			Sjf_nonpreemtive();
			
			
		else if(temp==4)	
			Priority_Scheduling();
			
			
		else if(temp==5)
			Bankers_Algorithm();
			
			
		else if(temp==6)	
			FIFO();
			
			
		else if(temp==7)
			Optimal();
			
			
		else if(temp==8)	
			LeastRecentlyUsed();
			
		else{
		
			cout<<"exit";
			break;
		}
	}
	
}
