#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

int height=20,width=20,x,y,fx,fy,lastx,lasty;

void PrintBoard();
void Input();
void Logic();
void Setup();

typedef struct SnakePart{
    int x;
    int y;
    SnakePart* next;
}SnakePart;

int main() {


    return 0;
}