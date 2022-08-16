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

    void pushFront(int x){
        node* temp=new node();
        temp->data=x;
        temp->next=head;
        head=temp;
    }

    void pushBack(int x){
        node* temp=new node();
        temp->data=x;
        temp->next=NULL;
        if(head==NULL){
            head=temp;
        }
        else{
            node* ntemp = head;
            while(ntemp->next!=NULL){
                ntemp=ntemp->next;
            }
            ntemp->next=temp;
        }
    }

    void insertAtPos(int x,int pos){
        node* temp=new node();
        temp->data=x;
        temp->next=NULL;
        if(pos<1){
            cout<<"position should be >= 1"<<endl;
        }
        else if(pos==1){
            temp->next=head;
            head=temp;
        }
        else{
            int i=1;
            node* ntemp=head;
            while(ntemp->next!=NULL){
                ntemp=ntemp->next;
                i++;
                if(i==(pos-1)){
                    temp->next=ntemp->next;
                    ntemp->next=temp;
                    break;
                }
            }
        }
    }

    void countNodes(){
        node* temp=head;
        if(temp==NULL){
            cout<<0<<endl;
        }
        else{
            int i=0;
            while(temp!=NULL){
                i++;
                temp=temp->next;
            }
            cout<<i<<endl;
        }
    }

};

int main(){
    //feel free to comment any line from main function to see how LL works
    linkedList l;

    l.pushBack(40);
    l.pushBack(50);
    l.pushFront(20);
    l.pushFront(10);

    l.printLinkedList();
    l.countNodes();

    l.insertAtPos(30,3);

    l.printLinkedList();
    l.countNodes();
}