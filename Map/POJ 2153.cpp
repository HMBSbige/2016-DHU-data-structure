#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <new>
using namespace std;

int main()
{
    int N,tempInt,M;
    string tempString;
    map<string,int> NameList;
    while(cin>>N){
    cin.ignore();
    for(int i=tempInt=1;i<=N;++i){
        getline(cin,tempString,'\n');
        if(tempString=="Li Ming")
            NameList[tempString]=0;
        else{
            NameList[tempString]=tempInt++;
        }
    }
    cin>>M;
    //vector<int> Scores[M];
    vector<int> *Scores=new vector<int>[M];
    for(int i=0;i<M;++i){
        Scores[i].resize(N);
        for(int j=0;j<N;++j){
            cin>>tempInt;
            cin.ignore();
            getline(cin,tempString,'\n');
            Scores[i][NameList[tempString]]=tempInt;
        }
    }
    vector<int> TotalScore(N,0);
    for(int i=0;i<M;++i){
       for(tempInt=0;tempInt<N;++tempInt)
        TotalScore[tempInt]+=Scores[i][tempInt];
       int rank=1;
       for(int j=1;j<N;++j)
        if(TotalScore[j]>TotalScore[0])
            ++rank;
       cout<<rank<<endl;
    }
    delete [] Scores;
}
    return 0;
}