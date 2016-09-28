/*
DHU4414 Finding crosses
Coded by Guojin Zhu
Run time 15MS
AC on September 23, 2012
--------------
INPUT
4
oo#o
o###
oo#o
ooo#
4
oo#o
o###
oo#o
oo#o
5
oo#oo
oo#oo
#####
oo#oo
oo##o
6
ooo#oo
ooo##o
o#####
ooo#oo
ooo#oo
oooooo
6
oooooo
oooo#o
o#####
oooo#o
oooo#o
oooo#o
6
ooo##o
ooo#oo
o#####
ooo#oo
ooo#oo
oooooo
0
------------
OUTPUT
1
0
0
0
0
0
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/////////////////////
struct XY{
    int x, y;
    XY(int a = 0, int b = 0){x = a; y = b;}
    friend bool operator < (XY p1, XY p2){
        if(p1.x != p2.x){
            return p1.x < p2.x;
        }else{
            return p1.y < p2.y;
        }
    }
};
class FindingCrosses{
private:
    vector<string> matrix;
    int numberOfCrosses;
    vector<XY> candidate;
private:
    void dfs(int r, int c);
    bool isCross();
public:
    void initial(int n);
    void readCase();
    void computing();
    void outResult(){cout << numberOfCrosses << endl;}
};
void FindingCrosses::initial(int n){
    numberOfCrosses = 0; 
    matrix.clear();
    matrix.resize(n+2); //the aditional two rows for boundaries
}
void FindingCrosses::readCase(){
    for(int i = 1; i < matrix.size()-1; i++){
        cin >> matrix[i];
        matrix[i] = 'o' + matrix[i] + 'o'; // add left and right boundaries
    }
    for(int i = 0; i < matrix.size(); i++){
        matrix[0].push_back('o');  // top boundary
        matrix[matrix.size()-1].push_back('o'); // bottom boundary
    }
}
void FindingCrosses::dfs(int r, int c){
    if(matrix[r][c] == '#'){
        matrix[r][c] = 'o'; // marked visisted
        candidate.push_back(XY(r, c));
        dfs(r-1, c); // go up
        dfs(r+1, c); // go down
        dfs(r, c-1); // go left
        dfs(r, c+1); // go right
    }
}
bool FindingCrosses::isCross(){
    int width = 1 + (candidate.size() >> 1);
    if(width < 3){
        return false;
    }else if((width & 1) == 0){
        return false;
    }else{        
        sort(candidate.begin(), candidate.end());
        int r, c;
        r = c = 0;
        for(int i = 0; i < candidate.size(); i++){
            if(candidate[width-1].y == candidate[i].y){
                c++;
            }
            if(candidate[width-1].x == candidate[i].x){
                r++;
            }
        }
        if((c != width)||(r != width)){
            return false;
        }else if((candidate[width-1].x - candidate[0].x) != (width >> 1)){
            return false;
        }else{
            return true;
        }
    }  
}
void FindingCrosses::computing(){
    for(int row = 1; row < matrix.size()-1; row++){
        for(int col = 1; col < matrix.size()-1; col++){
            candidate.clear();
            if(matrix[row][col] == '#'){
                dfs(row, col);
                if(isCross()){
                    numberOfCrosses++;
                }
            }
        }
    }
}
/////////////
int main(){
    FindingCrosses fc;
    int n;
    while((cin >> n) && n){
        fc.initial(n);
        fc.readCase();
        fc.computing();
        fc.outResult();
    }
    return 0;
}