#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class ScoreCard{
    public:
    vector<int> sc;

    ScoreCard(vector<int> v){
        sc=v;
    }

    void showScoreCard(){
        cout<<"SCORECARD"<<endl;
        if(sc.empty()){
            cout<<endl;
            cout<<"Sorry! No SCORE found."<<endl;
        }else{
            int total=0;
            int t4=0;
            int t6=0;
            for(int i=0;i<sc.size();i++){
                cout<<sc[i]<<" - ";
                total=total+sc[i];
                if(sc[i]==4){
                    t4++;
                }
                if(sc[i]==6){
                    t6++;
                }
            }
            cout<<endl;
            cout<<"Total: "<<total<<endl;
            cout<<"Total 4s: "<<t4<<" SCORE: "<<4*t4<<endl;
            cout<<"Total 6s: "<<t6<<" SCORE: "<<6*t6<<endl;
        }
    }
};
int main(){
    vector<int> vect = {1,0,1,2,0,1,4,2,0,6,1,6,4,0,2,3,4};
    // vector<int> vect2 = {};
    ScoreCard obj(vect);
    obj.showScoreCard();
    // ScoreCard obj2(vect2);
    // obj2.showScoreCard();
}