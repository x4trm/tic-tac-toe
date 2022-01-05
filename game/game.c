#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define BOARD_SIZE 3
#define EMPTY '.'

void Board(char board[BOARD_SIZE][BOARD_SIZE]);
void Human(char board[BOARD_SIZE][BOARD_SIZE]);
void Computer(char board[BOARD_SIZE][BOARD_SIZE]);
void Step(char board[BOARD_SIZE][BOARD_SIZE],int user);
void Show(char board[BOARD_SIZE][BOARD_SIZE]);
int Check(char board[BOARD_SIZE][BOARD_SIZE],int row,int col, int dr,int dc);
int End(char board[BOARD_SIZE][BOARD_SIZE]);
int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    int user=0;
    /*
        0-human
        1-computer
    */
    Board(board);
    Show(board);
    do{
        Step(board,user);
        Show(board);
        if(user==0)
        {
            user=1;
        }
        else
        {
            user=0;
        }
    }while(End(board)!=1);
    return 0;
}
void Board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i,j;
    for(i=0;i<BOARD_SIZE;i++)
    {
        for(j=0;j<BOARD_SIZE;j++)
        {
            board[i][j]=EMPTY;
        }
    }
}
void Human(char board[BOARD_SIZE][BOARD_SIZE])
{
    int row,col;
    do
    {
        printf("Your turn\n");
        printf("ROW: ");
        scanf("%d",&row);
        printf("COL: ");
        scanf("%d",&col);
    }while(row<0 || row>=BOARD_SIZE || col<0 || col>=BOARD_SIZE || board[row][col]!=EMPTY);
    board[row][col]='o';
}
void Computer(char board[BOARD_SIZE][BOARD_SIZE])
{
    int row,col;
    srand(time(NULL));
        do
    {
        row=rand()%BOARD_SIZE;
        col=rand()%BOARD_SIZE;
    }while(board[row][col]!=EMPTY);
    printf("Computer move: ROW: %d, COL: %d\n",row,col);
    board[row][col]='x';
}
void Step(char board[BOARD_SIZE][BOARD_SIZE],int user)
{
    if(user==0)
    {
        Human(board);
    }
    else{
        Computer(board);
    }
}
void Show(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i,j;
    for(i=0;i<BOARD_SIZE;i++)
    {
        for(j=0;j<BOARD_SIZE;j++)
        {
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
}
int Check(char board[BOARD_SIZE][BOARD_SIZE],int row,int col,int dr,int dc)
{
    char sign=board[row][col];
    if(sign==EMPTY)
    {
        return 0; //return false
    }
    row+=dr;
    col+=dc;
    while(row >=0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE)
    {
        if(board[row][col]!=sign)
        {
            return 0;
        }
        row+=dr;
        col+=dc;
    }
    return 1;//return true
}

int End(char board[BOARD_SIZE][BOARD_SIZE])
{
    /*
    0-continue
    1-end
    */
    int i,j;
    for(i=0;i<BOARD_SIZE;i++)
    {
        if(Check(board,i,0,0,1)==1)
        {
            return 1;
        }
    }
    for(i=0;i<BOARD_SIZE;i++)
    {
        if(Check(board,0,i,0,1)==1)
        {
            return 1;
        }
    }
    if(Check(board,0,0,1,1)==1)
    {
            return 1;
    }
    if(Check(board,0,(BOARD_SIZE-1),1,(-1))==1)
    {
        return 1;
    }
    for(i=0;i<BOARD_SIZE;i++)
    {
        for(j=0;j<BOARD_SIZE;j++)
        {
            if(board[i][j]==EMPTY)
            {
                return 0;
            }
        }
    }
}