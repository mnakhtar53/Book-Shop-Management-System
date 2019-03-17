#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>     //for strcmp
#include<process.h>    //for exit
#include<stdio.h>
#include "LOGIN.C"
#include "MENU.C"

void main()
{

   Login l;
   clrscr();
   l.main_window();

   getch();
}
