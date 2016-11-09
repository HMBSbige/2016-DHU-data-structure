/*********************************/
/* hdu4022 Bombing
/* Coded by Guojin ZHU
/* Run time 1296MS
/* AC on Sept. 11, 2011
/*********************************/
#include <iostream>
#include <list>
#include <map>
using namespace std;
//////////////////////////////////
struct node{
    int v;
    list<node> ::iterator it; 
};
class Cross{
private:
    map<int, list<node> > mx, my;
public:
    void initial();
    void inssetPoint(int x, int y);
    void deleteXline(int x);
    void deleteYline(int y);
    int countX(int x){return mx[x].size();}
    int countY(int y){return my[y].size();}
};
void Cross::initial(){
    mx.clear();
    my.clear();
}
void Cross::inssetPoint(int x, int y){
    list<node> ::iterator ix, iy;
    node n;  
    ix = mx[x].insert(mx[x].end(), n);
    iy = my[y].insert(my[y].end(), n);
    ix->it = iy;
    iy->it = ix;
    ix->v = y;
    iy->v = x;
}
void Cross::deleteXline(int x){
    for (list<node> ::iterator i = mx[x].begin(); i != mx[x].end(); i++){
        my[i->v].erase(i->it);
    }
    mx[x].clear();    
}
void Cross::deleteYline(int y){
    for (list<node> ::iterator i = my[y].begin(); i != my[y].end(); i++){
        mx[i->v].erase(i->it);
    }
    my[y].clear();    
}
//////////////////////////////////////////
class Bombing{
private:
    Cross cross;
public:
    void readBases(int n);
    void reporting(int m); 
};
void Bombing::readBases(int n){
    int x, y;
    cross.initial();
    for (int i = 0; i < n; i++){
        //cin >> x >> y;
        scanf("%d%d", &x, &y);
        cross.inssetPoint(x, y);
    }
}
void Bombing::reporting(int m){
    int c, d;
    for (int i = 0; i < m; i++){
        //cin >> c >> d;
        scanf("%d%d", &c, &d);
        if (c == 0){
            //cout << cross.countX(d) << endl;
            printf("%d\n", cross.countX(d));
            cross.deleteXline(d);
        }else{
            //cout << cross.countY(d) << endl;
            printf("%d\n", cross.countY(d));
            cross.deleteYline(d);
        }
    }
} 
//////////////////////////////////////
int main(){
    int n, m;
    Bombing b;
    while ((cin >> n >> m)&&((n != 0)||(m != 0))){
        b.readBases(n);
        b.reporting(m);
    }
    return 0;
}