/*
HDU4417 Super Mario
Coded by Guojin Zhu
Run Time 515MS
AC on September 25, 2012
-------------
INPUT
1
10 10
0 5 2 7 5 4 3 8 7 7
2 8 6
3 5 0
1 3 1
1 9 4
0 1 0
3 5 5
5 5 1
4 6 3
1 5 7
5 7 3
-----------------
OUTPUT
Case 1:
4
0
0
3
1
2
0
1
5
1
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
////////////////////////
const int maxsize = 263000;
struct Node{
    int left, right, mid;
    vector<int> v;
};
class SegmentTree{
private:
    static Node node[maxsize];
public:
    void build(int l, int r, int rt);
    void insert(int p, int x, int rt);
    int query(int l, int r, int h, int rt);
};
Node SegmentTree::node[maxsize];
void SegmentTree::build(int l, int r, int rt){
    node[rt].left = l;
    node[rt].right = r;
    node[rt].mid = (l + r) >> 1;
    node[rt].v.clear();    
    if(l < r){
        int m = (l + r) >> 1;
        build(l, m, rt << 1);
        build(m + 1, r, (rt << 1)|1);
    }
}
void SegmentTree::insert(int p, int x, int rt){
    node[rt].v.push_back(x);
    if(node[rt].left < node[rt].right){
        if(p <= node[rt].mid ){
            insert(p, x, rt << 1);
        }else{
            insert(p, x, (rt << 1)|1);
        } 
    }
}
int SegmentTree::query(int l, int r, int h, int rt){
    if((l <= node[rt].left)&&(node[rt].right <= r)){
        vector<int>::iterator it;
        it = upper_bound(node[rt].v.begin(), node[rt].v.end(), h);
        return int(it - node[rt].v.begin());
    }else{
        int c = 0;
        if(l <= node[rt].mid){
            c += query(l, r, h, rt << 1);
        }
        if(node[rt].mid < r){
            c += query(l, r, h, (rt << 1)|1);
        }
        return c;        
    }
}
//////////////////////
struct Brick{
    int position;
    int height;
    Brick(int a = 0, int b = 0){position = a; height = b;}
    friend bool operator < (Brick b1, Brick b2){
        return b1.height < b2.height;
    }
};
class SuperMario{
private:
    vector<Brick> brick;
    int lengthOfRoad;
    int numberOfQueries;
    SegmentTree st;
public:
    void initial(){brick.clear();}
    void readRoad();
    void computing();
    void query();
};
void SuperMario::readRoad(){
    scanf("%d%d", &lengthOfRoad, &numberOfQueries);
    int h;
    for(int i = 0; i < lengthOfRoad; i++){
        scanf("%d", &h);
        brick.push_back(Brick(i, h));
    }
}
void SuperMario::computing(){
    st.build(0, brick.size() - 1, 1);
    sort(brick.begin(), brick.end());
    for(int i = 0; i < brick.size(); i++){
        st.insert(brick[i].position, brick[i].height, 1);
    }
}
void SuperMario::query(){
    int l, r , h;
    for(int i = 0; i < numberOfQueries; i++){
        scanf("%d%d%d", &l, &r, &h);
        printf("%d\n", st.query(l, r, h, 1));
    }
}
//////////////////////
int main(){
    SuperMario sm;
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        sm.initial();
        sm.readRoad();
        sm.computing();
        printf("Case %d:\n", i);
        sm.query();
    }
    return 0;
}
