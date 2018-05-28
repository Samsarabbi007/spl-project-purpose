#include<bits/stdc++.h>

using namespace std;

void Priority_Scheduling()

{
    double bt[200],p[200],wt[200],turnaround_time[200],pr[200],total=0,temp,avg_wt,avg_turnaround_time;
    int i,j,n,pos;
    ifstream ifile;
    ifile.open("Priority_schedulingFile.txt");
    
   // cout<<"Enter Total Number of Process:";
    ifile>>n;

    //cout<<"\nEnter Burst Time and Priority\n";
    for(i=0;i<n;i++)
    {
       // cout<<"\nP["<<i+1<<"]\n";
        //cout<<"Burst Time:";
        ifile>>bt[i];
       // cout<<"Priority:";
        //ifile>>pr[i];
                   //process number
    }
	for(i=0;i<n;i++)
    {
    	ifile>>pr[i];
    	p[i]=i+1;
	}
        //sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }

        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    wt[0]=0;            //waiting time for first process is zero

        //waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        total=total+wt[i];
    }

    avg_wt=(float)total/n;      //average waiting time
    total=0;

    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        turnaround_time[i]=bt[i]+wt[i];     //turnaround time
        total=total+turnaround_time[i];
        cout<<"\nP["<<p[i]<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<turnaround_time[i];
    }

    avg_turnaround_time=total/n;     //average turnaround time
    cout<<"\n\nAverage Waiting Time="<<avg_wt;
    cout<<"\nAverage Turnaround Time="<<avg_turnaround_time;
	cout<<endl;
}
