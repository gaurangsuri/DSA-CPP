#include<iostream>
using namespace std;

class nodeCollege{
    public:
    string data;
    nodeCollege* prev;
    nodeCollege* next;
};

class DoublyLLCollege{
    public:
    nodeCollege* head;
    nodeCollege* tail;

    DoublyLLCollege(){
        head=NULL;
        tail=NULL;
    }

    void pushBack(string s){
        nodeCollege* temp = new nodeCollege;
        temp->data=s;
        if(tail==NULL){
            head=temp;
            tail=temp;
            temp->next=NULL;
            temp->prev=head;
        }else{
            tail->next=temp;
            temp->prev=tail;
            temp->next=NULL;
            tail=temp;
        }
    }

    void Display(){
        nodeCollege* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

class nodeUniversity{
    public:
    string name;
    DoublyLLCollege ill;
    nodeUniversity* ahead;
    nodeUniversity* behind;
};

class DoublyLLUniversity{
    public:
    nodeUniversity* first;
    nodeUniversity* last;

    DoublyLLUniversity(){
        first=NULL;
        last=NULL;
    }

    void insert(){
        cout<<endl;
        nodeUniversity* temp = new nodeUniversity;
        DoublyLLCollege cll;
        cout<<"Please enter the university name:- ";
        string s;
        cin>>s;
        cout<<endl;
        temp->name=s;
        bool f=true;
        while(f){
            int n;
            cout<<"enter your choice:- "<<endl;
            cout<<"1. enter a college of "<<s<<endl;
            cout<<"2. finish college list and exit. "<<endl;
            cin>>n;
            if(n==1){
                string x;
                cin>>x;
                cll.pushBack(x);
                cout<<endl;
            }else if(n==2){
                f=false;
            }
            else{
                cout<<"please enter a correct choice value... "<<endl;
            }
        }
        temp->ill=cll;
        if(last==NULL){
            first=temp;
            last=temp;
            temp->ahead=NULL;
            temp->behind=first;
        }else{
            last->ahead=temp;
            temp->behind=last;
            temp->ahead=NULL;
            last=temp;
        }
    }

    void print(){
        nodeUniversity* temp = first;
        while(temp!=NULL){
            cout<<"University :- "<<temp->name<<endl;
            DoublyLLCollege cll = temp->ill;
            cout<<"College :- "<<endl;
            cll.Display();
            temp=temp->ahead;
            cout<<endl;
        }
        cout<<endl;
    }
};
int main(){
    DoublyLLUniversity cll;
    cll.insert();
    cll.insert();
    cll.print();
}