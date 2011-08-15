#include "player.h"
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H


class HumanPlayer : public Player
{
public:
    HumanPlayer(char _symbol): Player(_symbol){}
    //next course
    virtual void MakeMove();
};


#endif // HUMANPLAYER_H
