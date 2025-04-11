#include <iostream>
#include <cstdlib>
#include <ctime>

#ifndef D_H
#define D_H

class Dice
{
protected:
    int dicesize;
    int rollv;
public:
    void Dicetype(int choice)
    {
        dicesize = choice;
    }
    void rolld()
    {
        srand(time(0));
        rollv=rand()%dicesize+1;

    }
};
#endif D_H
