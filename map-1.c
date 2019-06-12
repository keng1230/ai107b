#include<stdio.h>
#include<stdlib.h>
#define SIZE 7 //定義地圖大小
typedef struct{         //宣告 .structure
    int x;              //x為縱座標
    int y;              //y為橫坐標
}Point;

Point pt(int,int);      //利用陣列的index製造一個point
int visit(int[][SIZE],Point,Point);     //回傳一個整數
void print(int[][SIZE]);
int main(void)
{
    int maze[SIZE][SIZE]=
    {
    {2,2,2,2,2,2,2},
    {2,0,0,0,0,0,2},
    {2,0,2,0,2,0,2},
    {2,0,0,2,0,2,2},
    {2,2,0,2,0,2,2},
    {2,0,0,0,0,0,2},
    {2,2,2,2,2,2,2}
    };
    if(!visit(maze,pt(1,1),pt(5,5))){       //輸出為0表示沒找到出口
        printf("沒找到出口\n");
    }
        print(maze);
        system("pause");
        return 0;
}    
Point pt(int x, int y){
        Point p = {x,y};
        return p;
}
int visit(int maze[][SIZE],Point start,Point end)
{
    if(!maze[start.x][start.y])
    {
        maze[start.x][start.y] = 1;     //走過變1
        if(!maze[end.x][end.y]&&        //終點沒被訪問過，進行下面遞迴
        !(visit(maze,pt(start.x,start.y + 1),end)||
        visit(maze,pt(start.x + 1,start.y),end)||
        visit(maze,pt(start.x,start.y - 1),end)||
        visit(maze,pt(start.x - 1,start.y),end)))
        {
            maze[start.x][start.y] = 0;     //若沒找到出口,將1還原為0
        }
    }
    return maze[end.x][end.y];
}
    void print(int maze[][SIZE])
    {
                    int i,j;
                    for(i=0;i<SIZE;i++)
                    {
                        for(j=0;j<SIZE;j++)
                        {
        switch(maze[i][j])
        {
            case 0 : printf(" ");break;
            case 1 : printf(".");break;
            case 2 : printf("#");
        }
                        }
        printf("\n");
                    }
    }
