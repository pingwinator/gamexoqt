#ifndef PLAYER_H
#define PLAYER_H
/*
class Player
{
public:
    Player();
};
*/
class Player
{
protected:
    char Symbol;// x or 0
public:
    Player(char _symbol) : Symbol(_symbol){}
    //next course
    virtual void MakeMove() = 0;
    //make 1 iteration of learning
    virtual void Learn(int){}
};

#endif // PLAYER_H
