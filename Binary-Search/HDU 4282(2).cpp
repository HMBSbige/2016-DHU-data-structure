/*
HDU4282 A very hard mathematic problem
Coded by Guojin Zhu
Run time 125MS
AC on September 10, 2012
-----------------
INPUT
9
53
6
0
------------------
OUTPUT
1
1
0
*/
#include<iostream>
#include<cmath>
using namespace std;
/////////////////////
const double eps = 0.0000001;
class SearchX{
public:
    double a; // a = y*z
    double b; // b = y^z - k
    int c; // c = z
    bool binary_search(int left, int right);
};
bool SearchX::binary_search(int left, int right){
    if(left > right){
        return false;
    }else{
        int mid = (left + right) >> 1;
        double p = pow(double(mid), c) + a*double(mid) + b;
        if(abs(p) < eps){
            return true;
        }else if(p > 0){
            return binary_search(left, mid - 1);
        }else{
            return binary_search(mid + 1, right);
        }
    }
}
class HardProblem{
private:
    int k;
    int cnt;
public:
    void initial(int a){k = a; cnt = 0;}
    void computing();
    void outResult(){cout << cnt << endl;}
};
void HardProblem::computing(){
    SearchX sx;
    int maxy;
    for(int z = 2; z < 32; z++){
        maxy = int(eps+ pow(double(k), 1.0/double(z)));
        for(int y = 2; y <= maxy; y++){
            sx.a = double(y*z);
            sx.b = pow(double(y), z) - double(k);
            sx.c = z;
            if(sx.binary_search(1, y-1)){
                cnt++;
            }
        }
    }
}
/////////////////////
int main(){
    HardProblem hp;
    int k;
    while((cin >> k) && k){
        hp.initial(k);
        hp.computing();
        hp.outResult();
    }
    return 0;
}