#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* prev;
    node* next;
};
class Stack{
    public:
    node* tail;
    node* head;

    Stack(){
        head=NULL;
        tail=NULL;
    }

    ~Stack(){
        cout<<"STACK DELETED"<<endl<<endl;
    }

    void isEmpty(){
        if(head==NULL){
            cout<<"Stack is empty"<<endl;
        }else{
            cout<<"Stack is not Empty"<<endl;
        }
    }

    void push(int x){
        node* temp = new node();
        temp->data=x;
        temp->next=NULL;
        if(head==NULL){
            head=temp;
            tail=temp;
            temp->prev=NULL;
        }else{
            node* ntemp=head;
            while(ntemp->next!=NULL){
                ntemp=ntemp->next;
            }
            ntemp->next=temp;
            temp->prev=ntemp;
            tail=temp;
        }
    }

    void pop(){
        node* temp = new node();
        if(tail==NULL){
            cout<<"stack is already empty"<<endl;
        }
        temp=tail->prev;
        temp->next=NULL;
        tail=temp;
    }

    void ShowStack(){
        node* temp = new node();
        temp = tail;
        if(tail!=NULL){
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp=temp->prev;
            }
            cout<<"Stack finished"<<endl;
        }else{
            cout<<"Stack empty"<<endl;
        }
    }

    void showLast(){
        if(tail==NULL){
            cout<<"Stack is Empty"<<endl;
        }
        else{
            cout<<"the last enetered element is "<<tail->data<<endl;
        }
    }
};
int main(){
    cout<<"WELCOME TO STACK"<<endl<<endl;
    Stack s;
    bool f = true;
    while(f){
        cout<<"What action would you like to perform"<<endl;
        cout<<"1. add element"<<endl;
        cout<<"2. pop last enetered element"<<endl;
        cout<<"3. show last entered element"<<endl;
        cout<<"4. display the entire stack"<<endl;
        cout<<"5. check if stack is empty or not"<<endl;
        cout<<"6. EXIT"<<endl;
        cout<<endl<<endl;
        int x,n;
        cout<<"Option : ";
        cin>>x;
        switch (x)
        {
        case 1:
            cout<<"element : ";
            cin>>n;
            cout<<endl<<endl;
            s.push(n);
            break;
        case 2:
            s.pop();
            cout<<endl<<endl;
            break;
        case 3:
            s.showLast();
            cout<<endl<<endl;
            break;
        case 4:
            s.ShowStack();
            cout<<endl<<endl;
            break;
        case 5:
            s.isEmpty();
            cout<<endl<<endl;
            break;
        case 6:
            cout<<"program ended"<<endl<<endl;
            f=false;
            break;
        default:
            cout<<"please enter a valid input"<<endl<<endl;
            break;
        }
    }
    return 0;
}