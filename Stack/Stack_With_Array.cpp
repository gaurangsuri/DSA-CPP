#include<iostream>
#define maxsize 10
using namespace std;
class Stack{
    int S[10];
    int top = -1;
    public:

    Stack(){
        cout<<"Stack Created"<<endl<<endl<<endl;
    }

    ~Stack(){
        cout<<"STACK DELETED"<<endl<<endl;
    }

    void isEmpty(){
        if(top == -1){
            cout<<"Stack is Empty"<<endl<<endl;
        }else{
            cout<<"Stack is not Empty"<<endl<<endl;
        }
    }
    void push(int x){
        if(top ==maxsize-1){
            cout<<"STACK IS FULL , CANNOT PLACE VALUE "<<x<<" INTO THE STACK"<<endl<<endl;
        }else{
            top++;
            S[top]=x;
        }
    }
    void show(){
        for(int i=0;i<=top;i++){
            cout<<S[i]<<" ";
        }
        cout<<endl<<endl;
    }
    void pop(){
        if(top == -1){
            cout<<"Stack is Empty, cannot pop top-most element."<<endl<<endl;
        }else{
            S[top]=0;
            top = top - 1;
        }
    }
    void ShowTop(){
        if(top == -1){
            cout<<"Stack is Empty"<<endl<<endl;
        }else{
            cout<<"the top-most element is "<<S[top]<<endl;
        }
    }
};
int main(){
    cout<<"WELCOME TO STACK"<<endl<<endl;
    Stack s;
    bool f = true;
    while(f){
        cout<<"What action would you like to perform"<<endl;
        cout<<"1. add element"<<endl;
        cout<<"2. pop last enetered element"<<endl;
        cout<<"3. show last entered element"<<endl;
        cout<<"4. display the entire stack"<<endl;
        cout<<"5. check if stack is empty or not"<<endl;
        cout<<"6. EXIT"<<endl;
        cout<<endl<<endl;
        int x,n;
        cout<<"Option : ";
        cin>>x;
        switch (x)
        {
        case 1:
            cout<<"element : ";
            cin>>n;
            cout<<endl<<endl;
            s.push(n);
            break;
        case 2:
            s.pop();
            cout<<"element deleted"<<endl<<endl;
            break;
        case 3:
            s.ShowTop();
            cout<<endl;
            break;
        case 4:
            s.show();
            cout<<endl<<endl;
            break;
        case 5:
            s.isEmpty();
            break;
        case 6:
            cout<<"program ended"<<endl;
            f=false;
            break;
        default:
            cout<<"Please enter a valid input"<<endl;
            break;
        }
    };
}