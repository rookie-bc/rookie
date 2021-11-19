#include "game.h"
//整个游戏的算法实现
void game()
{
	char ret;
	//数组存放走出的棋盘信息
	char board[ROW][COL] = { 0 };
	//初始化三子棋盘     每个数组的元素是空格
	InitBoard(board, ROW, COL);
	//打印棋盘     
	DisplayBoard(board, ROW, COL);
	//开始下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("              \n");
		printf("   玩家获胜！ \n");
		printf("              \n");
	}
	else if (ret == '#')
	{
		printf("              \n");
		printf("   电脑获胜！ \n");
		printf("              \n");
	}
	else if (ret == 'Q') 
	{
		printf("              \n");
		printf("     平局！   \n");
		printf("              \n");
	}
}
void menu()
{
	printf("************************\n");
	printf("***** 1.play 0.exit ****\n");
	printf("************************\n");
}
void test()
{
	int input=0;
	srand ((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("请选择:");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("                     \n");
			printf("   三子棋:游戏开始   \n");
			printf("                     \n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新输入\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}