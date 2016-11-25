/*
UVa11512 - GATTACA
Coded by Guojin Zhu
Run Time 0.284s
AC on September 6, 2012
------------
INPUT
9
AAAAATTTTTGGGGGCCCCGGGGGCCCCAAAAATTTTTGGGGG
AAACAAGAATACCACGACTAGCAGGAGTATCATGATT
GATTACA
GAGAGAG
GATTACAGATTACA
TGAC
TGTAC
TTGGAACC
TTGCACTGACTGTTGCTTGC
-------------
OUTPUT
AAAAATTTTTGGGGG 2
AA 4
A 3
GAGAG 2
GATTACA 2
No repetitions found!
T 2
A 2
ACTG 2
*/
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
using namespace std;
//////////////////////////
const unsigned int bigprime = 100000007;
class GATTACA{
private:
    string strDNA;
    vector<unsigned int> vecDecDNA;
    vector<unsigned int> vecHash;
    vector<unsigned int> weight;
    string strResult;
    int ocurrences;
private:
    unsigned int toDec(char c);
    void genHash(int len);
    bool repeated(int len);
    int binarySearch(int, int);
    void finalResult(int len);
public:
    void genWeight(int n);
    void initial();
    void readDNA();
    void computing();
    void outResult();    
};
void GATTACA::genWeight(int n){
    weight.resize(n);
    weight[0] = 0;
    weight[1] = 1;
    for(int i = 2; i < n; i++){
        weight[i] = (weight[i-1]<<2) % bigprime;
    }
}
void GATTACA::initial(){
    vecDecDNA.clear();
    strResult = "aa";
    ocurrences = 0;
}
unsigned int GATTACA::toDec(char c){
    if(c == 'A'){
        return 0;
    }else if(c == 'C'){
        return 1;
    }else if(c == 'G'){
        return 2;
    }else{
        return 3;
    }
}
void GATTACA::readDNA(){
    getline(cin, strDNA);
    for(int i = 0; i < strDNA.length(); i++){
        vecDecDNA.push_back(toDec(strDNA[i]));
    }
}
void GATTACA::genHash(int len){
    vecHash.clear();
    unsigned int key = 0;
    for(int i = 0; i < len; i++){
        key = ((key << 2) + vecDecDNA[i]) % bigprime;
    }
    vecHash.push_back(key);
    for(int i = len; i < vecDecDNA.size(); i++){
        key = (((key + (bigprime << 2) - weight[len]*vecDecDNA[i-len]) << 2) + vecDecDNA[i]) % bigprime;
        vecHash.push_back(key);
    }
}
bool GATTACA::repeated(int len){
    bool find;
    map<unsigned int, set<string> > hashtable;
    set<string>* pStrSet;
    string str;
    genHash(len);
    find = false;
    for(int i = 0; i < vecHash.size(); i++){
        pStrSet = &(hashtable[vecHash[i]]);
        str = strDNA.substr(i, len);
        if(pStrSet->count(str) < 1){
            pStrSet->insert(str);
        }else{
            find = true;
            break;
        }
    }
    return find;
}
int GATTACA::binarySearch(int left, int right){
    if(left > right){
        return 0;
    }else{
        int mid = (left + right) >> 1;
        if(repeated(mid)){
            return max(mid, binarySearch(mid+1, right));
        }else{
            return binarySearch(left, mid-1);
        }
    }
}
void GATTACA::finalResult(int len){
    bool find;
    map<unsigned int, set<string> > hashtable;
    set<string>* pStrSet;
    string str;
    genHash(len);
    for(int i = 0; i < vecHash.size(); i++){
        pStrSet = &(hashtable[vecHash[i]]);
        str = strDNA.substr(i, len);
        if(pStrSet->count(str) < 1){
            pStrSet->insert(str);
        }else if(str < strResult){
            strResult = str;
            ocurrences = 2;
        }else if(str == strResult){
            ocurrences++;
        }
    }
}
void GATTACA::computing(){
    int len = binarySearch(1, strDNA.length()-1);
    if(len > 0){
        finalResult(len);
    }
}
void GATTACA::outResult(){
    if(ocurrences == 0){
        cout << "No repetitions found!" << endl;
    }else{
        cout << strResult << ' ' << ocurrences << endl;
    }
}   
///////////////////////////
int main(){
    int t;
    GATTACA g;
    string s;
    g.genWeight(1005);
    cin >> t;
    getline(cin, s);
    while(t--){
        g.initial();
        g.readDNA();
        g.computing();
        g.outResult();
    }
    return 0;
}