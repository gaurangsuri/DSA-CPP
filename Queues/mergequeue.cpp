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
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
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
    queue combine(queue q1,queue q2,queue q3){
        node* temp = q1.head;
        node* ntemp=q2.head;
        while(temp!=NULL){
            int t1=temp->data;
            int t2=ntemp->data;
            q3.push(t1);
            q3.push(t2);
            temp=temp->next;
            ntemp=ntemp->next;
        }
        return q3;
    }
};
int main(){
    queue q1;
    q1.push(0);
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    queue q2;
    q2.push(10);
    q2.push(11);
    q2.push(12);
    q2.push(13);
    q2.push(14);
    q2.push(15);
    queue q3;
    q3=q3.combine(q1,q2,q3);
    q3.viewQueue();
}