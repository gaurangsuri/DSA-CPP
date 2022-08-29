#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
};

class queue{
    public:
    node* head;
    node* tail;

    queue(){
        head=NULL;
        tail=NULL;
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

    void viewQueue(){
        node* temp = new node();
        temp=head;
        if(head!=NULL){
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp=temp->next;
            }
            cout<<"queue finished"<<endl;
        }else{
            cout<<"queue empty"<<endl;
        }
    }

    void pop(){
        node* temp = new node();
        if(head==NULL){
            cout<<"list is already empty"<<endl;
        }
        temp=head->next;
        temp->prev=NULL;
        head=temp;
    }
};
int main(){
    queue q; // initialising queue with values 10 20 30 40 50
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout<<endl<<endl;

    q.viewQueue();
    cout<<endl<<endl;

    // since queue follows first in first out(FIFO) scheme the first entered element will be popped first
    q.pop();
    q.viewQueue();
    cout<<endl<<endl;
}