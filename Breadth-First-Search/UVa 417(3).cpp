/*
UVa417 - Word Index
Coded by Guojin Zhu
Run Time 0.052s
AC on October 1, 2012
*/
#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/////////////////
struct Word{
    string w;
    Word(string s = ""){w = s;}
    bool friend operator < (Word a, Word b){
        if(a.w.length() == b.w.length()){
            return a.w < b.w;
        }else{
            return a.w.length() < b.w.length();
        }
    }
    bool friend operator == (Word a, Word b){
        return a.w == b.w;
    }
};
class WordIndex{
private:
    vector<Word> digit;
public:
    void initial();
    int operator [](string w);
};
void WordIndex::initial(){
    int cnt = 1;
    string w, nw;
    queue<string> q;
    for(char ch = 'a'; ch <= 'z'; ch++){
        cnt++;
        w = ch;
        digit.push_back(Word(w));
        q.push(w);
    }
    while(!q.empty()){//bfs
        w = q.front();
        q.pop();
        //cout << w << endl;
        if( w.length() < 5){
            for(char ch = (*w.rbegin()) + 1; ch <= 'z'; ch++){
                cnt++;
                nw = w + ch;
                digit.push_back(Word(nw)); 
                q.push(nw);
            }
        }
    }
}
int WordIndex::operator [](string w){
    vector<Word>::iterator it;
    it = lower_bound(digit.begin(), digit.end(), Word(w));
    if(it->w == w){//found
        return 1 + int(it - digit.begin());
    }else{//not found
        return 0;
    }
}
///////////////
int main(){
    WordIndex wi;
    wi.initial();
    string s;
    while(cin >> s){
        cout << wi[s] << endl;
    }
    return 0;
}
/*
INPUT
z
a
cat
vwxyz
------------------
OUTPUT
26
1
0
83681
*/