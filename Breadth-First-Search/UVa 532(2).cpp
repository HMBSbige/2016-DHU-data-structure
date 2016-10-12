/**********************************/
/* uva532 - Dungeon Master
/* Coded by Guojin Zhu
/* Run time 0.016s
/* AC on Nov. 1, 2011
/**********************************/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
//////////////////////////
struct Cube{
    int row;
    int column;
    int level;
    int step;
};
///////////////////////////
int const maxsize = 35;
class DungeonMaster{
private:
    int intNumberOfLevels;
    int intNumberOfRows;
    int intNumberOfColumns;
    char chararr3Dungeon[maxsize][maxsize][maxsize];
    bool boolarr3Visited[maxsize][maxsize][maxsize];
    bool boolEscaped;
    Cube cubeStart;
    int intShortestTime;
public:
    void initial();
    void readCase(int l, int r, int c);
    void compting();
    void outResult();
};
void DungeonMaster::initial(){
    memset(boolarr3Visited, false, sizeof(boolarr3Visited));
    memset(chararr3Dungeon, '#', sizeof(chararr3Dungeon));
    boolEscaped = false;
    cubeStart.step = 0;
    intShortestTime = maxsize*maxsize*maxsize;
}
void DungeonMaster::readCase(int l, int r, int c){
    intNumberOfLevels = l;
    intNumberOfRows = r;
    intNumberOfColumns = c;
    for(int level = 1; level <= intNumberOfLevels; level++){
        for(int row = 1; row <= intNumberOfRows; row++){
            for(int column = 1; column <= intNumberOfColumns; column++){
                cin >> chararr3Dungeon[level][row][column];
                if(chararr3Dungeon[level][row][column] == 'S'){
                    cubeStart.level = level;
                    cubeStart.row = row;
                    cubeStart.column = column;
                }
            }
        }
    }
}
void DungeonMaster::compting(){//BFS
    int d[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
    Cube c, nc;
    queue<Cube> q;
    boolarr3Visited[cubeStart.level][cubeStart.row][cubeStart.column] = true;
    q.push(cubeStart);
    while(!q.empty()){
        c = q.front();
        q.pop();
        nc.step = c.step + 1;
        for(int i = 0; i < 6; i++){
            nc.level = c.level + d[i][0];
            nc.row = c.row + d[i][1];
            nc.column = c.column + d[i][2];
            if(chararr3Dungeon[nc.level][nc.row][nc.column] == 'E'){
                intShortestTime = nc.step;
                boolEscaped = true;
                break;
            }else if(!boolarr3Visited[nc.level][nc.row][nc.column]){
                boolarr3Visited[nc.level][nc.row][nc.column] = true;
                if(chararr3Dungeon[nc.level][nc.row][nc.column] == '.'){
                    q.push(nc);
                }
            }
        }
    }
}
void DungeonMaster::outResult(){
    if(boolEscaped){
        cout << "Escaped in " << intShortestTime << " minute(s)." << endl;
    }else{
        cout << "Trapped!" << endl;
    }
}
///////////////////////////
int main(){
    int l, r, c;
    DungeonMaster dm;
    while((cin >> l >> r >> c)&&((l != 0)||(r != 0)||(c != 0))){
        dm.initial();
        dm.readCase(l, r, c);
        dm.compting();
        dm.outResult();
    }
    return 0;
}