/*************************/
/* pku 2153 Rank List
/* Coded by Guojin Zhu
/* Run time 6360MS
/* AC on Oct. 13, 2011
/*************************/
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
//////////////////////////////
class RankList{
private:
    int numberOfStudents;
    map<string, int> mapNameList;
    int numberOfExams;
    vector<vector<int> > vec2Scores;
    vector<int> intvecRanksOfLiMing; 
public:
	void initial(int n);
	void readCase();
	void computing();
	void outReeult();
};
void RankList::initial(int n){
    numberOfStudents = n;
    numberOfExams = 0;
    vec2Scores.clear();
    intvecRanksOfLiMing.clear();
    mapNameList.clear();
}
void RankList::readCase(){
    int c;
    string strName;
    cin.ignore(256, '\n');
    c = 0;
    for (int i = 0; i < numberOfStudents; i++){
        getline(cin, strName);
        if (strName == "Li Ming"){
            mapNameList[strName] = 0;
        }else{
            c++;
            mapNameList[strName] = c;
        }
    }
    
    int id, s;
    vector<int> vecScore;
    cin >> numberOfExams;
    for (int i = 0; i < numberOfExams; i++){
        vecScore.clear();
        vecScore.resize(numberOfStudents);
        for (int c = 0; c < numberOfStudents; c++){
            cin >> s;
            cin.ignore();
            getline(cin, strName);
            id = mapNameList[strName];
            vecScore[id] = s;
        }
        vec2Scores.push_back(vecScore);
    }
}
void RankList::computing(){
    vector<int> intvecTotalScore;
    int r;
    for (int i = 0; i < numberOfStudents; i++){
        intvecTotalScore.push_back(0);
    }
    for (int i = 0; i < numberOfExams; i++){
        for (int id = 0; id < numberOfStudents; id++){
            intvecTotalScore[id] += vec2Scores[i][id];
        }
        r = 1;
        for (int id = 1; id < numberOfStudents; id++){
            if (intvecTotalScore[id] > intvecTotalScore[0]){
                r++;
            }
        }
        intvecRanksOfLiMing.push_back(r);
    }
}
void RankList::outReeult(){
    for (int i = 0; i < intvecRanksOfLiMing.size(); i++){
        cout << intvecRanksOfLiMing[i] << endl;
    }
}
/////////////////////////////
int main(){
	int n;
	RankList rl;
	while (cin >> n){
		rl.initial(n);
		rl.readCase();
		rl.computing();
		rl.outReeult();
	}
	return 0;
}
