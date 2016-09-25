/***************************/
/* pku3481 Double Queue
/* Coded by Guojin Zhu
/* Run time 516MS
/* AC on Nov. 6, 2011
/***************************/
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
//////////////////////
class DoubleQueue{
private:
    map<int, int> m;
    int intServedClient;
public:
    void initial(){m.clear();}
    void addClient(int k, int p){m[p] = k;}
    void serveHighest(){
        if(m.size() == 0){
            intServedClient = 0;
        }else{
            intServedClient = (*m.rbegin()).second;
            m.erase(--m.end());
        }
    }  
    void serveLowest(){
        if(m.size() == 0){
            intServedClient = 0;
        }else{
            intServedClient = (*m.begin()).second;
            m.erase(m.begin());
        }
    }
    void printServedClient(){printf("%d\n", intServedClient);}  
};
/////////////////////////
int main(){
    int r, k, p;
    DoubleQueue dq;
    dq.initial();
    while(scanf("%d", &r)&&(r != 0)){
        if(r == 1){
            scanf("%d%d", &k, &p);
            dq.addClient(k, p);
        }else if(r == 2){
            dq.serveHighest();
            dq.printServedClient();
        }else if(r == 3){
            dq.serveLowest();
            dq.printServedClient();
        }
    }
    return 0;
}