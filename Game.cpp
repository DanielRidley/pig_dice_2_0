#include <iostream>
#include "D.h"
#include <cstdlib>
#include "turn.cpp"
#include "player.cpp"
using namespace std;
#ifndef game
#define game
 class Game : public Turn
 {
  private:
  int turnc=0;
  bool winner=false;
  void checkWinner(int player1s,int player2s)
  {
   if(player1s>=50||player2s>=50)
   {
    winner=true;
   }
  }
  public:
  void rules(){
   cout << "LET'S PLAY PIG DICE!" << endl;
   cout << endl;
   cout<<"* see how many turns it takes you to get to 20"<<endl
   <<"* turn ends when you hold or roll a 2"<<endl
   <<"* if you roll a 1 you loose all points for the turn"<<endl
   <<"* if you hold you save all points for the turn"<<endl;
  }

  void play()
  {
Player p1;
   Player p2;

   int dsides;
   cout<<"how many sides do you want?"<<endl;
   cin>>dsides;
   Dicetype(dsides);
   while ((p1.get_ptscore()<50||p2.get_ptscore()<50)and (winner==false))
   {
    score=0;
    if (p1turn==true)
    {
     turnc++;
     p1.set_pturn_count(turnc);
     cout <<endl<<"TURN "<< p1.get_pturn_count() << endl<<"Player one's turn"<<endl;
    }
    else
    {
     p2.set_pturn_count(turnc);
     cout<<endl <<"Player two's turn"<<endl;
    }
    tover=false;
    take_turn(p1,p2);
    if (tover==true)
    {
     cout<<"score for turn:"<<score<<endl;
     if (p1turn==true)
     {
      cout<<"Total score: "<<p1.get_ptscore()<<endl;
     }
     else
     {
      cout<<"Total score: "<<p2.get_ptscore()<<endl;
     }
     if ((p1.get_pturn_count()==p2.get_pturn_count())and (p1.get_ptscore()>=50||p2.get_ptscore()>=50))
     {
      winner=true;
     }
     p1turn=!p1turn;
    }

   }
 if (p1.get_ptscore()>p2.get_ptscore())
 {
  cout<<endl<<"Player one has won the game!"<<endl;
 }
   else if (p1.get_ptscore()<p2.get_ptscore())
   {
    cout<<endl<<"Player two has won the game!"<<endl;
   }
   else
   {
    cout<<endl<<"TIE!"<<endl;
   }
  }
 };
#endif game