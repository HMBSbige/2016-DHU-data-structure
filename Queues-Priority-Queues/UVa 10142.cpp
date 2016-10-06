/**********************************/
/* uva10142 Australian Voting
/* Coded by Guojin Zhu
/* Run Time 0.720s
/* On August 1, 2010
/*******************************/
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
const int maxNumberOfNames = 20;
typedef queue<int> ballot;
//////////////////////////
class Vote{
private:
    vector<ballot> ballotlist;
    bool eliminated[maxNumberOfNames];
    int numberOfVotes[maxNumberOfNames];
    int highest;
    int lowest;
public:
    void initial();
    void addBallot(string line);
    void counting();
    void recounting();
    void eliminating();
    int highestNumber(){return highest;};
    int lowestNumber(){return lowest;};
    bool hasWinner(){return 2*highest > ballotlist.size();};
    bool isHighest(int k){return numberOfVotes[k] == highest;};
};
void Vote::initial(){
    ballotlist.clear();
    memset(eliminated, false, sizeof(eliminated));
    memset(numberOfVotes, 0, sizeof(numberOfVotes));
}
void Vote::addBallot(string line){
    int id;
    ballot b;
    stringstream ss(line);
    while (ss >> id){
        b.push(id-1); //  (id-1) from 0 to n-1
    }
    ballotlist.push_back(b);
}
void Vote::counting(){    
    int id;
    highest = 0;
    lowest = ballotlist.size();
    for (int i = 0; i < ballotlist.size(); i++){
        id = ballotlist[i].front();
        numberOfVotes[id]++;
        if (numberOfVotes[id] > highest){
            highest = numberOfVotes[id];
        }
        if (numberOfVotes[id] < lowest){
            lowest = numberOfVotes[id];
        }
    }
}
void Vote::recounting(){
    int id;
    for (int i = 0; i < ballotlist.size(); i++){
        id = ballotlist[i].front();
        if (eliminated[id]){
            while (eliminated[id]){
                ballotlist[i].pop();
                id = ballotlist[i].front();
            }
            numberOfVotes[id]++;
            if (numberOfVotes[id] > highest){
               highest = numberOfVotes[id];
            };
        }
    }
    lowest = ballotlist.size();
    for (int i = 0; i < ballotlist.size(); i++){
        id = ballotlist[i].front();
        if ((!eliminated[id])&&(numberOfVotes[id] < lowest)){
            lowest = numberOfVotes[id];
        }
    }
}
void Vote::eliminating(){
    for (int i = 0; i < maxNumberOfNames; i++){
        if (numberOfVotes[i] == lowest){
            eliminated[i] = true;
        }
    }
}
//////////////////////////
class AustralianVoting{
private:
    vector<string> namelist;
    Vote vote;
public:
    void initial();
    void readNames();
    void readBallots();
    void computing();
    void outResult();
};
void AustralianVoting::initial(){
    namelist.clear();
    vote.initial();
}
void AustralianVoting::readNames(){
    int numberOfNames;
    string name;
    cin >> numberOfNames;
    getline(cin, name); // read the end of the line
    for (int i = 0; i < numberOfNames; i++){
        getline(cin, name);
        namelist.push_back(name);
    }
}
void AustralianVoting::readBallots(){
    string line;
    getline(cin, line);
    while (line != ""){
        vote.addBallot(line);
        getline(cin, line);
    }
}
void AustralianVoting::computing(){
    vote.counting();
    while (vote.highestNumber() > vote.lowestNumber()){
        if (vote.hasWinner()){
            break;//one candidate receives more than 50% of the vote
        }else{
            vote.eliminating();//eliminate all candidates tied for the lowest number of votes
            vote.recounting();
        }
    }
}
void AustralianVoting::outResult(){
    for (int i = 0; i < namelist.size(); i++){
        if (vote.isHighest(i)){
            cout << namelist[i] << endl;
        }
    }
}
/////////////////////////////////////////////
int main(){
    AustralianVoting av;
    int numberOfCases;
    cin >> numberOfCases;
    for (int i = 0; i < numberOfCases; i++){
        av.initial();
        av.readNames();
        av.readBallots();
        av.computing();
        if (i > 0){
            cout << endl;
        }
        av.outResult();
    }
    return 0;
}