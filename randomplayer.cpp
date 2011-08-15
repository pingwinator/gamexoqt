#include "randomplayer.h"
#include "values.h"
#include "vector"

void RandomPlayer :: MakeMove()
{

    std::vector<int> v;
    //remember the numbers of empty cells
    for(int i = 0; i < 9; i++)
    {
            if (GameField[i] == ' ')
                    v.push_back(i);
            int a = (rand()*v.size())%RAND_MAX;
            GameField[v[a]] = Symbol;
    }
};
