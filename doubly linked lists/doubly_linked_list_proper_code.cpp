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

    void pushFront(int x){
        node* temp = new node();
        if(tail==NULL){
            tail=temp;
        }
        temp->data=x;
        temp->next=head;
        temp->prev=NULL;
        if(temp->next!=NULL){
            temp->next->prev=temp;
        }
        head=temp;

    }

    void pushBack(int x){
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

    void countNodes(){
        node* temp=head;
        if(temp==NULL){
            cout<<0<<endl;
        }
        else{
            int i=1;
            while(temp->next!=NULL){
                temp=temp->next;
                i++;
            }
            cout<<i<<endl;
        }
    }

    void showHead(){
        if(head==NULL){
            cout<<"head node doesnt exist as the list is empty"<<endl;
        }
        else{
            cout<<"the value in the head node is "<<head->data<<endl;
        }
    }

    void showTail(){
        if(tail==NULL){
            cout<<"tail node doesnt exist as the list is empty"<<endl;
        }
        else{
            cout<<"the value in the tail node is "<<tail->data<<endl;
        }
    }

    void insertAtPos(int x,int pos){
        node* temp = new node();
        temp->data=x;
        if(pos<1){
            cout<<"please enter valid position"<<endl;
        }else if(pos==1){
            temp->prev=NULL;
            temp->next=head;
            head=temp;
        }else{
            int i=1;
            node* ntemp=head;
            while(ntemp->next!=NULL){
                if(i==(pos-1)){
                    temp->next=ntemp->next;
                    ntemp->next=temp;
                    temp->prev=ntemp;
                    if(temp->next!=NULL){
                        temp->next->prev=temp;
                    }
                    break;
                }
                ntemp=ntemp->next;
                i++;
            }
        }
    }

    void popFront(){
        node* temp = new node();
        if(head==NULL){
            cout<<"list is already empty"<<endl;
        }
        temp=head->next;
        temp->prev=NULL;
        head=temp;
    }

    void popBack(){
        node* temp = new node();
        if(tail==NULL){
            cout<<"list is already empty"<<endl;
        }
        temp=tail->prev;
        temp->next=NULL;
        tail=temp;
    }

    void popAtPos(int pos){
        node* temp = new node();
        int presPos=1;
        temp=head;
        if(temp==NULL){
            cout<<"list is already empty"<<endl;
        }else{
            while(temp!=NULL){
                if(presPos==pos){
                    node* ntemp=new node();
                    ntemp=temp->prev;
                    ntemp->next=temp->next;
                    ntemp=temp->next;
                    ntemp->prev=temp->prev;
                    if(temp==head){
                        head=temp;
                    }
                    if(temp==tail){
                        tail=temp;
                    }
                }
                temp=temp->next;
                presPos++;
            }
        }
    }

    void searchFromFront(int x){
        node* temp = new node();
        temp=head;
        bool flag = false;
        int i=1;
        if(temp==NULL){
            cout<<"list is empty"<<endl;
        }else{
            while(temp!=NULL){
                if(temp->data==x){
                    cout<<"value found at position "<<i<<"th from the front"<<endl;
                    flag= true;
                    break;
                }
                temp=temp->next;
                i++;
            }
            if(!flag){
                cout<<"element not found"<<endl;
            }
        }
    }

    void searchFromBack(int x){
        node* temp= new node();
        temp=tail;
        bool flag = false;
        int i=1;
        if(temp == NULL){
            cout<<"list is empty"<<endl;
        }else{
            while(temp!=NULL){
                if(temp->data==x){
                    cout<<"value found at position "<<i<<"th from the back"<<endl;
                    flag=true;
                    break;
                }
                temp=temp->prev;
                i++;
            }
            if(!flag){
                cout<<"element not found"<<endl;
            }
        }
    }
};
int main(){
    //feel free to comment any line from main function to see how the doubly LL works
    doublyLinkedList l;

    //initialising linked list through insertion at back and insertion at the front
    cout<<"initialising doubly linked list with values 10,20,30,40,50"<<endl;
    l.pushFront(30); //adds value to the front of the doubly linked list
    l.pushFront(20);
    l.pushFront(10);
    l.pushBack(40); // adds value to the end of the doubly linked list
    l.pushBack(50);
    l.printDoublyLinkedListBack();
    l.countNodes(); // counts total nodes in the doubly linked list
    cout<<endl<<endl;

    //showing head and tail of the doubly linked list
    l.showHead();
    l.showTail();
    cout<<endl<<endl;

    //inserting value midway at any position
    cout<<"inserting value 35 at position 4"<<endl;
    l.insertAtPos(35,4);
    l.printDoublyLinkedListFront();
    l.countNodes();
    cout<<endl<<endl;

    //popping the value at the beginning of the doubly linked list
    cout<<"popping the value at the beginning of the doubly linked list"<<endl;
    l.popFront();
    l.printDoublyLinkedListFront();
    l.countNodes();
    l.showHead();
    cout<<endl<<endl;

    //resetting the doubly linked list for sake of simplicity
    l.pushFront(10);

    //popping the value at the end of the doubly linked list
    cout<<"popping the value at the end of the doubly linked list"<<endl;
    l.popBack();
    l.printDoublyLinkedListFront();
    l.countNodes();
    l.showTail();
    cout<<endl<<endl;

    //resetting the doubly linked list for sake of simplicity
    l.pushBack(50);

    //popping the value at a specific position in the doubly linked list
    cout<<"popping the value at a specific position in the doubly linked list"<<endl;
    l.popAtPos(4);
    l.printDoublyLinkedListFront();
    l.countNodes();
    cout<<endl<<endl;

    //searching an element through the linked list from the front
    cout<<"searching an element (in this case 40) through the linked list from the front"<<endl;
    l.searchFromFront(40);
    l.printDoublyLinkedListFront();
    l.countNodes();
    cout<<endl<<endl;

    //searching an element through the linked list from the back
    cout<<"searching an element (in this case 40) through the linked list from the back"<<endl;
    l.searchFromBack(40);
    l.printDoublyLinkedListBack();
    l.countNodes();
    cout<<endl<<endl;
}