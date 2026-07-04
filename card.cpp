#include <iostream>
#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
enum class Suit = {Hearts = 0, Diamond, Club, Spade};
enum class Rank = {two = 2, three, four, five, six, seven, eight, nine, ten, jack ,king, queen, ace};
class Card{
    Suit S;
    Rank R;
    int value;
    public:
    Card(Suit x, Rank y){
        S = x;
        R = y;
        this->value = valueCalculator();
    }
    int valueCalculator(){
    int r = static_cast<int>(R);
    if (r>=10){r = 10;}
    if (R==Rank::ace) {r = 11;}
    return r;
}
    display(){
        cout<<S<<" "<<R<<endl;
    }
}
class Deck{
    vector <Cards> cards;
    void build();
    pubic:
    void shuffle();
    void reBuild();
    int remainingCard() const;
    Card topCard(); //return the top card, show it and remove it from this class
}
void Deck::build{
    cards.clear();
    for (int i = 0 ; i< 4 ;i++){
        for (j=0;j<=14;j++){
            cards.push_back({static_cast<Suit>(i),staic_cast<Rank>(j)});
        }
    }
}