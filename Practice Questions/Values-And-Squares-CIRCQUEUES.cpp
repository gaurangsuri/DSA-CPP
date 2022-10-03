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
            cout<<"queue finished"<<endl<<endl;
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
class outernode{
    public:
    queue q;
    outernode* right;
    outernode* left;
};
class circqueue{
    public:
    outernode* first;
    outernode* last;

    circqueue(){
        first=last=NULL;
    }

    void enqueue(queue x){
        outernode* temp = new outernode();
        temp->q=x;
        if(first==NULL){
            first=temp;
            last=temp;
            temp->left=last;
            temp->right=first;
        }else{
            last->right=temp;
            temp->left=last;
            temp->right=first;
            last=temp;
        }
    }

    void view(){
        outernode* temp = first;
        do{
            temp->q.viewQueue();
            temp=temp->right;
        }while(temp!=first);
    }
};
int main(){
    circqueue q1;
    queue cq1;
    queue cq2;
    int n;
    cout<<"enter the number of elements :- ";
    cin>>n;
    cout<<"enter your elements :- "<<endl;
    while(n!=0){
        int temp;
        cin>>temp;
        cq1.push(temp);
        temp = temp*temp;
        cq2.push(temp);
        n--;
    }
    //---------------------------
    cout<<endl<<endl<<endl;
    q1.enqueue(cq1);
    q1.enqueue(cq2);
    q1.view();
}