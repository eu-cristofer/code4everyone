/*
    Code Title

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/

#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

enum class suit:short{SPADE, HEART, DIAMOND, CLUB};

class pips{
private:
    int v;
public:
    pips(int val):v(val){assert(v>0 && v<14);}
    friend ostream& operator<<(ostream& out, const pips& p);
    int get_pips(){return v;}
};

ostream& operator<<(ostream& out, const pips& p){
    out << p.v;
    return out;
}

class card
{
private:
    /* data */
    suit s;
    pips v;
public:
    card():s(suit::SPADE),v(1){}
    card(suit s, pips v):s(s),v(v){}
    friend ostream& operator<<(ostream& out, const card& c);
    suit get_suit(){return s;}
    pips get_pips(){return v;}
};

ostream& operator<<(ostream& out, const card& c){
    // a scoped enumeration is not implicitly convertible to 
    // its integer value. You need to explicitly convert it to
    // an integer using a cast:
    out << c.v << static_cast<std::underlying_type<suit>::type>(c.s);
    return out;
}

void init_deck(vector<card>& d){
    for(int i=1; i<14; i++){
        card c(suit::SPADE,i);
        d[i-1] = c;
        c = card(suit::HEART,i);
        d[i+12] = c;
        c = card(suit::DIAMOND,i);
        d[i+24] = c;
        c = card(suit::CLUB,i);
        d[i+38] = c;
    }
}

void print(vector<card>&& deck){
    for(auto p=deck.begin(); p!=deck.end();++p)
        cout << *p;
    cout << endl;
}

void print1(vector<card>&& deck){
    for(auto cardval:deck)
        cout << cardval;
    cout << endl;
}

bool is_flush(vector<card>& hand){
    suit s=hand[0].get_suit();
    for(auto p=hand.begin() + 1; p!=hand.end(); ++p)
        if(s!=p->get_suit())
            return false;
        return true;
}

bool is_straight(vector<card>& hand){
    int pips_v[5], i = 0;
    for(auto p=hand.begin(); p!=hand.end(); ++p)
        pips_v[i++] = (p->get_pips()).get_pips();
        sort(pips_v, pips_v + 4); //STL iterator range
    if(pips_v[0] != 1) // non-aces
        return (pips_v[0] == pips_v[1]-1 && pips_v[1] == pips_v[2]-1 && pips_v[2] == pips_v[3]-1 && pips_v[3] == pips_v[4]-1);
    else // aces have a special logic
        return (pips_v[0] == pips_v[1]-1 && pips_v[1] == pips_v[2]-1 && pips_v[2] == pips_v[3]-1 && pips_v[3] == pips_v[4]-1) || (pips_v[1] == 10 && pips_v[2] == 11 && pips_v[3] == 12 && pips_v[4] == 13);
}

bool is_straight_flush(vector<card>& hand){
    return is_flush(hand) && is_straight(hand);
}

int main(int argc, const char * argv[]) {
    
    /* code */
    vector<card> deck(52);
    srand(time(0));
    init_deck(deck);
    int how_many;
    int flush_count = 0;
    int str_count = 0;
    int str_flush_count = 0;
    cout << "   How many shufles?";
    cin >> how_many;

    for(int loop = 0; loop < how_many; ++loop){
        random_shuffle(deck.begin(), deck.end()); //STL algorithm
        vector<card> hand(5);
        int i = 0;
        for(auto p=deck.begin(); i < 5; ++p)
            hand[i++] = *p;
        if(is_flush(hand))
            flush_count++;
        if(is_straight(hand))
            str_count++;
        if(is_straight_flush(hand))
            str_flush_count++;
    };
    cout << " Flushes " << flush_count << " out of " << how_many << endl;
    cout << " Straights " << str_count << " out of " << how_many << endl;
    cout << " Straight Flushes " << str_flush_count << " out of " << how_many << endl; 
    
    return 0;
}