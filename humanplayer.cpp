#include "humanplayer.h"
#include "values.h"



void HumanPlayer :: MakeMove()
{
        int Cell = 0;
        std::cin >> Cell;
        GameField[Cell] = Symbol;
};
