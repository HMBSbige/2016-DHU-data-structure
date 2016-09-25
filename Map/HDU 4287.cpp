/*
HDU4287 Intelligent IME
Coded by Guojin Zhu
Run time 265MS
AC on September 10, 2012
--------------
INPUT
1
3 5
46
64448
74
go
in
night
might
gn
---------------
OUTPUT
3
2
0
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
using namespace std;
///////////////////
const string digital = "22233344455566677778889999";
class IntelligentIME{
private:
    vector<string> vecNumSeq;
    vector<string> vecWords;
    map<string, int> mapWords;
    string toDigital(string w);
public:
    void initial();
    void readCase();
    void computing();
    void outResult();
};
void IntelligentIME::initial(){
    vecNumSeq.clear();
    vecWords.clear();
    mapWords.clear();
}
void IntelligentIME::readCase(){
    int n, m;
    scanf("%d%d", &n, &m);
    char s[10];
    string str;
    while(n--){
        scanf("%s", s);
        str = s;
        vecNumSeq.push_back(str);
    }
    while(m--){
        scanf("%s", s);
        str = s;
        vecWords.push_back(str);
    }
}
string IntelligentIME::toDigital(string w){
    for(int i = 0; i < w.length(); i++){
        w[i] = digital[w[i] - 'a'];
    }
    return w;
}
void IntelligentIME::computing(){
    for(int i = 0; i < vecWords.size(); i++){
        mapWords[toDigital(vecWords[i])]++;
    }
}
void IntelligentIME::outResult(){
    for(int i = 0; i < vecNumSeq.size(); i++){
        printf("%d\n", mapWords[vecNumSeq[i]]);
    }
}
/////////////////////
int main(){
    int t;
    IntelligentIME ii;
    cin >> t;
    while(t--){
        ii.initial();
        ii.readCase();
        ii.computing();
        ii.outResult();
    }
    return 0;
}