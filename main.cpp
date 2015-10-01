/* 
 * File:   main.cpp
 * Author: iCheater
 *
 * Created on June 20, 2015, 9:04 PM
 */
#include <cstdlib>
#include <iostream> // cin, cout
#include <cstdlib> // clear,
#include <unistd.h> // usleep
#include <time.h> // time_t,clock
#include <ctype.h> // cin.get(),


//#include <stdio.h>
//#include <wchar.h>
//#include <locale.h>
//#include <stdlib.h>
//#include <ctime>

using namespace std;

int randomizer(int min, int max)
{
    
    int r =  min + rand() %  max ;
//    r = rand() % 7;		// 0 ... 6
//    r = 1 + rand() % 7;	// 1 ... 7
//    r = 200 + rand() % 101;	// 200 ... 300
//    r = rand() % 41 - 20;	// -20 ... 20
//    r = 0.01 * (rand() % 101);// 0.01 ... 1
    return r; 
}

//void testASCII()
//{
//setlocale( LC_ALL, "en_US.UTF-8");
//    int i;
//    i=0;
//    do
//    {
//       // printf("%d %c \n",i,i);
//        wprintf (L"%d %lc\n",i, i);
//        i++;
//    }
//    while(i<=255);
//}

void displayfield()
{
    int field [6][6];
    int t = 0;
    for (int i = 0 ; i < 5 ; i++)
    {
        cout << "\n";
        for (int j = 0 ; j < 5 ; j++)
        {
            field[i][j] = t ; 
            t++;
            printf(" %.2d", field[i][j]);
        }
    }
}



int main()
{
    srand (time(NULL));
    char userLetter;
    time_t startTime, endTime;
    double diffTime;
    float typeSpeed;
    int gstep = 0;
    
    do
    {
        int Step = 0;
        int Errors = 0;
        int letterCount;
        char letters[ letterCount ];
        int letter[letterCount];
        cout << "Введи длинну строки?\n";
        cin >> letterCount;
        for (int i=0;i < letterCount; i++)
        {
            letter[i] = randomizer(65,26);
        }
        for(int i = 0; i < letterCount; ++i)
        {
            printf(".",fflush(stdout));
            usleep(35000);     
        }
        cin.get();
        cout << "\n";
        time (&startTime);
        do
        {
            system("clear");
            for( int i = 0; i < letterCount; i++)
            {

                if ( i < Step )
                {
                    printf("%c ", 176);
                }
                else
                {
                    printf("%c ", letter[i]);
                }
            }
            cout << "\n";
            cin >> userLetter;
            if( userLetter == letter[Step])
            {
                Step++;
            } 
            else
            {
                Errors++;
            }
        }
        while (Step < letterCount ); 
        
        system("clear");
        time (&endTime);
        diffTime = endTime - startTime;
        typeSpeed = letterCount/diffTime * 60;

        printf("Ошибок: %d\n",Errors);
        printf("Время игры: %.f сек\n",(diffTime));
        printf("Ваша скорость: %.f символов/минуту\n",(typeSpeed));
        printf ("Еще разок Y\\N? \n") ;
        char t ;
        cin >> t;
        if (t == 'Y')
        {
            gstep = 0;
            system("clear");
        }
        else
        {
            gstep = 1;
            system("clear");
            cout << "Досвидос!\n";
            for(int i = 0; i < letterCount; ++i)
            {
                printf(".",fflush(stdout));
                usleep(35000);     
            }
        }
        
    }
    while (gstep == 0);

}