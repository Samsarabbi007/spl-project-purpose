#include<iostream>
#include<vector>

using namespace std;

int main() {
    int work[4];
    int allocation[5][4];
    int max[5][4];
    int need[5][4];
    int p,pr,r,a,aval[4],req[4];
    bool state[5],test;
    vector <int>avl;
    //----------------------------------------
    test=true;
    for(int i=0;i<4;i++)
        work[i]=aval[i];
    for(int i=0;i<5;i++)
        state[i]=false;


    //-------------enter process & recourses---------------
    cout<<"Enter the number of processes in the system :";
    cin>>p;
    cout<<"\nEnter the number of recourses :";
    cin>>r;


    //------------enter allocation-------------
    cout<<"\nEnter the allocation :"<<endl;
    if (r==1)
    {
        cout<<"\t A \n";
    }
    else if (r==2)
    {
        cout<<"\t A B \n";
    }
    else if (r==3)
    {
        cout<<"\tA B C\n";
    }
    else if (r==4)
    {
        cout<<"\tA B C D\n";
    }
    for(int i=0;i<p;i++)
    {
        cout<<endl<< "P" <<i<<":\t";
        for(int j=0;j<r;j++)
        {
            cin>>allocation[i][j];
           // cout << " ";
        }
    }
    //----------enter max-----------
    cout<<"\nEnter the MAX :"<<endl;
    if (r==1)
        cout<<"\t A \n";
    else if (r==2)
        cout <<"\tA B\n";
    else if (r==3)
        cout <<"\tA B C\n";
    else if (r==4)
        cout <<"\tA B C D\n";
    for(int i=0;i<p;i++)
    {
        cout<<endl<< "P" <<i<<":\t";
        for(int j=0;j<r;j++)
        {
            cin>>max[i][j];
            need[i][j]=max[i][j]-allocation[i][j];
        }

    }
    //-----------------enter available--------------
    cout << "\nEnter the available number :  ";
    for(int i=0;i<r;i++)
    {
        cin>>aval[i];
        cout<<" ";
    }
    //----------------------enter request---------------------------
    cout<<"\nEnter the number of process want be request  :  ";
    cin>>pr;
    cout<<"\nEnter the request number :  ";
    for(int i=0;i<r;i++)
    {
        cin>>req[i];
        cout<<" ";
    }
    //-----------------------------------COUT----------------------------
    cout<<endl<<"There are "<<p<<" processes in the system."<<endl<<endl;
    cout<<"There are "<<r<<" resource types."<<endl<<endl;
    //----------------------------------cout allocation------------------
    cout<<"The allocation Matrix :"<<endl<<endl;
    cout<<"\t    A B C D";
    for(int i=0;i<p;i++)
    {
        cout<<endl<<"\tP"<<i<<": ";
        for(int j=0;j<r;j++)
        {
            cout<<allocation[i][j]<<" ";
        }
        cout<<endl;
    }
    //----------------------------------cout max---------------
    cout<<endl<<"The Max Matrix is..."<<endl<<endl;
    cout<<"\t    A B C D";
    for(int i=0;i<p;i++)
    {
        cout<<endl<<"\tP"<<i<<": ";
        for(int j=0;j<r;j++)
        {
            cout<<max[i][j]<<" ";
        }
        cout<<endl;
    }
    //--------------------cout need--------------------------
    cout<<endl<<"The Need Matrix is...  "<<endl<<endl;
    cout<<"\t    A B C D";
    for(int i=0;i<p;i++)
    {
        cout<<endl<<"\tP"<<i<<": ";
        for(int j=0;j<r;j++)
        {
            cout<<need[i][j]<<" ";
        }
        cout<<endl;
    }
    //----------------------------- cout available ---------------------
    cout<<endl<<"The Available Vector is..."<<endl<<endl;
    cout<<"A B C D"<<endl;
    for(int i=0;i<r;i++)
    {
        cout<<aval[i]<<" ";
    }
    //-----------------------------------SAFE STATE-----------------------
    int k=0;
    for(k=0;k<p;k++) {
        if(state[k]==false) {
            test=false;
            for(int j=0;j<r;j++) {
                if(need[k][j]>work[j])
                    break;
                if(need[k][j]<=aval[j])
                    test=true;
            }
        }
    }
    if(test==true) {
        for(int j=0;j<r;j++)
        {
            work[j]=work[j]+allocation[k][j];
        }
        state[k]=true;
        cout<<endl<<endl<<"THE SYSTEM IS IN A SAFESTATE!"<<endl;
    }
    if(test==false){
        state[k]=false;
        cout<<endl<<endl<<"THE SYSTEM IS NOT IN A SAFE STATE!";
    }
    //-----------------------------------request------------------------
    cout<<"\nThe Request Vector is..."<<endl;
    cout<<"  A B C D"<<endl;
    cout<<pr<<":";
    for(int i=0;i<r;i++)
    {
        cout<<req[i]<<" ";
    }
    bool test2=false;
    for(int i=0;i<p;i++){
        if(pr==p){
            for(int j=0;j<r;j++)
            {
                if(req[j]<=avl[j]&&req[j]<=need[i][j])
                {
                    test2=true;
                }
                else
                {
                    break;
                }
            }
            if(test2=true)
            {
                for(int n=0;n<r;n++)
                {
                    aval[n]=aval[n]-req[n];
                    allocation[i][n]=allocation[i][n]+req[n];
                    need[i][n]=need[i][n]-req[n];
                }
                cout<<"THE REQUEST CAN BE GRANTED!"<<endl<<endl;
                cout<<"The Available Vector is...";
                cout<<"A B C D"<<endl;
                for(int x=0;x<r;x++)
                {
                    cout<<aval[x]<<" ";
                }
            }
            else
            {
                cout<<"THE REQUEST CANNOT BE GRANTED!"<<endl<<endl;
            }
        }
    }
    return 0;
}
