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
    int size;
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

    void EvenOddDivide(int n){
        size=n;
        int arr[n];
        cout<<"Please enter the elements :- "<<endl;
        for(int i=0;i<size;i++){
            cin>>arr[i];
        }
        CircQueue Even;
        CircQueue Odd;
        for(int i=0;i<size;i++){
            int temp = arr[i];
            if(temp%2==0){
                Even.enqueue(temp);
            }else{
                Odd.enqueue(temp);
            }
        }
        cout<<endl<<endl;
        cout<<"EVEN :- "<<endl;
        Even.ViewQueue();
        cout<<"ODD :- "<<endl;
        Odd.ViewQueue();
    }

};
int main(){
    CircQueue q1;
    CircQueue q2;
    cout<<"Number of Elements ? :- "<<endl;
    int n;
    cin>>n;
    q1.EvenOddDivide(n);
}