#include<bits/stdc++.h>

using namespace std;

int check(int mem[4][100],int value,int col){

    for(int i=1;i<=3;i++){
        if(mem[i][col]==value)return 0;
    }
    return 1;
}

int main(){

    ifstream ifile;
    ifile.open("fifo.txt");
    vector<int>vec;

    int mem[4][100];

    for(int i=0;i<19;i++){
        ifile>>mem[0][i];
    }


    for(int i=0;i<3;i++){
        for(int j=1;j<=i+1;j++){
            mem[j][i]=mem[0][j-1];
            cout<<mem[j][i]<<" "<<j<<" "<<i<<endl;
        }
    }
    mem[2][0]=-1;
    mem[3][0]=-1;
    mem[3][1]=-1;

    int cn=1;
    for(int i=3;i<19;i++){
        if(check(mem,mem[0][i],i-1)==0){
            cout<<"head"<<" "<<i<<endl;
            vec.push_back(i);
            //mem[0][i]=mem[][];
            mem[1][i]=mem[1][i-1];
            mem[2][i]=mem[2][i-1];
            mem[3][i]=mem[3][i-1];
        }
        else{

            mem[cn][i] = mem[0][i];
            for(int j=1;j<4;j++)if(j!=cn)mem[j][i]=mem[j][i-1];
            cn++;
            if(cn==4)cn=1;
        }
    }

    vector<int>:: iterator it;
    for(it=vec.begin();it!=vec.end();it++){
        int v=*it;
        for(int j=1;j<4;j++){
            mem[j][v]=-1;
        }
    }

    for(int i=0;i<4;i++){
        //cout<<"index "<<i;
        for(int j=0;j<19;j++){
            cout<<mem[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Page fault : "<<19-vec.size()<<endl;

    return 0;
}
