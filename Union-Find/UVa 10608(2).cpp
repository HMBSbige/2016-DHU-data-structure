/******************************/
/* uva 10608 Friends
/* Coded by Guojin Zhu
/* Run time 0.108s
/* Submission received with ID 9384075
/* AC on Oct. 18, 2011
/******************************/
#include <iostream>
#include <vector>
using namespace std;
//////////////////////////////
class UnionFind{
private:
    vector<int> parent;
    vector<bool> root;
    int intLargestSize;
public:
    void initial(int size);
    int find(int k);
    int union1(int a, int b);
    int largestSize(){return intLargestSize;}
};
void UnionFind::initial(int n){
    root.resize(n + 1);
    parent.resize(n + 1);
    for(int k = 1; k <= n; k++ ){
        parent[k] = 1; 
        root[k] = true;
    }
    intLargestSize = 1;
}
int UnionFind::find(int k){
    int r = k;
    while(!root[r]){
        r = parent[r]; // search for the root
    }
    int pe;
    int e = k;
    while(e != r){
        pe = parent[e];
        parent[e] = r;
        e = pe;
    }
    return r;
}
int UnionFind::union1(int r1, int r2){
    if(parent[r1] < parent[r2]){
        parent[r2] += parent[r1];
        parent[r1] = r2;
        root[r1] = false;
        if(parent[r2] > intLargestSize){
            intLargestSize = parent[r2];
        }
        return r2;
    }else{
        parent[r1] += parent[r2];
        parent[r2] = r1;
        root[r2] = false;
        if(parent[r1] > intLargestSize){
            intLargestSize = parent[r1];
        }
        return r1;
    }
}
//////////////////////////////
class FRIENDS{
private:
    int intNumberOfCitizens;
    int intNumberOfPairs;
    int intNumberOfpeopleInLargestGroup;
    UnionFind uf;
public:
    void readCase();
	void initial();
	void computing();
	void outResult();
};
void FRIENDS::readCase(){
    cin >> intNumberOfCitizens >> intNumberOfPairs;
}
void FRIENDS::initial(){
    uf.initial(intNumberOfCitizens);
}
void FRIENDS::computing(){
    int a, b;
    int ra, rb;
    for(int i = 0; i < intNumberOfPairs; i++){
        cin >> a >> b;
        ra = uf.find(a);
        rb = uf.find(b);
        if(ra != rb){
            uf.union1(ra, rb);
        }
    }
    intNumberOfpeopleInLargestGroup = uf.largestSize();    
}
void FRIENDS::outResult(){
    cout << intNumberOfpeopleInLargestGroup << endl;
}
//////////////////////////////
int main(){
	int NumOfCase;
	FRIENDS f;
	cin >> NumOfCase;
	for(int i = 0; i < NumOfCase; i++){
	    f.readCase();
	    f.initial();
	    f.computing();
	    f.outResult();
	}
	return 0;
}
