#include<bits/stdc++.h>
using namespace std;
#define V 20

struct node{
    int value,index;
};

void LeastRecentlyUsed(){
	ifstream ifile;
    ifile.open("LeastRecentlyUsedFile.txt");
    int arr[V];
    vector<int>head;
    for(int i=0;i<20;i++){
        ifile>>arr[i];
    }
    node temp[3];
    int cn=0;
	for(int j=0;j<3;j++){
	
	    for(int i=0;i<=j;i++){
	    	
	        temp[i].value = arr[i];
	        temp[i].index = i+1;
	        cout<<temp[i].value<<" ";
	        
	    }
	    cout<<endl;
	}
	bool bl=false;
    for(int i=3;i<V;i++){
        int tag;
        

        for(int j=0;j<3;j++){
            if(arr[i]==temp[j].value){
                tag=j;
                //cout<<""<<endl;
                bl=true;
                cn++;
                break;
            }
        }
         
        if(bl==true){
			head.push_back(i);
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
		
        for(int k=0;k<3&&bl==false;k++)cout<<temp[k].value<<" ";
        bl=false;
        cout<<endl;
    }
    cout<<"heads ";
    vector<int>::iterator it;
    for(it=head.begin();it!=head.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	cout<<"Total Number of Page fault: "<<V-cn<<endl;
   
}
