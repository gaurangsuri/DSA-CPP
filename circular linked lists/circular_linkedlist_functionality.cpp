#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* prev;
    node* next;
};
class circularlinkedlist{
    public:
    node* head;
    node* tail;

    circularlinkedlist(){
        head=NULL;
        tail=NULL;
    }

    void printCircularLinkedListFront(int x){
        node* temp = new node();
        temp=head;
        if(head!=NULL){
            int i=1;
            while(i<=x){
                cout<<temp->data<<endl;
                temp=temp->next;
                i++;
            }
            cout<<"list finished"<<endl;
        }else{
            cout<<"list empty"<<endl;
        }
    }

};
int main(){
    //initializing the circular linked list
    circularlinkedlist cl;

    //adding the first node
    node* first = new node();
    first->data = 10; // data in the node
    first->prev = cl.tail; // pointer to the previous node , in circular LL the prev of the head node will always be the tail node
    first->next=NULL; // pointer to the next node since it doesnt exist right now it is set to null
    cl.head=first; // making this first node as the head of the circluar LL

    //adding the second node
    node* second = new node();
    second->data=20; // data
    second->prev = first; // previous of second node is the first node
    second->next=NULL; // next of second node is null cause third doesnt exist right now
    first->next=second; // setting the second node as the next of the first node

    //adding the third node
    node* third = new node();
    third->data=30; // data 
    third->prev=second; // setting prev of third node as the second node
    third->next= cl.head; // setting next of the last node as head so it re=iterates to the front
    second->next=third; // setting next of second node to third
    cl.tail=third; // declaring third node as the tail of the circular LL

    //specifying how many times we want to iterate through the circular linked list
    int x = 10;
    cl.printCircularLinkedListFront(x); // this function will therefore iterate through the linked list ten times before stopping .. therefore 
    // output should be 10 20 30 10 20 30 10 20 30 10 
}