/*
UVa572 - Oil Deposits 
Coded by Guojin Zhu
Run Time 0.012s
AC on October 1, 2012
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
/////////////////
const int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
const int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};
class OilDeposits{
private:
    vector<string> land;
    int numberOfDeposits;
    void dfs(int x, int y);
public:
    void initial(){land.clear(); numberOfDeposits = 0;}
    void readCase(int m, int n);
    void computing();
    void outResult(){cout << numberOfDeposits << endl;}
    void outLand(){
        for(int i = 0; i < land.size(); i++){
            cout << land[i] << endl;
        }
        cout << endl;
    }
};
void OilDeposits::readCase(int m, int n){
    land.resize(m + 2);
    for(int i = 0; i < n + 2; i++){
        land[0].push_back('*');   //add the top boundary
        land[m+1].push_back('*'); //add the bottom boundary
    }
    for(int i = 1; i <= m; i++){
        cin >> land[i];
        land[i] = '*' + land[i] + '*'; //add the left and right boundaries
    }
}
void OilDeposits::computing(){
    for(int r = 1; r < land.size() - 1; r++){
        for(int c = 1; c < land[r].size() - 1; c++){
            if(land[r][c] == '@'){
                numberOfDeposits++;
                dfs(r, c);
            }
        }
    }
}
void OilDeposits::dfs(int x, int y){
    if(land[x][y] == '@'){
        land[x][y] = '*';
        for(int i = 0; i < 8; i++){
            dfs(x + dx[i], y + dy[i]);
        }
    }
}
///////////////
int main(){
    OilDeposits od;
    int m, n;
    while((cin >> m >> n) && m){
        od.initial();
        od.readCase(m, n);
        //od.outLand();
        od.computing();
        od.outResult();
    }
    return 0;
}
/*
INPUT
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0
------------------
OUTPUT
0
1
2
2
*/