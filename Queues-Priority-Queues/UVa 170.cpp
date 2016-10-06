/*********************************/
/* uva170 - Clock Patience
/* Coded by Guojin ZHU
/* Run Time 0.008s
/* AC on July 12, 2010
/*********************************/
#include <iostream>
#include <queue>
using namespace std;
///////////////////////////////
struct Card{
    char charValue;
    char charSuit;
    bool boolFaceDown;
    int intValue(){
        switch (charValue){
            case 'A': return 1;
            case 'K': return 13;
            case 'Q': return 12;
            case 'J': return 11;
            case 'T': return 10;
            default: return int(charValue - '0');
        }
    }
};
class ClockPatience{
private:
    queue<Card> queCard[13];
    Card cardLast;
    int intNumberOfFaceUp;
public:
    void initial();
    void readDeck(char firstChar);
    void playGame();
    void outResult();
};
void ClockPatience::initial(){
    for (int i = 0; i < 13; i++){
        while (!queCard[i].empty()){
            queCard[i].pop();
        }
    }
}
void ClockPatience::readDeck(char firstChar){
    Card card;
    for (int row = 0; row < 4; row++){
        for (int col = 0; col < 13; col++){
            if ((row == 0) && (col == 0)){
                card.charValue = firstChar;
                cin >> card.charSuit;
            }else{
                cin >> card.charValue >> card.charSuit;
            }
            card.boolFaceDown = true;
            queCard[12-col].push(card);
        }
    }
}
void ClockPatience::playGame(){
    int pile;
    intNumberOfFaceUp = 0;
    pile = 12;
    while (queCard[pile].front().boolFaceDown){
        cardLast = queCard[pile].front();
        queCard[pile].pop();
        cardLast.boolFaceDown = false;
        intNumberOfFaceUp++;
        pile = cardLast.intValue() - 1;
        queCard[pile].push(cardLast);
    }
}
void ClockPatience::outResult(){
    cout << intNumberOfFaceUp/10 << intNumberOfFaceUp%10 << ',';
    cout << cardLast.charValue << cardLast.charSuit << endl;
}
////////////////////////////////
int main(){
    char c;
    ClockPatience cp;
    while((cin >> c) && (c != '#')){
        cp.initial();
        cp.readDeck(c);
        cp.playGame();
        cp.outResult();
    }
    return 0;
}