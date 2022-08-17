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

    void popBack(){
        node* temp = new node();
        temp = head;
        if(temp == NULL){
            cout<<"list is already empty"<<endl;
        }
        else if(temp->next == NULL){
            head=NULL;
        }
        else{
            while(temp->next->next !=NULL){
                temp = temp->next;
            }
            temp->next = NULL;
        }
    }

    void popFront(){
        node* temp = new node();
        temp=head;
        if(temp==NULL){
            cout<<"list is already empty"<<endl;
        }
        else{
            head = temp->next;
        }
    }

    void popAtPos(int pos){
        node* temp = new node();
        temp=head;
        if(temp==NULL){
            cout<<"list is already empty"<<endl;
        }
        if(pos<1){
            cout<<"please enter valid position"<<endl;
        }
        else if(pos==1){
            head=temp->next;
        }
        else{
            int i=1;
            while(temp->next != NULL){
                if(i==(pos-1)){
                    temp->next = temp->next->next;
                    break;
                }
                temp=temp->next;
                i++;
            }
        }
    }

    void searchByItem(int x){
        node* temp = new node();
        temp=head;
        int i=1;
        bool flag = false;
        while(temp!=NULL){
            if(temp->data == x){
                flag=true;
                break;
            }
            temp=temp->next;
            i++;
        }
        if(flag){
            cout<<"element found at position "<<i<<endl;
        }
        else{
            cout<<"element not found"<<endl;
        }
    }

    void sortLinkedList(){
        node* current = new node();
        node* temp = new node();
        current = head;
        if(current==NULL){
            cout<<"list is empty"<<endl;
        }
        else{
            while(current!= NULL){
                temp=current->next;
                while(temp!=NULL){
                    if(current->data > temp->data){
                        int var = current->data;
                        current->data = temp->data;
                        temp->data = var;
                    }
                    temp=temp->next;
                }
                current = current->next;
            }
        }
    }

};

int main(){
    //feel free to comment any line from main function to see how LL works
    linkedList l;
    cout<<endl<<endl;

    //initialising linked list through insertion at back and insertion at the front
    cout<<"initialising linked list with values 10,20,40,50"<<endl;
    l.pushBack(40);
    l.pushBack(50);
    l.pushFront(20);
    l.pushFront(10);
    cout<<endl<<endl;

    l.printLinkedList();
    l.countNodes();
    cout<<endl<<endl;

    //inserting at a position
    cout<<"inserting element at a pos in linked list"<<endl;
    l.insertAtPos(30,3);
    l.printLinkedList();
    l.countNodes();
    cout<<endl<<endl;

    //pop from back
    cout<<"removing an element from the back in linked list"<<endl;
    l.popBack();
    l.printLinkedList();
    l.countNodes();
    cout<<endl<<endl;

    //pop from front 
    cout<<"removing an element from the front in linked list"<<endl;
    l.popFront();
    l.printLinkedList();
    l.countNodes();
    cout<<endl<<endl;

    //re-setting the LinkedList just for the sake of the program
    l.insertAtPos(10,1);
    l.insertAtPos(50,5);
    l.printLinkedList();
    l.countNodes();
    cout<<endl<<endl;

    //popping an element at a specific position
    cout<<"removing an element from a particular position in linked list"<<endl;
    l.popAtPos(3);//should pop 30 in this case
    l.printLinkedList();
    l.countNodes();
    cout<<endl<<endl;

    //searching linked list for an element
    cout<<"searching linked list for element 40"<<endl;
    l.searchByItem(40);
    cout<<endl<<endl;

    cout<<"searching linked list for element 30"<<endl;
    l.searchByItem(30);
    cout<<endl<<endl;

    cout<<"--------------------------------------------------------------------------------------"<<endl<<endl;

    //making a new linked list to test linked list SORTING
    linkedList l2;
    l2.pushBack(40);
    l2.pushBack(90);
    l2.pushBack(10);
    l2.pushBack(30);
    l2.pushBack(120);
    l2.pushBack(100);
    
    cout<<"before sorting:-"<<endl;
    l2.printLinkedList();
    l2.countNodes();
    cout<<endl<<endl;

    cout<<"after sorting:-"<<endl;
    l2.sortLinkedList();
    l2.printLinkedList();
    l2.countNodes();
    cout<<endl<<endl;
}