#include <iostream>
#include "D.h"
#include <cstdlib>
#ifndef turn
#define turn
class Turn : public Dice
{

protected:
    int score;
    int tscore;
    char choice;
    bool tover=false;
public:

    void roll()
    {
         rolld();
        std:: cout<<std::endl<<"dice "<<rollv<<std::endl;
        if (rollv==1)
        {
            tover=true;
            score=0;
        }
        else
        {
            score+=rollv;
        }

        if (rollv==1)
        {
            std::cout<<"turn over! No Score!"<<std::endl;
        }
    }
    void hold()
    {
        tover=true;
        tscore=tscore+score;
    }
    void take_turn()
    {
        Dice d1;
        while (tover==false)
        {
          std::  cout<<"roll or hold? (r/h)";
           std:: cin>>choice;
            if ((choice == 'r')||(choice == 'R'))
            {
                roll ();
            }
            else if ((choice == 'h')||(choice == 'H'))
            {
                hold ();

            }
            else
            {
               std:: cout<<"invalid input"<<std::endl;
            }

        }
    }
};
#endif Turn