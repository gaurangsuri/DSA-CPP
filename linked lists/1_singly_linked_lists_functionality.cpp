#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};
class linkedList{
    public:
    node* head;

    linkedList(){
        head = NULL;
    }

    void printLinkedList(){
        node* temp=head;
        if(temp!=NULL){
            cout<<"the list contains :-"<<endl;
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp=temp->next;
            }
            cout<<"List finished"<<endl;
        }
        else{
            cout<<"list empty"<<endl;
        }
    }
};

int main(){
    //initialize linked list
    linkedList l;

    //add first node
    node* first = new node();
    first->data = 100;//data
    first->next = NULL;//pointer to next node is set to NULL at first cause next doesnt exist right now
    l.head=first;//apointing this new node as the head of the linked list so iteration always begins from here

    //add second node
    node* second = new node();
    second->data=20;//data
    second->next=NULL;//address of next
    first->next=second;//setting this new node as the next node to the previous one

    //add third node and repeat same steps
    node* third = new node();
    third->data=40;
    third->next=NULL;
    second->next=third;

    //add fourth node and repeat same steps
    node* fourth = new node();
    fourth->data=59;
    fourth->next=NULL; //this fourth node is the last node in this linked list so the NULL in the next value wont change
    third->next=fourth;

    //print linked list
    l.printLinkedList();
}