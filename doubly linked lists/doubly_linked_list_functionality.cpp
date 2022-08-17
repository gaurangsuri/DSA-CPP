#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
};
class doublyLinkedList{
    public:
    node* head;
    node* tail;

    doublyLinkedList(){
        head=NULL;
        tail=NULL;
    }

    void printDoublyLinkedListFront(){
        node* temp = new node();
        temp=head;
        if(head!=NULL){
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp=temp->next;
            }
            cout<<"list finished"<<endl;
        }else{
            cout<<"list empty"<<endl;
        }
    }

    void printDoublyLinkedListBack(){
        node* temp = new node();
        temp = tail;
        if(tail!=NULL){
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp=temp->prev;
            }
            cout<<"list finished"<<endl;
        }else{
            cout<<"list empty"<<endl;
        }
    }
};
int main(){
    //initialise the doubly linked list
    doublyLinkedList l;

    //add the first node
    node* first = new node();
    first->data = 10;// data
    first->prev = NULL;// pointer to the previous node .. the prev of the head node will ALWAYS be NULL
    first->next = NULL;// pointer to next node is set to NULL at first cause next doesnt exist right now
    l.head=first; // setting this first node as the head of the doubly linked list

    //add second node
    node* second = new node();
    second->data = 20; // data
    second->prev = first; // adding the first node as the prev for the second node
    second->next = NULL; // setting next of second node as NULL at first
    first->next = second; // setting the second node as the next of the first node

    //add third node
    node* third = new node();
    third->data = 30; // data
    third->prev = second; // adding the second node as the prev for the third node
    third->next = NULL; // setting next of third node as NULL at first
    second->next = third; // setting the second node as the next of the first node

    //add second node
    node* fourth = new node();
    fourth->data = 40; // data
    fourth->prev = third; // adding the third node as the prev for the fourth node
    fourth->next = NULL; // setting next of fourth node as NULL at first
    third->next = fourth; // setting the fourth node as the next of the third node

    //add fifth node
    node* fifth = new node();
    fifth->data = 50; // data
    fifth->prev = fourth; // adding the fourth node as the prev for the fifth node
    fifth->next = NULL; // next node of the last node will ALWAYS be NULL
    fourth->next = fifth; // setting the fifth node as the next of the fourth node
    l.tail=fifth;//appointing fifth node as the tail of the doubly linked list and thus ending the doubly linked list here
    cout<<endl<<endl;

    //printing doubly linked list from the front
    cout<<"iterating from the front"<<endl;
    l.printDoublyLinkedListFront();
    cout<<endl<<endl;

    //printing doubly linked list from the back
    cout<<"iterating from the back"<<endl;
    l.printDoublyLinkedListBack();
    cout<<endl<<endl;
}