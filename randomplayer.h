#include "player.h"
#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H

class RandomPlayer : public Player
{
public:
    RandomPlayer(char _symbol): Player(_symbol){};
    virtual void MakeMove();
};

#endif // RANDOMPLAYER_H
