#include<bits/stdc++.h>

#define V 20
using namespace std;


int index(int arr[V],int temp[3],int n){

     bool tag[3]={false,false,false};
     int cn=0;
     bool g=false;
    if(n<(V-2)){
        for(int i=n;i<V;i++){
            for(int j=0;j<3;j++){
                if(arr[i]==temp[j] && tag[j]==false){
                    tag[j]=true;
                    cn++;
                    if(cn==2){g=true; break;}
                }

            }
            if(g==true)break;
        }
    }

    for(int i=0;i<3;i++){
        if(tag[i]==false)return i;
    }

}

void Optimal(){
    ifstream ifile;
    ifile.open("OptimalFile.txt");
    int arr[V];
    int ans[3][V];
    
    for(int i=0;i<20;i++){
        ifile>>arr[i];
    }
    
    int temp[3]={-1,-1,-1};
    vector<int>head;
    vector<int>fin[100];

    for(int i=0;i<3;i++){
        temp[i] = arr[i];
        for(int j=0;j<3;j++){
            fin[i].push_back(temp[j]);
        }
        for(int j=0;j<3;j++){
            ans[i][j]=temp[j];
        }
    }

    int u=3;
    for(int i=3;i<V;i++){

        bool t = false;
        for(int j=0;j<3;j++){
            if(arr[i]==temp[j]){
                head.push_back(i);
                t=true;
                break;
            }
        }
        if(t==false){
            temp[index(arr,temp,i)] = arr[i];
            for(int k=0;k<3;k++){
                    //cout<<temp[k]<<" ";
                    fin[u].push_back(temp[k]);

            }
            u++;
        }

        //cout<<endl;

    }

    vector<int>:: iterator it;
    cout<<"page head:  ";
    for(it=head.begin();it!=head.end();it++){

        cout<<*it+1<<"  ";

    }
    cout<<endl;
    cout<<endl;
    cout<<"Total Number of Page fault: "<<u<<endl;
    
    for(int i=0;i<u;i++){
        for(int j=0;j<3;j++){
            cout<<fin[i][j]<<" ";
        }
        cout<<endl;
    }

}
