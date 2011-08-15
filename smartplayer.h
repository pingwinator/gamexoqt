#include "player.h"
#include "values.h"
#include "map"
#include "stack"


#ifndef SMARTPLAYER_H
#define SMARTPLAYER_H

class SmartPlayer : public Player
{
private:
    //histiry of current game
    struct HistoryElement{
        map<TField, TWeight>::iterator Situation;
        int Move;
        HistoryElement(map<TField, TWeight>::iterator s, int m) :Situation(s), Move(m) {}
    };

    stack<HistoryElement> History;


    map<TField,TWeight> Database;

    //
    map<TField, TWeight>::iterator GetSituation();

    //  ,
    int GetWRandom(map<TField, TWeight>:: iterator s);

public:
    SmartPlayer(char _symbol): Player(_symbol){};

    virtual void MakeMove();
    void Learn(int step);
};
#endif // SMARTPLAYER_H
