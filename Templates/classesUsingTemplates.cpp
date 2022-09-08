#include<iostream>
using namespace std;
template <class T>
class Box{
    private:
    T a;
    public:
    Box(T x){
        a=x;
    }

    void show(){
        cout<<"Box contains :- "<<a<<endl;
    }
};
int main(){
    Box<int> b1(12);
    Box<char> b2('A');
    Box<string> b3("HELLO");    

    cout<<"displaying :- "<<endl<<endl;
    b1.show();
    b2.show();
    b3.show();
}