
#include "smartplayer.h"

#include "vector"


//
map<TField, TWeight>::iterator SmartPlayer::GetSituation()
{
 map<TField, TWeight>::iterator p = Database.find(TField());
 //if not found
 if(p == Database.end())
 {
        TWeight w;
        for(int i = 0; i < 9; i++)
        if(GameField[i] != ' ')
                w.Weight[i] = 0;

        Database[TField()] = w;
        return Database.find(TField());
 }
 return p;
};

//  ,
int SmartPlayer:: GetWRandom(map<TField, TWeight>:: iterator s)
{
 //
 int sum = accumulate(s->second.Weight, s->second.Weight+9, 0);
 //
 if (sum == 0)
         //
         return find(GameField, GameField + 9, ' ')-GameField;

 vector<int> coords; //

 for(int i = 0; i < 9; i++)
         fill_n(back_inserter(coords), PrecCoeff*s->second.Weight[i]/sum, i);
 int a= (rand()*coords.size())%RAND_MAX;
 return coords[a];
};

void SmartPlayer::MakeMove()
{
 map<TField, TWeight>::iterator s = GetSituation();

 int move = GetWRandom(s);
 GameField[move] = Symbol;
 History.push(HistoryElement(s,move));
}

void SmartPlayer::Learn(int step)
{
 if (History.empty()) return;

 HistoryElement h = History.top();
 History.pop();

 TWeight& w = h.Situation->second;

 w.Weight[h.Move] += step;
 if(w.Weight[h.Move] < 0) w.Weight[h.Move] = 0;

 Learn((int)step*StepCoeff);
}
