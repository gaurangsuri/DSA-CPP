#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    vector<int> coin;
    vector<int>::iterator i;
    int choice;
    int item;
    while(1){
        cout<<"----------------------------------"<<endl;
        cout<<"enter the coin values to be sorted"<<endl;
        cout<<"----------------------------------"<<endl;
        cout<<"1. enter coin value "<<endl;
        cout<<"2.Exit and sort "<<endl;
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"enter coin value ";
            cin>>item;
            coin.push_back(item);
            break;

            case 2:
            sort(coin.begin(),coin.end());
            cout<<"sorted list of coins "<<endl;
            for(i=coin.begin();i!=coin.end();i++){
            cout<<*i<<" ";
            }
            exit(1);
            break;

            default:
            cout<<"invalid input"<<endl;
            break;
        }
    }

    return 0;
}
