#include <iostream>
#include <cstdlib>
using namespace std;
#ifndef player
#define player
class Player
{
private:
    int pturn_count=0;
    int ptscore=0;

    public:
    Player()
    {
        pturn_count=0;
        ptscore=0;
    }
    int get_pturn_count()
    {
        return pturn_count;
    }
    int get_ptscore()
    {
        return ptscore;
    }
    void set_ptscore(int s)
    {
        ptscore +=s;
    }
    void set_pturn_count(int p)
    {
        pturn_count = p;
    }

};
#endif player