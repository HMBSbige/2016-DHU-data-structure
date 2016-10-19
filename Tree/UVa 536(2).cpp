/*
UVa536 Tree Recovery
Coded by Guojin Zhu
Run Time 0.008s
AC on November 2,2012
*/
#include<iostream>
#include<string>
using namespace std;
///////////////////
class TreeRecovery{
private:
    string preord;
    string inord;
    string postorder;
    void reconstruct(string p, string i);
public:
    void initial(string p, string i){
        preord = p;
        inord = i;
        postorder.clear();
    }
    void computing(){reconstruct(preord, inord);}
    void outResult(){cout << postorder << endl;}
};
void TreeRecovery::reconstruct(string preord, string inord){
    int sz = preord.size();
    if(sz > 0){
        int p = int(inord.find(preord[0]));
        reconstruct(preord.substr(1, p), inord.substr(0, p)); //left subtree
        reconstruct(preord.substr(p+1, sz-p-1), inord.substr(p+1, sz-p-1)); //right subtree
        postorder.push_back(preord[0]); //root
    }
}
/////////////////////
int main(){
    TreeRecovery tr;
    string p, i;
    while(cin >> p >> i){
        tr.initial(p, i);
        tr.computing();
        tr.outResult();
    }
    return 0;
}
/*
INPUT
DBACEGF ABCDEFG
BCAD CBAD
AB BA
--------------
OUTPUT
ACBFGED
CDAB
BA
*/