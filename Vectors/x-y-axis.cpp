#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> x ={10,20,30,40,50};
    vector<int> y={0,0,0,0,0};
    for(int i=0;i<x.size();i++){
        int sum=0;
        for(int j=0;j<x.size();j++){
            if(i==j){
                continue;
            }else{
                sum=sum+x[j];
            }
        }
        y[i]=sum;
    }
    cout<<"X-axis"<<endl;
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
    cout<<"Y-axis"<<endl;
    for(int i=0;i<y.size();i++){
        cout<<y[i]<<" ";
    }
}