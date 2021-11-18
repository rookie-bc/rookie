#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0, j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col) 
{
	int i, j;
	//打印列号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;    //生成1-row的随机数
		int y = rand() % col + 1;    //生成1-col的随机数
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
//x,y周围雷的个数
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	    return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	printf("请输入坐标: ");
	int x, y;
	int win=0;
	while (win<row*col- EASY_COUNT)
	{
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y <= col && y >= 1)
		{
			//坐标合法
			//1.踩雷
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了!\n");
				DisplayBoard(mine, row, col);
				break;
			}
			//不踩雷
			else
			{
				//计算x，y周围有几个雷
				int count = get_mine_count(mine,x,y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
			printf("坐标非法，请输入合法坐标\n");
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功！");
		DisplayBoard(show, row, col);
	}
}