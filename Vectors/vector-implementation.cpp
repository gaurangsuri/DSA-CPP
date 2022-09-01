#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    vector<int> ss;
    vector<int>::iterator it;
    int choice,item;
    while(1){
        cout<<"\n------------------"<<endl;
        cout<<"vector implementation";
        cout<<"\n------------------"<<endl;
        cout<<"1.insert element into the vector"<<endl;
        cout<<"2.delete last element of the vector"<<endl;
        cout<<"3.Size of the vector"<<endl;
        cout<<"4.display by index"<<endl;
        cout<<"5.display by iterator"<<endl;
        cout<<"6.clear the vector"<<endl;
        cout<<"7.EXIT"<<endl;

        cout<<"enter your choice"<<endl;
        cin>>choice;

        switch(choice){

            case 1:
            cout<<"enter value to be inserted: ";
            cin>>item;
            ss.push_back(item);
            break;

            case 2:
            cout<<"deleteing last element";
            ss.pop_back();
            break;

            case 3:
            cout<<"size of vector: ";
            cout<<ss.size()<<endl;
            break;

            case 4:
            cout<<"displaying vector by index "<<endl;
            for(int i=0;i<ss.size();i++){
                cout<<ss[i]<<endl;
            }
            break;

            case 5:
            cout<<"displaying by iterator "<<endl;
            for(it=ss.begin();it!=ss.end();it++){
                cout<<*it<<endl;
            }
            break;

            case 6:
            cout<<"clearing the vector";
            ss.clear();
            break;

            case 7:
            exit(1);
            break;

            default:
            cout<<"invalid input";
            break;

        }
    }
    return 0;
}