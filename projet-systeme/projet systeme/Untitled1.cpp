
#include <stdlib.h>
//#include"stdio.h"
#include<iostream>
//#include<conio.h>
#include<windows.h>

using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void settextcolor(int color)
{
    HANDLE h;
    h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,color);  
}
int main()
{    printf("Press any key to exit...");
    settextcolor(2);
    cout<<"Welcome to the color changing application!\n";
    printf("Press any key to change the background color!\n");
    
    settextcolor(6);
    printf("Now the background color is Yellow and Text Color is light Red\n");
    printf("Press any key to exit...");
    return 0;
}
