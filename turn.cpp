#include <iostream>
#include "D.h"
#include <cstdlib>
#include"player.cpp"
#ifndef turn
#define turn
class Turn : public Dice
{

protected:
    int score;
    char choice;
    bool tover=false;
    int tscore;
    bool p1turn=true;
public:
    void roll()
    {
         rolld();
        std:: cout<<std::endl<<"dice "<<rollv<<std::endl;
        if (rollv==1)
        {
            tover=true;
            score=0;
            std::cout<<endl<<"turn over! No Score!"<<std::endl;
        }
        else
        {
            score+=rollv;
        }
    }
    void hold(Player &p1,Player &p2)
    {
        tover=true;
        if (p1turn==true)
        {
            p1.set_ptscore(score);
        }
        else
        {
            p2.set_ptscore(score);
        }

    }
    void take_turn(Player &p1,Player &p2)
    {

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
                hold (p1,p2);

            }
            else
            {
               std:: cout<<"invalid input"<<std::endl;
            }

        }
    }
};
#endif Turn