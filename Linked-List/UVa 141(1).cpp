/************************************/
/* uva141 The Spot Game
/* Coded by Guojin ZHU
/* Run time 12ms
/* AC on July 5, 2010
/************************************/
#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
using namespace std;
const int maxsize = 100;
const int bigprime = 9941;
/////////////////////
class Position{
private:
    int row;
    int col;
    int size;
public:
    bool operator == (Position p){
        return (row == p.row) && (col == p.col);
    }
    void setRow(int r){row = r;};
    void setCol(int c){col = c;};
    void setSize(int s){size = s;};
    int viewFrom(int v){
        switch (v){
            case 0: return (row -1)*size + (col - 1);          // from south
            case 1: return (col -1)*size + (size - row );      // from east
            case 2: return (size - row)*size + (size - col);   // from north
            case 3: return (size -col)*size + (row -1);        // from west
            default:;
        }
    }
};
////////////////////////////
struct Pattern{
    int value[maxsize];
    int length;
    void clear(){
        length = 0;
        memset(value, 0, sizeof(value));
        value[0] = 0x7fffffff;
    }
    int hash(){
        int s = 0;
        for (int i = 0; i < length; i++){
            s += (value[i]*value[i]) % bigprime;
        }
        return s % bigprime;
    }
};
class Board: public list<Position>{
private:
    Pattern minPattern;
    void updateIfSmall(list<int>* ptn);
public:
    Pattern getPattern();
    int hash();
};
void Board::updateIfSmall(list<int>* ptn){
    int i;
    bool newsmall;
    i = 0;
    newsmall = false;
    while (!ptn->empty()){
        if (minPattern.value[i] > ptn->front()){
            newsmall = true;
            break;
        }else if (minPattern.value[i] < ptn->front()){
            break;
        }else{
            i++;
            ptn->pop_front();
        }
    }
    if (newsmall){
        while (!ptn->empty()){
            minPattern.value[i] = ptn->front();
            i++;
            ptn->pop_front();
        }
    }
};
Pattern Board::getPattern(){
    list<int> listTemp;
    minPattern.clear();
    minPattern.length = size();
    for (int i = 0; i < 4; i++){
        listTemp.clear();
        for(list<Position>::iterator it = begin(); it != end(); it++){
            listTemp.push_back(it->viewFrom(i));
        }
        listTemp.sort();
        updateIfSmall(&listTemp);
    }
    return minPattern;
}
////////////////////////////
class History{
private:
    vector<Pattern> vectorP[bigprime];
    bool boolExist;
public:
    void initial();
    void record(Pattern &p);
    bool exist(){return boolExist;};
};
void History::initial(){
    for (int i = 0; i < bigprime; i++){
        vectorP[i].clear();
    }
}
void History::record(Pattern &p){
    int hsh, sz;
    hsh = p.hash();
    sz = vectorP[hsh].size();
    boolExist = false;
    for (int i = 0; i < sz; i++){
        if (memcmp(p.value, vectorP[hsh][i].value, p.length*sizeof(int)) == 0){
            boolExist = true;
            break;
        }
    }
    if (!boolExist){
        vectorP[hsh].push_back(p);   
    }
}
////////////////////////////
class TheSpotGame{
private:
    int intRow[maxsize];
    int intCol[maxsize];
    char charSign[maxsize];
    int intSize;
private:
    Board bd;
    History h;
    int intResult;
    void move(int k);
public:
    void initial();
    void readData(int n);
    void process();
    void outResult(); 
};
void TheSpotGame::initial(){
    bd.clear();
    h.initial();
    Pattern ptn = bd.getPattern();
    h.record(ptn);
    intResult = 0; // 0 for draw
};
void TheSpotGame::readData(int n){
    intSize = n;
    for (int i = 0; i < 2*intSize; i++){
        cin >> intRow[i] >> intCol[i] >> charSign[i];
    }
}
void TheSpotGame::move(int k){
    Position p;
    p.setRow(intRow[k]);
    p.setCol(intCol[k]);
    p.setSize(intSize);
    switch(charSign[k]){
        case '+':
            bd.push_back(p);
            break;;
        case '-':
            bd.remove(p);
            break;
    }
}
void TheSpotGame::process(){
    Pattern ptn;
    for (int i = 0; i < 2*intSize; i++){
        move(i);
        ptn = bd.getPattern();
        h.record(ptn);
        if (h.exist()){
            intResult = i+1;
            break;
        }
    }
}
void TheSpotGame::outResult(){
    if (intResult == 0){
        cout << "Draw" << endl;
    }else if ((intResult % 2) == 0){
        cout << "Player 1 wins on move " << intResult << endl;
    }else{
        cout << "Player 2 wins on move " << intResult << endl;
    }
}; 
////////////////////////////////////////
int main(){
    int n;
    TheSpotGame tsg;
    while ((cin >> n) && (n != 0)){
        tsg.initial();
        tsg.readData(n);
        tsg.process();
        tsg.outResult();
    }
    return 0;
}