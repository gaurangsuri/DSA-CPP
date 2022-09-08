#include<iostream>
using namespace std;
class table{
    private:
    int x;
    public:
    table(int y){
        x=y;
    }

    void operator()(){
        for(int i=1;i<=10;i++){
            cout<<x<<" x "<<i<<" = "<<x*i<<endl;
        }
    }
};
int main(){
    int n;
    cout<<"Enter a number :- ";
    cin>>n;
    table o(n);
    o();
}