#include <QtCore/QCoreApplication>
#include "player.h"
#include "humanplayer.h"
#include "randomplayer.h"
#include "smartplayer.h"

#pragma once

void PlayGame(Player *Xp, Player *Op, bool Verbose)
{
    Player *Cp[] = {Xp, Op};
    //
    int move = 0;

    fill(GameField, GameField+9,' ');
    while(GetOutCome() == UNFINISHED)
    {
            Cp[move++ % 2] -> MakeMove();
            if (Verbose) PrintField();
    }
    ///
    //
    if(GetOutCome() == Xs)
    {
            Xp->Learn(LearningStep);
            Op->Learn(-LearningStep);
    }
    else if(GetOutCome() == Os)
    {
            Xp->Learn(-LearningStep);
            Op->Learn(LearningStep);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    RandomPlayer *r = new RandomPlayer('0');
    HumanPlayer *h = new HumanPlayer('0');
    SmartPlayer *s = new SmartPlayer('X');

    for(int k = 0; k < 2; k++)
            PlayGame((Player*)s, (Player*)r, true);
    PlayGame((Player*)s,(Player*)h,true);

    delete s;
    delete h;
    delete r;
    return a.exec();
}
