/*
UVa336 A Node Too Far 
Coded by Guojin Zhhu
Run Time 0.216s
AC on October 11, 2012
*/ 
#include<iostream>
#include<queue>
#include<map>
#include<vector>
using namespace std;
/////////////////
class NodeTooFar{
private:
    int startID;
    int ttlValue;
    int notReachables;
    map<int, vector<int> > connection;
public:
    void initial(int nc){connection.clear();}
    void readNetwork(int nc);
    void query(int start, int ttl);
    void outResult(int c);
};
void NodeTooFar::readNetwork(int nc){
    int n1, n2;
    for(int i = 0; i < nc; i++){
        cin >> n1 >> n2;
        connection[n1].push_back(n2);
        connection[n2].push_back(n1);
    }
}
void NodeTooFar::query(int start, int ttl){
    startID = start;
    ttlValue = ttl;
    map<int, int> visit;
    queue<int> q;
    notReachables = connection.size();
    visit[startID] = 0;
    q.push(start);
    int node, adj;
    while(!q.empty()){//bfs
        node = q.front();
        q.pop();
        notReachables--;
        if(visit[node] < ttlValue){
            for(int i = 0; i < connection[node].size(); i++){
                adj = connection[node][i];
                if(visit.count(adj) == 0){
                    visit[adj] = visit[node] + 1;
                    q.push(adj);
                }
            }
        }
    }
}
void NodeTooFar::outResult(int c){
    cout << "Case " << c << ": ";
    cout << notReachables << " nodes not reachable from node ";
    cout << startID << " with TTL = " << ttlValue << '.' << endl;
}
/////////////////
int main(){
    NodeTooFar ntf;
    int nc, start, ttl, caseID = 1;
    while((cin >> nc) && nc){
        ntf.initial(nc);
        ntf.readNetwork(nc);
        while((cin >> start >> ttl) && ((start != 0) || (ttl != 0))){
            ntf.query(start, ttl);
            ntf.outResult(caseID++);
        }
    }
    return 0;
}
/*
INPUT
16
10 15   15 20   20 25   10 30   30 47   47 50   25 45   45 65
15 35   35 55   20 40   50 55   35 40   55 60   40 60   60 65
35  2   35  3    0  0

14
1 2   2 7   1 3   3 4   3 5   5 10   5 11
4 6   7 6   7 8   7 9   8 9   8  6   6 11
1 1   1 2   3 2   3 3   0 0  
  
0
---------------------
OUTPUT
Case 1: 5 nodes not reachable from node 35 with TTL = 2.
Case 2: 1 nodes not reachable from node 35 with TTL = 3.
Case 3: 8 nodes not reachable from node 1 with TTL = 1.
Case 4: 5 nodes not reachable from node 1 with TTL = 2.
Case 5: 3 nodes not reachable from node 3 with TTL = 2.
Case 6: 1 nodes not reachable from node 3 with TTL = 3.
*/