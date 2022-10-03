#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
};

bool checkPalindrome(int x){
    int n=x;
    int t,sum=0;
    while(x>0){
        t=x%10;
        sum=(sum*10)+t;
        x=x/10;
    }
    if(n==sum){
        return true;
    }else{
        return false;
    }
}

bool checkprime(int n){
    int m = n/2;
    int flag=0;
    for(int i=2;i<=m;i++){
        if(n%i==0){
            flag=1;
        }else{
            continue;
        }
    }
    if(flag==1){
        return false;
    }else{
        return true;
    }
}

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

    void check(){
        node* temp = new node();
        temp = head;
        do{
            int res=0;
            if(checkPalindrome(temp->data) || checkprime(temp->data)){
                res=1;
            }
            if(checkPalindrome(temp->data) && checkprime(temp->data)){
                res=2;
            }
            cout<<temp->data<<" -> "<<res<<endl;
            temp=temp->next;
        }while(temp!=head);
        cout<<endl;
    }

};
int main(){
    CircQueue q;
    int n;
    cout<<"please enter the number of elements :- ";
    cin>>n;
    cout<<"Please enter the elements :- "<<endl;
    while(n!=0){
        int temp;
        cin>>temp;
        q.enqueue(temp);
        n--;
    }
    //------------------------
    cout<<endl<<endl<<endl;
    q.check(); 
}