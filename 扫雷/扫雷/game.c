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
	//��ӡ�к�
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
		int x = rand() % row + 1;    //����1-row�������
		int y = rand() % col + 1;    //����1-col�������
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
//x,y��Χ�׵ĸ���
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
	printf("����������: ");
	int x, y;
	int win=0;
	while (win<row*col- EASY_COUNT)
	{
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y <= col && y >= 1)
		{
			//����Ϸ�
			//1.����
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����!\n");
				DisplayBoard(mine, row, col);
				break;
			}
			//������
			else
			{
				//����x��y��Χ�м�����
				int count = get_mine_count(mine,x,y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
			printf("����Ƿ���������Ϸ�����\n");
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ���");
		DisplayBoard(show, row, col);
	}
}