/*
POJ1840 Eqs
Coded by Guojin Zhu
Run time 1563MS
AC on September 20, 2012
--------------
INPUT
37 29 41 43 47
37 29 41 43 47
--------------
OUTPUT
654
654
*/
#include<iostream>
#include<map>
using namespace std;
/////////////////
class Eqs{
private:
    int a[5];
    int cnt;
private:
    int Lfun(int x, int y, int z){return a[0]*x*x*x + a[1]*y*y*y + a[2]*z*z*z;}
    int Rfun(int x, int y){return -a[3]*x*x*x - a[4]*y*y*y;}
public:
    void initial(){cnt = 0;}
    bool readCase(){return cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];}
    void computing();
    void outResult(){cout << cnt << endl;}
};
void Eqs::computing(){
    map<int, int> m;
    map<int, int>::iterator it;
    for(int x = -50; x <= 50; x++){
        for(int y = - 50; y <= 50; y++){
            if(x!=0 && y!=0) 
               m[Rfun(x, y)]++;
        }
    }
    for(int x = -50; x <= 50; x++){        
        for(int y = - 50; y <= 50; y++){
            for(int z = -50; z <= 50; z++){
                if(x!=0 && y!=0&& z!=0){
                    it = m.find(Lfun(x, y, z));
                    if(it != m.end()){
                        cnt += it->second;
                    }
                }
            }
        }
   }
 }
////////////////////
int main(){
    Eqs e;
    while(e.readCase()){
        e.initial();
        e.computing();
        e.outResult();
    }
    return 0;
}