#include<bits/stdc++.h>

using namespace std;
#define V 20

struct node{
    int value,index;
};

int main(){

    int arr[V]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    node temp[3];
    int cn=0;

    for(int i=0;i<3;i++){
        temp[i].value = arr[i];
        temp[i].index = i+1;
    }

    for(int i=3;i<V;i++){
        int tag;
        bool bl=false;

        for(int j=0;j<3;j++){
            if(arr[i]==temp[j].value){
                tag=j;
                bl=true;
                cn++;
                break;
            }
        }
        if(bl==true){

            if(temp[tag].index==1){
                 for(int k=0;k<3;k++){
                    if(k!=tag){
                        temp[k].index=temp[k].index-1;
                    }
                 }
            }
            else{
                for(int k=0;k<3;k++){
                    if(k!=tag&&temp[k].index!=1){
                        temp[k].index=temp[k].index-1;
                    }
                 }
            }
            temp[tag].index=3;
        }else{
            for(int k=0;k<3;k++){
                if(temp[k].index==1){
                    temp[k].value=arr[i];
                    temp[k].index=3;
                }
                else  temp[k].index=temp[k].index-1;

                //cout<<"    false  "<<k<<"  "<<temp[k].index<<endl;
            }

        }

        for(int k=0;k<3;k++)cout<<temp[k].value<<" ";

        cout<<endl;

    }
    cout<<V-cn<<endl;
}
