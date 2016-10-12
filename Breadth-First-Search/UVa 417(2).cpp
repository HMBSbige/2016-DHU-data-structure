/*
UVa417 - Word Index
Coded by Guojin Zhu
Run Time 0.148s
AC on October 1, 2012
*/
#include<iostream>
#include<queue>
#include<map>
#include<string>
using namespace std;
/////////////////
class WordIndex{
private:
    map<string, int> digit;
public:
    void initial();
    int operator [](string w);
};
void WordIndex::initial(){
    int cnt = 1;
    string w, nw;
    queue<string> q;
    for(char ch = 'a'; ch <= 'z'; ch++){
        w = ch;
        digit[w] = cnt++;
        q.push(w);
    }
    while(!q.empty()){//bfs
        w = q.front();
        q.pop();
        //cout << w << endl;
        if( w.length() < 5){
            for(char ch = (*w.rbegin()) + 1; ch <= 'z'; ch++){
                nw = w + ch;
                digit[nw] = cnt++;
                q.push(nw);
            }
        }
    }
}
int WordIndex::operator [](string w){
    map<string, int>::iterator it;
    it = digit.find(w);
    if(it != digit.end()){//found
        return (*it).second;
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