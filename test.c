// given [a,b,c,d,e] nv=f  =========> [b,c,d,e,f]
#include <stdio.h>
struct Arr
{
    int x,y; 
};
int main()
{
    struct Arr arr1[5];
    arr1[0].x= 1;
    arr1[0].y=11;
    arr1[1].x= 2;
    arr1[1].y=12;
    arr1[2].x= 3;
    arr1[2].y=13;
    arr1[3].x= 4;
    arr1[3].y=14;
    arr1[4].x= 5;
    arr1[4].y=15;
    int newx=20,newy=40;
    printf("Previous:\n");
    for(int i=0;i<5;i++)
    {
        printf("(%d,",arr1[i].x);
        printf("%d)",arr1[i].y);
    }
    for(int i=0;i<5;i++)
    {
        arr1[i].x=arr1[i+1].x;
        arr1[i].y=arr1[i+1].y;
        if(i==4)
        {
            arr1[i].x=newx;
            arr1[i].y=newy;
        }
    }
    printf("Latest:\n");
    for(int i=0;i<5;i++)
    {
        printf("(%d,",arr1[i].x);
        printf("%d)",arr1[i].y);
    }
}