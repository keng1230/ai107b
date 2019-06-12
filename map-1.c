#include<stdio.h>
#include<stdlib.h>
#define SIZE 7 //�w�q�a�Ϥj�p
typedef struct{         //�ŧi .structure
    int x;              //x���a�y��
    int y;              //y�����
}Point;

Point pt(int,int);      //�Q�ΰ}�C��index�s�y�@��point
int visit(int[][SIZE],Point,Point);     //�^�Ǥ@�Ӿ��
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
    if(!visit(maze,pt(1,1),pt(5,5))){       //��X��0��ܨS���X�f
        printf("�S���X�f\n");
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
        maze[start.x][start.y] = 1;     //���L��1
        if(!maze[end.x][end.y]&&        //���I�S�Q�X�ݹL�A�i��U�����j
        !(visit(maze,pt(start.x,start.y + 1),end)||
        visit(maze,pt(start.x + 1,start.y),end)||
        visit(maze,pt(start.x,start.y - 1),end)||
        visit(maze,pt(start.x - 1,start.y),end)))
        {
            maze[start.x][start.y] = 0;     //�Y�S���X�f,�N1�٭쬰0
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
