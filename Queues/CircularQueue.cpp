#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
};
class CircQueue{
    public:
    node* head;
    node* tail;

    CircQueue(){
        head=NULL;
        tail=NULL;
    }

    void enqueue(int x){
        node* temp = new node();
        temp->data=x;
        if(head==NULL){
            head=temp;
            tail=temp;
            temp->prev=tail;
            temp->next=head;
        }else{
            tail->next=temp;
            temp->prev=tail;
            temp->next=head;
            tail=temp;
        }
    }

    void ViewQueue(){
        node* temp = head;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
        cout<<endl;
    }

    void dequeue(){
        node* temp = new node();
        temp=head->next;
        temp->prev=tail;
        tail->next=temp;
        head=temp;
    }

    node* getHead(){
        node* temp = head;
        return temp;
    }

    node* getTail(){
        node* temp = tail;
        return temp;
    }
};
int main(){

    CircQueue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.ViewQueue();
    cout<<endl<<endl;
    q1.dequeue();
    q1.ViewQueue();
}