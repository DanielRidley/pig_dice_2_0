#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.cpp"
#include "D.h"
#include "turn.cpp"
using namespace std;
int main()
{
    Game mygame;
    mygame.rules();
    mygame.play();
return 0;
}