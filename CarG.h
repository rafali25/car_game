#ifndef CARG_H
#define CARG_H
#include <windows.h>
#include <stdlib.h>
#include <iomanip>
#include <thread>

class CarG
{
    private:
        int sleep;
        int points;
        int n, n1;
        char cash, keyp;
    public:
        Sleep(3500);
        music();
        thread t1(music);
        t1.detach();
        CarG();
        void gotoxy(int x, int y);
        void frame();
        void car(int r);
        void cls();
        void movement(char keyp);
        void lmove();
        void rmove();
        char cfun();
        void displayscore();
        void Ecar(int r, int x2);
        void Ecls(int r, int x2);
        char GameOver();
};

#endif // CARG_H
