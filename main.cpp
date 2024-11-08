#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include "carG.h"
#define CC (x1==n && i==21) || (x1==n && i==22) || (x1==n && i==23) || (x1==n+1 && i==21) || (x1==n+1 && i==22) || (x1==n+1 && i==23) || (x1==n+2 && i==21) || (x1==n+2 && i==22) || (x1==n+2 && i==23) || (x1==n+3 && i==21) || (x1==n+3 && i==22) || (x1==n+3 && i==23) || (x1==n+4 && i==21) || (x1==n+4 && i==22) || (x1==n+4 && i==23)

using namespace std;

COORD coord={0,0};
 void CarG::gotoxy(int x,int y)
 {
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

CarG::CarG()
{
    srand(time(0));
    cash = '$';
    n=27;
    points=0;
    n1=0;
    sleep=150;
}

 void CarG::frame()
 {
     for(int j=1;j<=3;j+=2)
     for(int i=0;i<=24;i++)
     {
         gotoxy(16*j,i);
         cout << char (178);
     }
 }

void CarG::car(int r)
 {

    n=n+r;
    gotoxy(n,22);
    cout << "@   @";
    gotoxy(n,23);
    cout << "| X |";
    gotoxy(n,24);
    cout << "@   @";
 }

void CarG::cls()
 {

    gotoxy(n,22);
    cout << "     ";
    gotoxy(n,23);
    cout << "     ";
    gotoxy(n,24);
    cout << "     ";
 }

void CarG::Ecar(int r, int x2)
{
    gotoxy(x2,r);
    cout << char(219) << "  " << char(219) ;
    gotoxy(x2,1+r);
    cout << char(219) << char(219) << char(219) << char(219) ;
    gotoxy(x2,2+r);
    cout << char(219) << "  " << char(219) ;
}

void CarG::Ecls(int r, int x2)
{
    gotoxy(x2,r);
    cout << "    ";
    gotoxy(x2,r+1);
    cout << "    ";
    gotoxy(x2,r+2);
    cout << "    ";
}

void CarG::movement(char keyp)
{
    switch(keyp)
    {
        case 'A':
        case 'a':
            lmove();
            break;
        case 'D':
        case 'd':
            rmove();
            break;
    }
}

void CarG::lmove()
{
        if(n<=17);
        else
        {   cls();  car(-2);    }
}

void CarG::rmove()
{
        if(n>=42);
        else
        {   cls();  car(+2);    }
}

char CarG::cfun()
{
    for(;;)
    {
        int x1 = rand() % 30 + 17;
        int x2 = rand() % 28 + 17;
        if(x1==x2)
            x1 = rand() % 31 + 17;

        for(int i=0;i<=23;i++)
        {
            gotoxy(x1,i);
            cout << ' ';
            gotoxy(x1,i+1);
            cout << cash;
            if(i==23)
            {
                gotoxy(x1,24);
                cout << ' ';
            }
            Ecar(i, x2);
            Sleep(sleep);
            for(int k=-3;k<=4;k++)
            for(int j=0;j<=3;j++)
            if((x2==n+k && i+2==21+j) || (x2==n+k && i+2==22+j) || (x2==n+k && i+2==23+j))
            {
                keyp=GameOver();
                return keyp;
            }
            Ecls(i, x2);
            if(CC)
            {
                car(0);
                points=points+5;
                break;
            }
            points++;
            displayscore();
            if(_kbhit())
            {
                keyp=_getch();
                if(keyp=='a' || keyp == 'A' || keyp=='D' || keyp=='d')
                {   movement(keyp);  }
                else if(keyp=='Q' || keyp=='q')
                {   return keyp;    }
                else
                {   continue;   }
            }
            if(points%100==0)
            {
                if(sleep>25)
                sleep-=25;
                else if(sleep>15 && sleep<25)
                    sleep-=3;
            }
        }
    }
}

void CarG::displayscore()
{
    gotoxy(50, 15);
    cout << "points = "<< points;
}

char CarG::GameOver()
{
    gotoxy(26,12);
    cout << "GAME OVER";
    gotoxy(23,13);
    cout << "Your Score is : " << points;
    gotoxy(19,15);
    cout << "Want To Play Again? Y/N: ";
    keyp=_getche();
    if(keyp=='y' || keyp=='Y')
    {
        points=0;
        sleep=175;
        return keyp;
    }
    else if(keyp=='n' || keyp=='N')
    {   return 'q'; }
    else
    {   GameOver(); }
    void music(){
               PlaySound(TEXT("123.wav"), NULL, SND_SYNC);
               PlaySound(TEXT("all.wav"), NULL, SND_SYNC);

               }

}
 
