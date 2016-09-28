/*
UVa315 - Network
Coded by Guojin Zhu
Run Time 0.064s
AC on Septemebr 27, 2012
*/
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
//////////////
const int maxsize = 110;
int marked = 0; // for marking visit
class Network{
private:
    vector<vector<int> > connect;
    int visit[maxsize];
    int numberOfCriticalPlaces;
    int dfs(int k);
public:
    void initial(int n);
    void readCase();
    void computing();
    void outResult(){ cout << numberOfCriticalPlaces << endl;}
};
void Network::initial(int n){
    connect.clear();
    connect.resize(n + 1); // connect[0] is not used
    numberOfCriticalPlaces = 0;
    marked++;
}
void Network::readCase(){
    int k, m;
    string line;
    while((cin >> k) && k){
        getline(cin, line);
        stringstream ss(line);
        while(ss >> m){
            connect[k].push_back(m);
            connect[m].push_back(k);
        }
    }
    /*for(int i = 1; i < connect.size(); i++){
        for(int j = 0; j < connect[i].size(); j++){
            cout << ' ' << connect[i][j];
        }
        cout << endl;
    }*/
}
int Network::dfs(int k){
    if(visit[k] == marked){
        return 0;
    }else{
        visit[k] = marked;
        int c = 1;
        for(int i = 0; i < connect[k].size(); i++){
            c += dfs(connect[k][i]);
        }
        return c;
    }
}
void Network::computing(){
    if(connect.size() > 3){
        int c;
        for(int i = 1; i < connect.size(); i++){
            visit[i] = marked; //to mark its failure
            if(i == 1){
                c = dfs(2);
            }else{
                c = dfs(1);
            }
            marked++; // for initialization
            if(c < connect.size() - 2){
                numberOfCriticalPlaces++;
            }
        }
    }
}
//////////////
int main(){
    Network net;
    int n;
    while((cin >> n) && n){
        net.initial(n);
        net.readCase();
        net.computing();
        net.outResult();
    }
    return 0;
}
/*
INPUT
5
5 1 2 3 4
0
6
2 1 3
5 4 6 2
0
0
OUTPUT
1
2
*/