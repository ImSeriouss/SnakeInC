#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define HEIGHT 20
#define WIDTH 20

int x,y,fx,fy,gameover,ntail=0;
enum Input{UP=0,DOWN,LEFT,RIGHT,STOP};
enum Input input;

void PrintBoard();
void Input();
void Logic();
void Setup();

struct SnakePart {
    int x;
    int y;
    int lastx;
    int lasty;
};

struct SnakePart snake[HEIGHT*WIDTH];

int main() {
    Setup();

    while (gameover==0){
        PrintBoard();
        Input();
        Logic();
        Sleep(150);
    }
    system("PAUSE");
    return 0;
}

void PrintBoard(){
    system("cls");

    ///// DRAWING THE BOUNDARIES AND OTHER ELEMENTS /////
    for(int i=0;i<WIDTH+2;i++) {
        printf("#");
    }
    printf("\n");

    for(int i=0;i<HEIGHT;i++) {
        for(int j=0;j<WIDTH;j++) {
            if(j==0) {
                printf("#");
            }
            int isTail=0;
            for(int k=0;k<ntail;k++) {
                if(snake[k].x == j && snake[k].y == i) {
                    printf("o"); //Snake tail
                    isTail = 1;
                }
            }
            if(i == y && j == x) {
                printf("O"); //Head of the snake
            }
            else if(i==fy && j==fx) {
                printf("@"); //Fruit
            }
            else if(!isTail) {
                printf(" "); //Empty space
            }
            if(j == WIDTH-1) {
                printf("#");
            }
        }
        printf("\n");
    }

    for(int i=0;i<WIDTH+2;i++) {
        printf("#");
    }
}

void Setup() {
    srand(time(NULL));
    gameover = 0;
    input = STOP;

    ///// PLACING THE SNAKE HEAD IN THE CENTER /////
    x = WIDTH/2;
    y = HEIGHT/2;

    snake[0].x = x;
    snake[0].y = y;

    ///// PLACING THE FRUIT ON A RANDOM COORDINATE /////
    fx = rand() % 20;
    fy = rand() % 20;


}

void Input() {
    ///// GETTING INPUT FROM THE USER /////
    if(_kbhit()) {
        switch(_getch()) {
            case 'w':
                input = UP;
                break;
            case 's':
                input = DOWN;
                break;
            case 'a':
                input = LEFT;
                break;
            case 'd':
                input = RIGHT;
                break;
        }
    }
}

void Logic() {
    ///// REMEMBERING THE LAST POSITION OF THE HEAD /////
    int lastx,lasty;
    lastx = x;
    lasty = y;

    ///// MOVING THE SNAKE'S TAIL /////
    for(int i=0;i<ntail;i++) {
        int tempX = snake[i].x;
        int tempY = snake[i].y;
        snake[i].x = lastx;
        snake[i].y = lasty;
        lastx = tempX;
        lasty = tempY;
    }

    ///// MOVING THE SNAKE HEAD ACCORDING TO THE INPUT /////
    switch(input) {
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        default:
            break;
    }

    ///// CHECK IF THE SNAKE COLLIDED WITH THE FRUIT AND GENERATE A NEW FRUIT /////
    if(x == fx && y == fy) {
        fx = rand() % WIDTH;
        fy = rand() % HEIGHT;
        ntail++;
    }

    ///// CHECK IF THE SNAKE COLLIDED WITH ITS TAIL /////
    for(int i=1;i<ntail;i++) {
        if(snake[i].x == x && snake[i].y == y) {
            gameover = 1;
        }
    }

    ///// CHECK IF THE SNAKE COLLIDED WITH THE BORDER /////
    if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        gameover = 1;
    }
}