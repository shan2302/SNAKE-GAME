#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include "field.h"
#define T_ROW 50
#define T_COL 25
#define F_ROW 40
#define F_COL 20
#define SNAKE_LEN 51
#include "snake.h"

void move(int c_col,int c_row,int *f_row,int *f_col,int *point,struct Snake *snake,int *cur_snake_len)
{
    system("cls");
    if(c_row==*f_row&&c_col==*f_col)
    {
        int i;
        
        *f_row=rand()%(T_ROW+1);
        *f_col=rand()%(T_COL+1);
        printf("collision");
        *point=*point+1;
        cur_snake_len+=1;
        printf("%d",*f_col);
        printf("%d",*f_row);
    }
    for(int i=0;i<*cur_snake_len;i++)
    {
        snake[i].x=snake[i+1].x;
        snake[i].y=snake[i+1].y;
        if(i==*cur_snake_len-1)
        {
            snake[i].x=c_row;
            snake[i].y=c_col;
        }
    }
    field(T_ROW,T_COL,c_row,c_col,*f_row,*f_col,*point,snake,*cur_snake_len);
    
}
int main()
{
    int c_row=T_ROW/2;
    int c_col=T_COL/2;
    char p_key;
    int f_row=F_ROW;
    int f_col = F_COL;
    bool game_over = false;
    int point=0;
    struct Snake snake[SNAKE_LEN];
    snake[0].x=c_row;
    snake[0].y=c_col;
    int cur_snake_len=1;
    field(T_ROW,T_COL,c_row,c_col,f_row,f_col,point,snake,cur_snake_len);
    while (!game_over)
    {
    // scanf("%c",&p_key);
    while (kbhit()) p_key = getch(); 
    while (p_key == -32 || p_key == 0) p_key = getch();
    printf("\n");
    int easy=100;
    int med=50;
    int hard=25;
    switch (p_key)
    {
    case 'd':
        if(c_col==T_COL-2)
            c_col=1;
        move(c_col++,c_row,&f_row,&f_col,&point,snake,&cur_snake_len);
        break;       
    case 'a':
        if(c_col==1)
            c_col=T_COL-1;
        move(c_col--,c_row,&f_row,&f_col,&point,snake,&cur_snake_len);
        break;
    case 'w':
        if(c_row==1)
            c_row=T_ROW-1;
        move(c_col,c_row--,&f_row,&f_col,&point,snake,&cur_snake_len);
        break;
    case 's':
        if(c_row==T_ROW-2)
            c_row=1;
        move(c_col,c_row++,&f_row,&f_col,&point,snake,&cur_snake_len);
        break;
    case 'q':
        game_over=true;
        break;
    default:
        break;
    }
    Sleep(easy);
    }
    // printf("/n%c",p_key);
    
}