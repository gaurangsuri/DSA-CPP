#include<iostream>
#include<stack>
using namespace std;
class split{
    public:

    void splitarr(int arr[],int n){
        stack<int> q1;
        stack<int> q2;
        int first,second;
        if(n%2==0){
            first=n/2;
            second=n/2;
        }else{
            first=(n+1)/2;
            second=n/2;
        }
        for(int i=0;i<first;i++){
            q1.push(arr[i]);
        }
        for(int j=first;j<n;j++){
            q2.push(arr[j]);
        }
        while(!(q1.empty())){
            int f=q1.top();
            q1.pop();
            cout<<f<<" ";
        }
        cout<<endl;
        while(!(q2.empty())){
            int g=q2.top();
            q2.pop();
            cout<<g<<" ";
        }
    }
};
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    split s;
    s.splitarr(arr,n);
}