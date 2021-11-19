#include "game.h"
//������Ϸ���㷨ʵ��
void game()
{
	char ret;
	//�������߳���������Ϣ
	char board[ROW][COL] = { 0 };
	//��ʼ����������     ÿ�������Ԫ���ǿո�
	InitBoard(board, ROW, COL);
	//��ӡ����     
	DisplayBoard(board, ROW, COL);
	//��ʼ����
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("              \n");
		printf("   ��һ�ʤ�� \n");
		printf("              \n");
	}
	else if (ret == '#')
	{
		printf("              \n");
		printf("   ���Ի�ʤ�� \n");
		printf("              \n");
	}
	else if (ret == 'Q') 
	{
		printf("              \n");
		printf("     ƽ�֣�   \n");
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
		printf("��ѡ��:");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("                     \n");
			printf("   ������:��Ϸ��ʼ   \n");
			printf("                     \n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
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