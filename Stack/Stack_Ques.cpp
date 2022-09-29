#include<iostream>
using namespace std;
class node{
    public:
    char data;
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

    // ~Stack(){
    //     cout<<"STACK DELETED"<<endl<<endl;
    // }

    void isEmpty(){
        if(head==NULL){
            cout<<"Stack is empty"<<endl;
        }else{
            cout<<"Stack is not Empty"<<endl;
        }
    }

    void push(char x){
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

    bool searchByElement(char x){
        node* temp = new node();
        temp=head;
        while(temp!=NULL){
            if(temp->data==x){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

    int countNodes(){
        node* temp=head;
        if(temp==NULL){
            return 0;
        }
        else{
            int i=1;
            while(temp->next!=NULL){
                temp=temp->next;
                i++;
            }
            return i;
        }
    }

};
int main(){
    Stack s1;
    Stack s2;
    Stack s3;
    Stack S;
    //stack 1
    s1.push('B');
    s1.push('F');
    //stack 2
    s2.push('E');
    s2.push('C');
    s2.push('D');
    // stack 3
    s3.push('A');
    s3.push('G');
    //total number of elements to be added
    int total = s1.countNodes() + s2.countNodes() + s3.countNodes();
    // make a new stack with elements of stack 1-3 in order of A-B-C-D-E-F-G
    int ascA=65;
    for(int i=0;i<total;i++){
        if(s1.searchByElement(char(ascA)) || s2.searchByElement(char(ascA)) || s3.searchByElement(char(ascA))){
            S.push(char(ascA));
            ascA++;
        }else{
            cout<<"elemenet not found \n ERROR"<<endl;
            return 0;
        }
    }
    S.ShowStack();
}