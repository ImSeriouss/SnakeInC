#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

int height=20,width=20,x,y,fx,fy,lastx,lasty,gameover;
enum Input{UP=0,DOWN,LEFT,RIGHT};
enum Input input;

void PrintBoard();
void Input();
void Logic();
void Setup();

typedef struct SnakePart{
    int x;
    int y;
    struct SnakePart* next;
}SnakePart;

int main() {
    gameover = 0;

    while (gameover==0)
    {
        Setup();
        PrintBoard();
    }
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
            else if(i==x && j==y) {
                printf("O");
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

void Input() {
    char c;

    ///// GETTING INPUT FROM THE USER /////
    if(kbhit()) {
        c = getch();
        switch(c) {
            case 'w':
                input = UP;
            case 's':
                input = DOWN;
            case 'a':
                input = LEFT;
            case 'd':
                input = RIGHT;
        }
    }
}

void Logic() {
    ///// MOVING THE SNAKE HEAD ACCORDING TO THE INPUT /////
    if(input==UP) {
        y--;
    }
    else if(input==DOWN) {
        y++;
    }
    else if(input==LEFT) {
        x--;
    }
    else if(input==RIGHT) {
        x++;
    }
}