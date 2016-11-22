/* 
 * File:   main.cpp
 * Author: YuhaoZhu
 *
 * Created on October 27, 2011, 2:46 PM
 */

#include<iostream>
#include<memory>
#include <algorithm>
using namespace std;

typedef struct {
    int x, y;
    int w;
} Edge;

Edge edge[26 * 26];
int father[26];
int sum;
int rank[26];

int cmp(const Edge a, const Edge b) {
    return a.w < b.w;
}

int find_set(int x) {
    if (x != father[x]) {
        father[x] = find_set(father[x]);
    }
    return father[x];
}

void union_set(int x, int y, int w) {
    if (x == y) return;
    if (rank[x] > rank[y]) {
        father[y] = x;
    } else {
        if (rank[x] == rank[y]) {
            rank[y] += 1;
        }
        father[x] = y;
    }
    sum += w;
}

int main() {
    int i, j, k, m, n, t;
    char ch;
    while (cin >> m && m != 0) {
        //input start
        k = 0;
        for (i = 0; i < m; i++) {
            father[i] = i;
            rank[i] = 0;
        }
        for (i = 0; i < m - 1; i++) {
            cin >> ch >> n;
            for (j = 0; j < n; j++) {
                cin >> ch >> edge[k].w;
                edge[k].x = i;
                edge[k].y = ch - 'A';
                k++;
            }
        }
        sort(edge,edge+k,cmp);
        sum=0;
        for (i=0;i<k;i++) union_set(find_set(edge[i].x),find_set(edge[i].y),edge[i].w);
        cout<<sum<<endl;
    }
    return 0;
}

