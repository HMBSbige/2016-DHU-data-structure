/*
UVa10077 - The Stern-Brocot Number System
Coded by Guojin Zhu
Run Time 22 MS
Accepted on September 21, 2014
*/
#include<iostream>
#include<string>
using namespace std;
///////////////////
struct Fraction{
    int m, n;
    Fraction(int a = 0, int b = 0){m = a; n = b;}
    bool friend operator == (Fraction f1, Fraction f2){
        return f1.m*f2.n == f2.m*f1.n;
    }
    bool friend operator < (Fraction f1, Fraction f2){
        return f1.m*f2.n < f2.m*f1.n;
    }
};
///////////////
class SBNumber{
private:
    Fraction x;  // from input
    string ans;  // for result
public:
    bool readCase(){cin >> x.m >> x.n; return (x.m != 1)||(x.n != 1);}
    void computing();
    void outAns(){cout << ans << endl;}
};
void SBNumber::computing(){
    Fraction lt = Fraction(0, 1);
    Fraction rt = Fraction(1, 0);
    ans.clear();
    while(lt < rt){
        Fraction mid = Fraction(lt.m + rt.m, lt.n + rt.n);
        if(mid == x){
            break;
        }else if(mid < x){
            ans.push_back('R');
            lt = mid;
        }else{// mid > x
            ans.push_back('L');
            rt = mid;
        }
    }
}
int main(){
    SBNumber sbn;
    while(sbn.readCase()){
        sbn.computing();
        sbn.outAns();
    }
    return 0;
}
/*
INPUT
2 3
4 3
5 7
10 14
878 323
1 1
--------
OUTPUT
LR
RLL
LRRL
LRRL
RRLRRLRLLLLRLRRR
*/