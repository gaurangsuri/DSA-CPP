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
    node*head;
    node*tail;

    circularlinkedlist(){
        head=NULL;
        tail=NULL;
    }

    void pushFront(int x){
        node* temp = new node();
        temp->data=x;
        if(head==NULL){
            head=temp;
            tail=temp;
            temp->next=tail;
            temp->prev=head;
        }else{
            temp->next=head;
            head->prev=temp;
            temp->prev=tail;
            head=temp;
        }
    }

    void pushBack(int x){
        node* temp = new node();
        temp->data=x;
        if(tail==NULL){
            head=temp;
            tail=temp;
            temp->next=tail;
            temp->prev=head;
        }else{
            tail->next=temp;
            temp->prev=tail;
            temp->next=head;
            tail=temp;
        }
    }

    void insertAtPos(int x,int pos){
        node* temp = new node();
        temp->data=x;
        int i=1;
        node* ntemp=head;
        int j=1;
        while(ntemp!=tail){
            ntemp=ntemp->next; 
            j++;
        }
        ntemp=head;
        if(pos>0 && pos<=j){
                if(ntemp!=NULL){
                while(ntemp!=tail){
                    if(i==(pos-1)){
                        temp->next=ntemp->next;
                        temp->prev=ntemp;
                        ntemp->next->prev=temp;
                        ntemp->next=temp;
                        break;
                    }
                    ntemp=ntemp->next;
                    i++;
                }
            }else{
                head=temp;
                tail=temp;
                temp->next=tail;
                temp->prev=head;
            }
        }else{
            cout<<"please input a valid position"<<endl;
        }
    }

    void popBack(){
        node* temp = new node();
        temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=head;
        tail=temp;
    }

    void popFront(){
        node* temp = head;
        temp=temp->next;
        temp->prev=tail;
        head=temp;
    }

    void popAtPos(int pos){
        node* temp = head;
        int i=1;
        int j=1;
        while(temp!=tail){
            temp=temp->next; 
            j++;
        }
        temp=head;
        if(pos>0 && pos<=j){
            while(temp!=tail){
                if(i==(pos-1)){
                    temp->next=temp->next->next;
                    temp->next->prev=temp;
                    break;
                }
                temp=temp->next;
                i++;
            }
        }else{
            cout<<"please enter a valid position"<<endl;
        }
    }

    int countNodes(){
        node* temp = new node();
        temp=head;
        int i=1;
        while(temp!=tail){
            temp=temp->next;
            i++;
        }
        return i;
    }

    void displayCLLFront(int x){
        node*temp = head;
        int i=1;
        if(temp==NULL){
            cout<<"CIRCULAR LL EMPTY"<<endl;
        }else{
            while(i<=x){
                cout<<temp->data<<endl;
                temp=temp->next;
                i++;
            }
            cout<<"CIRCULAR LL FINISHED"<<endl;
        }
    }

    void displayCLLBack(int x){
        node*temp=tail;
        int i=1;
        if(temp==NULL){
            cout<<"CICULAR LL EMPTY"<<endl;
        }else{
            while(i<=x){
                cout<<temp->data<<endl;
                temp=temp->prev;
                i++;
            }
            cout<<"CIRCULAR LL FINISHED"<<endl;
        }
    }


};
int main(){

    //initiating the circular LL
    circularlinkedlist cl;

    //pushing values 30 20 10 from the front
    cl.pushFront(30);
    cl.pushFront(20);
    cl.pushFront(10);
    //pushing values 40 50 from the back
    cl.pushBack(40);
    cl.pushBack(50);
    cout<<endl<<endl;
 
    //total nodes
    int x=cl.countNodes();

    //iterating through the number of nodes from the front
    cout<<"initial list from front"<<endl<<endl;
    cl.displayCLLFront(x);
    cout<<endl<<endl;
    
    //iterating through the number of nodes from the back
    cout<<"initial list from back"<<endl<<endl;
    cl.displayCLLBack(x);
    cout<<endl<<endl;

    //pushing value 35 at position 4 through push at position method
    cout<<"inserting at pos"<<endl<<endl;
    cl.insertAtPos(35,4);
    x=cl.countNodes();
    cl.displayCLLFront(x);
    cout<<endl<<endl;

    //present CLL is 10 20 30 35 40 50

    //popping at back (last most element) expected output 10 20 30 35 40
    cout<<"POP BACK"<<endl<<endl;
    cl.popBack();
    x=cl.countNodes();
    cl.displayCLLFront(x);
    cout<<endl<<endl;
    //resetting CLL for sake of simplicity
    cl.pushBack(50);

    //popping at front (front most element) expected output 20 30 35 40 50
    cout<<"POP FRONT"<<endl<<endl;
    cl.popFront();
    x=cl.countNodes();
    cl.displayCLLFront(x);
    cout<<endl<<endl;
    // resetting CLL for sake of simplicity
    cl.pushFront(10);

    //popping at position 4 .. expected output 10 20 30 40 50
    cout<<"POP AT POS"<<endl<<endl;
    cl.popAtPos(4);
    x=cl.countNodes();
    cl.displayCLLFront(x);
    cout<<endl<<endl;
}