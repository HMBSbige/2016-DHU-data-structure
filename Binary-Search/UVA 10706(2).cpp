/*
UVa10706 Number Sequence
Coded by Guojin Zhu
Run time 0.040S
AC on September 21, 2012
-------------
INPUT
2
8
3
-------------
OUTPUT
2
2
*/
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
//////////////////////
string sk;
vector<unsigned> index;
void pushdigit(int k){
    stack<int> digit;
    while(k > 0){
        digit.push(k%10);
        k /= 10;
    }
    while(!digit.empty()){
        sk.push_back(char(digit.top()+ '0'));
        digit.pop();
    }
}
void preprocess(){
    sk.push_back('0');
    index.push_back(0);
    for(int k = 1; index.back() < 2147483647; k++){
        pushdigit(k);
        index.push_back(index.back() + sk.length() - 1);
    }
}
//////////////////////
int main(){
    preprocess();
    vector<unsigned>::iterator it;
    int t, i;
    cin >> t;
    while(t--){
        cin >> i;
        it = lower_bound(index.begin(), index.end(), i);
        it--;
        cout << sk[i - (*it)] << endl;
    }
    return 0;
}







/*
POJ1019 Number Sequence
Coded by Guojin Zhu
Run time 344MSMS
AC on September 22, 2012
-------------
INPUT
2
8
3
-------------
OUTPUT
2
2
*/
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
//////////////////////
class NumberSequence{
private:
    string sk;
    vector<unsigned> index;
    void pushdigit(int k);
public:
    void initial();
    char operator [](int i);
};
void NumberSequence::pushdigit(int k){
    stack<int> digit;
    while(k > 0){
        digit.push(k%10);
        k /= 10;
    }
    while(!digit.empty()){
        sk.push_back(char(digit.top()+ '0'));
        digit.pop();
    }
}
void NumberSequence::initial(){
    sk.push_back('0');
    index.push_back(0);
    for(int k = 1; index.back() < 2147483647; k++){
        pushdigit(k);
        index.push_back(index.back() + sk.length() - 1);
    }
}
char NumberSequence::operator [](int i){
    vector<unsigned>::iterator it;
    it = lower_bound(index.begin(), index.end(), i);
    it--;
    return sk[i - (*it)];
}
//////////////////////
int main(){
    NumberSequence ns;
    ns.initial();
    int t, i;
    cin >> t;
    while(t--){
        cin >> i;
        cout << ns[i] << endl;
    }
    return 0;
}