#include<iostream>
#include<string>

#include "marvel.h"
using namespace std;
int main(){
    cout<<"SUPERHEROES :-"<<endl<<endl;
    for(int i=0;i<sizeof(superhero);i++){
        cout<<superhero[i]<<endl;
    }
}