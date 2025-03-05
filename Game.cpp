#include <iostream>
#include "D.h"
#include <cstdlib>
#include "turn.cpp"
using namespace std;
#ifndef game
#define game
 class Game : public Turn
 {
  private:
  int turnc;
  int dsides;
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
Turn t1;
   cout<<"how many sides do you want?"<<endl;
   cin>>dsides;
   Dicetype(dsides);
   while (tscore<20)
   {
    score=0;
    turnc=turnc+1;
    cout<<endl<<"TURN "<<turnc<<endl;
    tover=false;
    take_turn();
    if (tover==true)
    {
     cout<<"score for turn:"<<score<<endl;
     cout<<"total score:"<<tscore<<endl;
    }

   }
 cout<<endl<<"you finished with a final score of 20 or more in "<<turnc<<" turns"<<endl;
  }
 };
#endif game