#include "game.h"
void game()
{
	//�׵Ĵ洢��Ϣ
	//1.���úõ��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };
	//2.�Ų���׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//չʾ�׵���Ϣ
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//ɨ��
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
		printf("��ѡ��:");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("                          \n");
			printf("        ɨ����Ϸ��ʼ      \n");
			printf("                          \n");
			game();
			break;
		case 0:
			printf("                          \n");
			printf("         �˳���Ϸ��       \n");
			printf("                          \n");
			break;
		default:
			printf("ѡ���������������\n");
			break;
		}

	} while (input);
}

int main()
{
	test();
	return 0;
}