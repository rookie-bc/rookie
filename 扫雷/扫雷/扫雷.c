#include "game.h"
void game()
{
	//雷的存储信息
	//1.布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };
	//2.排查的雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//展示雷的信息
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//扫雷
	FindMine(mine, show, ROW, COL);
}
void menu()
{
	printf("************************\n");
	printf("***** 1.play 0.exit ****\n");
	printf("************************\n");
}
void test()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("                          \n");
			printf("        扫雷游戏开始      \n");
			printf("                          \n");
			game();
			break;
		case 0:
			printf("                          \n");
			printf("         退出游戏！       \n");
			printf("                          \n");
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