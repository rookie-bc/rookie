//函数的实现
#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}
//void DisplayBoard(char board[ROW][COL], int row, int col)                                               //非常搓   没有普适性
//{
//	int i;
//	for (i = 0; i < row; i++)
//	{
//		//打印一行的数据
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//       //打印分割行
//		if(i<row-1)
//		printf("___|___|___\n");
//	}
//	printf("   |   |   \n");
//}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i,j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            //打印一行数据
            printf(" %c ", board[i][j]);
            if (j < col - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        //打印分割线
        if (i < row - 1)
        {
            for (j = 0; j < col; j++)
            {
                printf("---");
                if(j<col-1)
                printf("|");
            }
            printf("\n");
        }
    }
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
    int x, y;
    printf("玩家走\n");
    while (1)
    {
        printf("请输入坐标: ");
        scanf_s("%d%d", &x, &y);
        //判断坐标合法性
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
                printf("该坐标被占用\n");
        }
        else
            printf("坐标非法，请重新输入！\n");
    }
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
    int x, y;
    printf("电脑走\n");
    while (1)
    {
        x = rand() % 3;
        y = rand() % 3;
        if (board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}
//返回1表示棋盘满了  
//返回0表示棋盘没满
int IsFull(char board[ROW][COL], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 1; j < col; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}
char IsWin(char board[ROW][COL], int row, int col)                          //'*' 玩家赢    '#' 电脑赢         'Q' 平局        'C'继续
{
    int i;
    //横三行
    for (i = 0; i < row; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
        {
            return board[i][1];
        }
    }
    //竖三列
    for (i = 0; i < col; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
        {
            return board[1][i];
        }
    }
    //斜两行
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
    {
        return board[1][1];
    }
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
    {
        return board[1][1];
    }
    //平局
    if (1 == IsFull(board,ROW,COL))
    {
        return 'Q';
    }
    return 'C';
}