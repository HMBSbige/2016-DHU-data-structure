/*
pku2062 Card Game Cheater
Coded by Guojin Zhu
Run time 16MS
AC on Sept. 28, 2011
*/
#include <iostream>
#include <queue>
using namespace std;
////////////////////////////////////
struct Card{
    char charValue;
    char charSuit;
    int intValue(){
        switch (charValue){
            case 'T': return 10;
            case 'J': return 11;
            case 'Q': return 12;
            case 'K': return 13;
            case 'A': return 14;
            default: return int(charValue - '0');
        }
    }
    int intSuit(){
        switch (charSuit){
            case 'H': return 3;
            case 'S': return 2;
            case 'D': return 1;
            case 'C': return 0;
        }
    }
    friend bool operator < (Card c1, Card c2){
        return (c1.intValue() < c2.intValue())
               ||((c1.intValue() == c2.intValue())&&(c1.intSuit() < c2.intSuit()));
    }
};
////////////////////////////////////
class CardGameCheater{
private:
    priority_queue<Card> priqueAdamCards;
    priority_queue<Card> priqueEveCards;
    int intNumberOfPoints;
public:
    void initial();
    void readInput();
    void computing();
    void outResult();
};
void CardGameCheater::initial(){
    while (!priqueAdamCards.empty()){
        priqueAdamCards.pop();
    }
    while (!priqueEveCards.empty()){
        priqueEveCards.pop();
    }
}
void CardGameCheater::readInput(){
    Card c;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++){
        cin >> c.charValue >> c.charSuit;
        priqueAdamCards.push(c);
    }
    for (int i = 0; i < k; i++){
        cin >> c.charValue >> c.charSuit;
        priqueEveCards.push(c);
    }    
}
void CardGameCheater::computing(){
    intNumberOfPoints = 0;
    while (!priqueAdamCards.empty()){
        if ( priqueAdamCards.top() < priqueEveCards.top()){
            intNumberOfPoints++;
            priqueEveCards.pop();
            priqueAdamCards.pop();
        }else{
            priqueAdamCards.pop();
        }
    }
}
void CardGameCheater::outResult(){
    cout << intNumberOfPoints << endl;
}
////////////////////////////////////
int main(){
	int n;
	CardGameCheater cgc;
	cin >> n;
	for (int i = 0; i < n; i++){
		cgc.initial();
		cgc.readInput();
		cgc.computing();
		cgc.outResult();
	}
	return 0;
}