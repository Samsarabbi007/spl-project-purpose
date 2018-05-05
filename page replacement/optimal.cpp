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

int main(){

    int arr[V]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int ans[3][V];

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
                    cout<<temp[k]<<" ";
                    fin[u].push_back(temp[k]);

            }
            u++;
        }

        cout<<endl;

    }


    cout<<endl<<u<<endl;
    vector<int>:: iterator it;
    for(it=head.begin();it!=head.end();it++){

        cout<<*it<<"  ";

    }
    cout<<endl;
    for(int i=0;i<u;i++){
        for(int j=0;j<3;j++){
            cout<<fin[i][j]<<" ";
        }
        cout<<endl;
    }

}
