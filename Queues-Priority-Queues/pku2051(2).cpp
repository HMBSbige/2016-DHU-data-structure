/*******************************/
/* pku2051 Argus
/* Coded by Guojin ZHU
/* Run time 47ms
/* AC on August 23, 2010
/**************************/
#include <iostream>
#include <queue>
#include <string>
using namespace std;
/////////////////////////
class Query{
private:
    int intQnum;
    int intPeriod;
    int intTimeOfReturn;
public:
    friend bool operator< (Query q1, Query q2){
        return (q2.TimeOfReturn() < q1.TimeOfReturn())
               || ((q2.TimeOfReturn() == q1.TimeOfReturn())&&(q2.Qnum() < q1.Qnum()));
    }
    bool operator = (Query q){
        intQnum = q.Qnum();
        intPeriod = q.Period();
        intTimeOfReturn = q.TimeOfReturn();
    }
    void setQnum(int q){intQnum = q;};
    void setPeriod(int p){intTimeOfReturn = intPeriod = p;};
    int Qnum(){return intQnum;};
    int Period(){return intPeriod;};
    int TimeOfReturn(){return intTimeOfReturn;};
    void nextTime(){intTimeOfReturn += intPeriod;};
};
//////////////////////////////////////////////////////////////
class Argus{
private:
    int k;
    priority_queue<Query> que;
public:
    bool readInput();
    void process();
};
bool Argus::readInput(){
    while (!que.empty()){
        que.pop();
    }
    Query q;
    string str;
    int n, p;
    while ((cin >> str)&&(str != "#")){
        cin >> n >> p;
        q.setQnum(n);
        q.setPeriod(p);
        que.push(q);        
    }
    cin >> k;
    return !cin.eof(); 
}
void Argus::process(){
    Query q;
    for (int i = 0; i < k; i++){
        q = que.top();
        que.pop();
        cout << q.Qnum() << endl;
        q.nextTime();
        que.push(q);
    }
}
/////////////////////////////////
int main(){
    Argus a;
    while (a.readInput()){
        a.process();
    }
    return 0;
}
