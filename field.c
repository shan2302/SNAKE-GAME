#include <stdio.h>
#include "snake.h"
void field(int t_row,int t_col,int s_row,int s_col,int f_row,int f_col,int point,struct Snake snake[],int snake_len,char snake_sym)
{
    int row,col;
    for(row=0;row<t_row;row++)
    {
        for(col=0;col<t_col;col++)
        {
            int is_snake=0;
            for(int i=0;i<snake_len;i++)
            {
                if(snake[i].x==row&&snake[i].y==col)
                {
                    printf("%c ",snake_sym);
                    is_snake=1;
                    break;
                }
            }
            if(is_snake)
                continue;
            if(row==0||row==t_row-1)
            {
                printf("* ");
            }
            else if(row==f_row && col==f_col)
            {
                printf("# ");
            }
            else
            {
                if(col==0||col==t_col-1)
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }
            
            
        }
        
        if(row==0)
        {
            printf("\t");
            printf("Points: %d",point);
        }
        printf("\n");
    }
}