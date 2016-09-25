/*
UVa10539 Almost Prime Numbers
Coded by Guojin Zhu
Run Time 0.036s
AC on September 24, 2012
---------------
INPUT
4
1 10
1 20
1 5
5 20
---------------
OUTPUT
3
4
1
3
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxsize = 1000010;
///////////////////////
struct PrimeNumbers{
    vector<int> primes;
    void genprimes();
};
void PrimeNumbers::genprimes(){
    bool nonprime[maxsize];
    for(int i = 3; i <= maxsize; i++){
        if(i&1){//i%2 == 1
            nonprime[i] = false;
        }else{
            nonprime[i] = true;
        }
    }
    primes.push_back(2);
    for(int i = 3; i <= maxsize; i++){
        if(!nonprime[i]){
            primes.push_back(i);
            for(int k = i + i; k <= maxsize; k += i){
                nonprime[k] = true;
            }
        }
    }
}
//////////////////////
class AlmostPrimeNumbers{
private:
    long long low;
    long long high;
    long long ans;
    PrimeNumbers pn;
public:
    void initialForAll(){pn.genprimes();};
    void readCase(){cin >> low >> high;};
    void computing();
    void outResult(){cout << ans << endl;}
};
void AlmostPrimeNumbers::computing(){
    double const eps = 1e-6;
    vector<int>::iterator it;
    double key;
    int sumhigh = 0; // the number of almost prime numbers between 1 and high
    int sumlow = 0;  // the number of almost prime numbers between 1 and low
    for(int i = 2; i <= 40;  i++ ){
        key = eps + pow(double(high), 1.0/double(i));
        it = lower_bound(pn.primes.begin(), pn.primes.end(), key);
        sumhigh += int(it - pn.primes.begin());
        key = pow(double(low), 1.0/double(i));
        it = lower_bound(pn.primes.begin(), pn.primes.end(), key);
        sumlow += int(it - pn.primes.begin());
    }
    ans = sumhigh - sumlow;
}
//////////////////////
int main(){
    AlmostPrimeNumbers apn;
    apn.initialForAll();
    int n;
    cin >> n;
    while(n--){
        apn.readCase();
        apn.computing();
        apn.outResult();
    }
    return 0;
}