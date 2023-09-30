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

void PrintBoard(){
    system("cls");

    ///// DRAWING THE BOUNDARIES AND OTHER ELEMENTS /////
    for(int i=0;i<height;i++) {
        for(int j=0;j<width;j++) {
            if(i == 0 || i == width - 1 || j == 0 || j == height - 1) {
                printf("#");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void Setup() {
    srand(time(NULL));

    ///// PLACING THE SNAKE HEAD IN THE CENTER /////
    x = width/2;
    y = height/2;

    ///// PLACING THE FRUIT ON A RANDOM COORDINATE /////
    fx = rand() % 20;
    fy = rand() % 20;
}