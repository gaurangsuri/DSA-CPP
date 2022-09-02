#include<iostream>
#include<map>
#include<iterator>
#define MAX 100
using namespace std;
int main(){
    int t;
    cout<<"total number of customers :- ";
    cin>>t;
    map<string, string> cl;
    while(t!=0){
        char id[MAX],name[MAX];
        cin.getline(id,MAX,'-');
        cin.getline(name,MAX);
        cl.insert(pair<string,string>(id,name));
        t--;
    }
    cout<<endl<<endl;
    map<string,string>::iterator itr;
    for(itr=cl.begin();itr!=cl.end();itr++){
        bool sn=false;
        bool even=false;
        if(stoi(itr->first.substr(4))%2==0){
            even=true;
        }
        int n=itr->second.size();
        for(int i=0;i<n;i++){
            if((itr->second)[i]==' '){
                sn=true;
            }
        }
        if(sn==false && even==true){
        cout<<"YES"<<endl;
        }else{
        cout<<"NO"<<endl;
        }
    }
}

//enter customer id-name and if the customer id ends in an even number and the name of the person doesnt contain the surname
//then the output should be yes otherwise no

//EXAMPLE
//csb0112001-Chandan Singh    NO
//csb0112002-Ashish           YES
//csb0112003-Deepak Kumar     NO
//csb0112004-Jerry Hector     NO
//csb0112005-Richa            NO