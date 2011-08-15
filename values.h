#include <iostream>
#include <string>
#include <cstdlib>

#ifndef VALUES_H
#define VALUES_H

using namespace std;
#define InitWeight 100//weight for begin
#define PrecCoeff 50//accuracy of generator
#define StepCoeff 0.65//"learning koefficient"
#define LearningStep 20


static char GameField[9];

enum OUTCOME { Xs, Os, DRAW, UNFINISHED };
/*
        current state of game:
        won "x" -> Xs
        won "x" -> Os
        draw -> DRAW
        unfinished -> UNFINISHED
*/
struct TField//
{
        char Field[9];
        TField() { copy(GameField, GameField + 9, Field); };
        bool operator<(const TField& rhs) const
        {
                return lexicographical_compare(Field, Field + 9, rhs.Field, rhs.Field + 9);
        }
};

//matrix of weight
struct TWeight
{
        int Weight[9];
        TWeight(){ fill(Weight, Weight+9, InitWeight);}
};
void PrintField();
/*
        //current stage of game field
void PrintField()
{
        cout << GameField[0] << "|" << GameField[1] << "|" << GameField[2] << endl;
        cout << GameField[3] << "|" << GameField[4] << "|" << GameField[5] << endl;
        cout << GameField[6] << "|" << GameField[7] << "|" << GameField[8] << endl;
        cout << endl;
}
*/
OUTCOME GetOutCome();
/*
OUTCOME GetOutCome()
{
        //position to win
        int V[8][3] =
        { {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6},
          {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6} };

        //if it is WIN combination
        for(int i = 0; i < 8; i++)
                if (GameField[V[i][0]] == GameField[V[i][1]] &&
                        GameField[V[i][0]] == GameField[V[i][2]] &&
                        GameField[V[i][0]] != ' ')
                        return GameField[V[i][0]] == 'x' ? Xs : Os;
        return (find(GameField, GameField+9, ' ') == GameField +9) ? DRAW : UNFINISHED;
};
*/
#endif // VALUES_H
