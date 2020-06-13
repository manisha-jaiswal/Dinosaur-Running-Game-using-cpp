#include<windows.h>
#include<mmsystem.h> //windows multimedia functions used to play music
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <time.h> 
#include<dos.h> // for command prompt
char strname[100] ;
 int static score=0;
void gotoxy(int x, int y) //gotoxy function places cursor at a desired location on screen i.e., 
//we can change cursor position using gotoxy function. 
//Declaration: void gotoxy(int x, int y); where (x, y) is the position where we want to place the cursor.
{
 COORD coord;
 /*Defines the coordinates of a character cell in a console screen buffer. 
 The origin of the coordinate system (0,0) is at the top, left cell of the buffer.*/
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//This specifies the new position of the cursor that we will set.
} 
void delay(int mseconds) //This function is used for giving the score
{
   clock_t goal = mseconds + clock();
    while (goal > clock());
}
void getup() //used for giving name before starting the program
{
    system("cls");
    gotoxy(30,0); //x=30 and y=0 position
	printf("Player Name:-  ");
	scanf("%s",strname);
    gotoxy(10,2); //x=10 and y=2 position
    printf("Press X to Exit, Press Space to Jump");
    gotoxy(62,2); //x=62 and y=2 position
    printf("SCORE : ");
    gotoxy(1,25); //x=1 and y=25 position
    for(int x=0;x<79;x++)
    	printf("ß");
}
 
int t,speed=12;
void ds(int jump=0)
{

    static int a=1;
    if(jump==0)
        t=0;
    else if(jump==2)
	   t--;
    else t++;
    gotoxy(2,15-t);
    printf("                 ");
    gotoxy(2,16-t);
    printf("         ÜÛßÛÛÛÛÜ");
    gotoxy(2,17-t); 
    printf("         ÛÛÛÛÛÛÛÛ");
    gotoxy(2,18-t);
    printf("         ÛÛÛÛÛßßß");
    gotoxy(2,19-t);
    printf(" Û      ÜÛÛÛÛßßß ");
    gotoxy(2,20-t);
    printf(" ÛÛÜ  ÜÛÛÛÛÛÛÜÜÜ ");
    gotoxy(2,21-t);
    printf(" ßÛÛÛÛÛÛÛÛÛÛÛ  ß ");
    gotoxy(2,22-t);
    printf("   ßÛÛÛÛÛÛÛß     ");
    gotoxy(2,23-t);
    if(jump==1 || jump==2){
    printf("    ÛÜ   ÛÜ      ");
    }else if(a==1)
    {
    printf("    ßÛÛß  ßßß    ");
    gotoxy(2,24-t);
    printf("      ÛÜ         ");
    a=2;
    }
    else if(a==2)
    {
    printf("     ßÛÜ ßÛ      ");
    gotoxy(2,24-t);
    printf("          ÛÜ     ");
    a=1;
    }
    gotoxy(5,25-t);
    if(jump!=0){
        printf("                ");
    }
    else
    {
         printf("ßßßßßßßßßßßßßßßßß");
    }
    delay(speed);
}
void obj()
{

    static int x=0,scr=0;
     if(x==56 && t<1)
    {
    scr=0;
    speed=12;
    gotoxy(36,8);
    printf("Game Over");
    PlaySound(0,0,0);
    PlaySound(("myfile.wav"),NULL,SND_LOOP|SND_ASYNC);
    /*SND_ASYNC flag. It says that you want this call to return immediately and play the sound in background.
     If you do this in a loop, since it will return with the sound still playing, */
    getch();
    gotoxy(36,8);
    printf("         ");
    }
   	gotoxy(74-x,20);
    printf("Û    Û ");
    gotoxy(74-x,21);
    printf("Û    Û ");
    gotoxy(74-x,22);
    printf("ÛÜÜÜÜÛ ");
    gotoxy(74-x,23);
    printf("  Û    ");
    gotoxy(74-x,24);
    printf("  Û  " );
    x++;
    if(x==73)
    {
    x=0;
    scr++;
    gotoxy(70,2);
    printf("     ");
    gotoxy(70,2);
    printf("%d",scr);
    score=scr;
    if(speed>60)
        speed--;
    }
}
int main()
{
	 PlaySound(("myfile.wav"),NULL,SND_LOOP|SND_ASYNC);
    system("mode con: lines=29 cols=82");////sets window size! I think it will modify the console window size.
   	system("color 4A");
   char ch;
    int i;
    getup();
    while(true)
    {
        while(!kbhit())//kbhit() is present in conio.h and used to determine if a key has been pressed or not.
        // To use kbhit function in your program you should include the header file “conio.h
        {
            ds();
            obj();
        }
        ch=getch();
        if(ch==' ')
        {	 
            for(i=0;i<10;i++)
            {
            ds(1);
            obj();
           if(score<=20&&score>10){
             gotoxy(36,8);
             printf("Very Good Jump");
			}
			if(score<=40&&score>20){
				gotoxy(36,8);
				printf("Excellent Jump");
			}
			if(score>70 ){
				gotoxy(36,8);
				printf("Excellent Concentration Jump");
			}
			if(score<=10){
				gotoxy(36,8);
            	printf("Good Jump");
			}
            }
            for(i=0;i<10;i++)
            {
            	gotoxy(36,8);
           	 	printf("                                             ");
            ds(2);
            obj();
            }
        }
        else if (ch=='x')
            return(0);
    } 
     
}

