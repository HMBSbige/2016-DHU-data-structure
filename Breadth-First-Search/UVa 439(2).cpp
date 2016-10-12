/*
UVa439 - Knight Moves
Coded by Guojin Zhu
Run Time 0.032s
AC on October 2,2012
*/
#include <iostream>
#include <queue>
using namespace std;
/////////////////////////////
struct RC{
    int r;
    int c;
    RC(int a = 0, int b = 0){r = a; c = b;}
    RC(char a, char b){r = int(a - '1'); c = int(b - 'a');}
    char rowChar(){return char(int('1') + r);}
    char colChar(){return char(int('a') + c);}
    bool friend operator == (RC a, RC b){return (a.r == b.r) && (a.c == b.c);}
};
////////////////////////////////////////////////////////
const int size = 8;
class KnightMoves{
private:
    RC squareA;
    RC squareB;
    int board[size][size];
public:
    void initial();
    bool readData();
    void computing();
    void outResult();
    void outBoard();
};
void KnightMoves::initial(){
    for(int r = 0; r < size; r++){
        for(int c = 0; c < size; c++){
            board[r][c] = -1;
        }
    }
}
void KnightMoves::outBoard(){
    for(int r = 0; r < size; r++){
        for(int c = 0; c < size; c++){
            if(board[r][c] < 0){
                cout << " .";
            }else{
                cout << ' ' << board[r][c];
            }
        }
        cout << endl;
    }
    cout << endl;
}
bool KnightMoves::readData(){
    char r, c;
    cin >> c >> r;
    squareA = RC(r, c);
    cin >> c >> r;
    squareB = RC(r, c);
    return !cin.eof();
}
void KnightMoves::computing(){//BFS
    const int dr[8] = {2, 1, -1, -2, -2, -1,  1,  2};
    const int dc[8] = {1, 2,  2,  1, -1, -2, -2, -1};     
    RC s, ns;
    queue<RC> q;
    board[squareA.r][squareA.c] = 0;
    q.push(squareA);
    while (!q.empty()){
        s = q.front();
        q.pop();
        if (s == squareB){
            break;
        }else{
            for(int i = 0; i < 8; i++){
                ns = RC(s.r + dr[i], s.c + dc[i]);
                if((0 <= ns.r) && (ns.r < 8) && (0 <= ns.c) && (ns.c < 8)){
                    if(board[ns.r][ns.c] < 0){
                        board[ns.r][ns.c] = board[s.r][s.c] + 1;
                        q.push(ns);
                    }
                }
            }
        }
    }
}
void KnightMoves::outResult(){
    cout << "To get from " << squareA.colChar() << squareA.rowChar();
    cout << " to " << squareB.colChar() << squareB.rowChar();
    cout << " takes " << board[squareB.r][squareB.c] << " knight moves." << endl;
}
////////////////////////////////////
int main(){
   KnightMoves km;
    while (km.readData()){
        km.initial();
        km.computing();
        //km.outBoard();
        km.outResult();
    }
    return 0;
}
/*
IUPUT
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6
-----------
OUTPUT
To get from e2 to e4 takes 2 knight moves.
To get from a1 to b2 takes 4 knight moves.
To get from b2 to c3 takes 2 knight moves.
To get from a1 to h8 takes 6 knight moves.
To get from a1 to h7 takes 5 knight moves.
To get from h8 to a1 takes 6 knight moves.
To get from b1 to c3 takes 1 knight moves.
To get from f6 to f6 takes 0 knight moves.
*/