/*
Coded by Guojin ZHU on Nov. 18, 2015
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;
////////////////////////
class Coder{
private:
    int c;
    map<string, int> m;
public:
    void reset(){c = 1; m.clear();}
    int code(string s){
        if (m.find(s) == m.end()) {m[s] = c++;}
        return m[s];
    }
};
int main(){
    string s1, s2;
    int a;
    Coder c;
    c.reset();
    while(cin >> s1 >> s2 >> a){
        //cout << s1 << ' ' << s2 << ' '<< a << endl;
        cout << c.code(s1) << ' ';
        cout << c.code(s2) << ' '<< a << endl;
    }
    return 0;
}
/*
Input
Karlsruhe Stuttgart 100
Stuttgart Ulm 80
Ulm Muenchen 120
Karlsruhe Hamburg 220
Hamburg Muenchen 170
----------
Output
1 2 100
2 3 80
3 4 120
1 5 220
5 4 170
*/