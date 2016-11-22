/* 
 * File:   main.cpp
 * Author: YuhaoZhu
 *
 * Created on October 27, 2011, 2:46 PM
 */

#include<iostream>
#include<memory>
#include <algorithm>
#define INF 0x7FFFFF

using namespace std;

int n, g[26][26];
int min(int a,int b){
    if (a>b) return b;
    else return a;
}
void init() {

    char a, b;
    int an, bw;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = INF;
        }
    }
    for (int i = 0; i < n-1; i++) {
        cin >> a >> an;
        while (an--) {
            cin >> b >> bw;
            g[a - 'A'][b - 'A'] = bw;
            g[b - 'A'][a - 'A'] = bw;
        }
    }
}


void prim() {
    int dis[26], mark[26];
    int min_dis, v;
    for (int i = 0; i < 26; i++) {
        dis[i] = INF;
        mark[i] = 0;
    }
    dis[0] = 0;
    while (true) {
        min_dis = INF, v = -1;
        for (int i = 0; i < n; i++) {
            if (mark[i]==0 && (min_dis > dis[i]) ){
                v = i;
                min_dis = dis[i];
            }
        }
        if (v == -1) break;
        mark[v]=1;
        for (int i = 0; i < n; i++) {
            if (mark[i]==0) {
                dis[i] = min(dis[i], g[v][i]);
            }
        }
    }
    int sum=0;
    for (int i=0;i<n;i++) sum+=dis[i];
    cout<<sum<<endl;
}

int main() {
    while (cin >> n && n != 0) {
        init();
        prim();
    }
    return 0;
}

