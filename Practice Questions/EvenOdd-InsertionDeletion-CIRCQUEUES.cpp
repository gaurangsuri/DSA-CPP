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

    CircQueue rep(CircQueue q){
        int d=q.getHead()->data;
        q.dequeue();
        cout<<d<<" element deleted."<<endl;
        if(d%2==0){
            int temp;
            label:
            cout<<d<<" was even so please enter an odd number to add to the queue..."<<endl;
            cin>>temp;
            if(temp%2==0){
                cout<<"ERROR"<<endl;
                goto label;
            }else{
                q.enqueue(temp);
            }
        }else{
            int temp;
            baan:
            cout<<d<<" was odd so please enter an even number to add to the queue..."<<endl;
            cin>>temp;
            if(temp%2==1){
                cout<<"ERROR"<<endl;
                goto baan;
            }else{
                q.enqueue(temp);
            }
        }
        return q;
    }

    node* getHead(){
        node* temp = head;
        return temp;
    }

    node* getTail(){
        node* temp = tail;
        return temp;
    }
};
int main(){
    int n;
    cout<<"Total elements ? :- "<<endl;
    cin>>n;
    CircQueue q;
    cout<<"Please enter the Elements :- "<<endl;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        q.enqueue(temp);
    }
    cout<<"initial Circular queue created ... "<<endl;
    cout<<"Carrying out new odd/even replace function"<<endl;
    bool f=true;
    while(f){
        q=q.rep(q);
        cout<<endl<<endl;
        q.ViewQueue();
        cout<<endl<<endl;
        cout<<"Quit/continue ?(Y/N)";
        char a;
        cin>>a;
        if(a=='N' || a=='n'){
            break;
        }else if(a=='Y' || a=='y'){
        }else{
            cout<<"INVALID INPUT"<<endl;
            break;
        }
    }
    cout<<endl<<endl<<"FINAL QUEUE :- "<<endl;
    q.ViewQueue();
}