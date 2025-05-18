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

void move(int c_col,int c_row,int *f_row,int *f_col,int *point,struct Snake *snake,int *cur_snake_len,bool *game_over)
{
    
    system("cls");
    
    if(c_row==*f_row&&c_col==*f_col)
    {
        
        int i;
        *cur_snake_len+=1;
        snake[*cur_snake_len].x=*f_row;
        snake[*cur_snake_len].y=*f_col;
        *f_row=(rand()%(T_ROW-2))+1;
        *f_col=(rand()%(T_COL-2))+1;
        printf("collision");
        *point=*point+1;
        printf("%d",*f_col);
        printf("%d",*f_row);
    }
    for (int i = *cur_snake_len - 1; i > 0; i--)
    {
        snake[i].x = snake[i - 1].x;
        snake[i].y = snake[i - 1].y;
    }
    snake[0].x = c_row;
    snake[0].y = c_col;
    field(T_ROW,T_COL,c_row,c_col,*f_row,*f_col,*point,snake,*cur_snake_len);
    for(int i=0;i<=*cur_snake_len;i++)
    {
        for(int j=i+1;j<*cur_snake_len;j++)
        {
            if(snake[i].x==snake[j].x&&snake[i].y==snake[j].y)
            {
                *game_over=true;
                printf("\nYour score is: %d",*point);
            }
        }
    }
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
    char cur_dir='b';
    while (!game_over)
    {
    // scanf("%c",&p_key);
    while (kbhit()) p_key = getch(); 
    while (p_key == -32 || p_key == 0) p_key = getch();
    printf("\n");
    if(cur_dir=='a'&&p_key=='d'&&cur_snake_len>1)
    {
        p_key='a';
    }
    else if(cur_dir=='d'&&p_key=='a'&&cur_snake_len>1)
    {
        p_key='d';
    }
    else if(cur_dir=='w'&&p_key=='s'&&cur_snake_len>1)
    {
        p_key='w';
    }
    else if(cur_dir=='s'&&p_key=='w'&&cur_snake_len>1)
    {
        p_key='s';
    }
    int easy=500;
    int med=200;
    int hard=100;
    // char cur_dir;
    switch (p_key)
    {
    case 'd':
        cur_dir='d';
        if(c_col==T_COL-2)
            c_col=1;
        move(c_col++,c_row,&f_row,&f_col,&point,snake,&cur_snake_len,&game_over);
        break;       
    case 'a':
        cur_dir='a';
        if(c_col==1)
            c_col=T_COL-1;
        move(c_col--,c_row,&f_row,&f_col,&point,snake,&cur_snake_len,&game_over);
        break;
    case 'w':
        cur_dir='w';
        if(c_row==1)
            c_row=T_ROW-1;
        move(c_col,c_row--,&f_row,&f_col,&point,snake,&cur_snake_len,&game_over);
        break;
    case 's':
        cur_dir='s';
        if(c_row==T_ROW-2)
            c_row=1;
        move(c_col,c_row++,&f_row,&f_col,&point,snake,&cur_snake_len,&game_over);
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