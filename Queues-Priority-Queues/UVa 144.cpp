/*********************************/
/* uva144 Student Grants
/* Coded by Guojin ZHU
/* Run Time 0.008s
/* AC on July 12, 2010
/*********************************/
#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;
///////////////////////////////
struct IDCard{
    int intIDNumber;
    int intPayment;
};
class Machine{
private:
    int intOutputStore;
    int intLimit;
    int intNextCoins;
public:
    Machine(int k);
    void makingPayment(IDCard* card);
};
Machine::Machine(int k){
    intNextCoins = 1;    
    intOutputStore = intNextCoins;
    intLimit = k;
}
void Machine::makingPayment(IDCard* card){
    if ((card->intPayment + intOutputStore) <= 40){
        card->intPayment += intOutputStore;
        intNextCoins = 1 + (intNextCoins % intLimit);
        intOutputStore = intNextCoins;
    }else{
        intOutputStore -= 40 - card->intPayment;
        card->intPayment = 40; 
    }
}
///////////////////////////////
class StudentGrants{
private:
    int intNumberOfStudents;
    int intLimitForMachine;
    queue<IDCard> queCard;
public:
    void setNumber(int n);
    void setLimit(int k){intLimitForMachine = k;};
    void process();
};
void StudentGrants::setNumber(int n){
    IDCard card;
    intNumberOfStudents = n;
    while (!queCard.empty()){
        queCard.pop();
    }
    for (int i = 0; i < intNumberOfStudents; i++){
        card.intIDNumber = i + 1;
        card.intPayment = 0;
        queCard.push(card);
    }
}
void StudentGrants::process(){
    Machine m(intLimitForMachine);
    IDCard card;
    while (!queCard.empty()){
        card = queCard.front();
        queCard.pop();
        m.makingPayment(&card);
        if (card.intPayment == 40){
            cout << setw(3) << card.intIDNumber;
        }else{
            queCard.push(card);
        }
    }
    cout << endl;
}
////////////////////////////////
int main(){
    int n, k;
    StudentGrants sg;
    while((cin >> n >> k) && !((n == 0) && (k == 0))){
        sg.setNumber(n);
        sg.setLimit(k);
        sg.process();
    }
    return 0;
}