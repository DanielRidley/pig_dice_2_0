#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void rules(){
    cout << "LET'S PLAY PIG DICE!" << endl;
    cout << endl;
    cout<<"* see how many turns it takes you to get to 20"<<endl
    <<"* turn ends when you hold or roll a 2"<<endl
    <<"* if you roll a 1 you loose all points for the turn"<<endl
    <<"* if you hold you save all points for the turn"<<endl;
}
void roll(int &score,bool &tover)
{
    int dice;
    srand(time(0));
    dice=rand()%6+1;
    if (dice==1)
    {
        tover=true;
        score=0;
    }
    else
    {
        score=score+dice;
    }
    cout<<"dice "<<dice<<endl;
    if (dice==1)
    {
        cout<<"turn over! No Score!"<<endl;
    }
}
void hold(bool &tover,int &tscore,int &score)
{
    tover=true;
    tscore=tscore+score;
}
void take_turn(bool &tover,int &score,int &tscore)
{
    char choice;
    while (tover==false)
    {
        cout<<"roll or hold? (r/h)";
        cin>>choice;
        if ((choice == 'r')||(choice == 'R'))
        {
            roll (score,tover);
        }
        else if ((choice == 'h')||(choice == 'H'))
        {
            hold (tover,tscore,score);

        }
        else
        {
            cout<<"invalid input"<<endl;
        }

    }
}
void play(int &turn)
{
    bool tover=false;
    int tscore = 0;
    int score = 0;
    while (tscore<20)
    {
        score=0;
        turn=turn+1;
        cout<<endl<<"TURN "<<turn<<endl;
        tover=false;
        take_turn(tover,score,tscore);
        if (tover==true)
        {
            cout<<"score for turn:"<<score<<endl;
            cout<<"total score:"<<tscore<<endl;
        }

    }
}
int main()
{
    int turn=0;

    rules();
    play(turn);

    cout<<endl<<"you finished with a final score of 20 or more in "<<turn<<" turns"<<endl;
    return 0;
}
