#include "values.h"

void PrintField()
{
        cout << GameField[0] << "|" << GameField[1] << "|" << GameField[2] << endl;
        cout << GameField[3] << "|" << GameField[4] << "|" << GameField[5] << endl;
        cout << GameField[6] << "|" << GameField[7] << "|" << GameField[8] << endl;
        cout << endl;
}
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
