#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void menu()
{
	printf("**************************\n");
	printf("****1. play   0.exit *****\n");
	printf("**************************\n");
	printf("\n");
	printf("\n");
}
void game()
{
	int ret = 0;
	int guess = 0;      //���ܲµ�����
	ret = rand()%100;
	while (1)
	{
		printf("�������");
		scanf_s("%d", &guess);
		if (guess > ret)
		{
			printf("�´���\n");
		}
		if (guess < ret)
		{
			printf("��С��\n");
		}
		if (guess == ret)
		{
			printf("��ϲ�㣬�ش���ȷ��\n");
			break;
		}
	}

}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));                //���������
	do 
	{
		menu();
		printf("��ѡ��:");
		scanf_s("%d", &input);
		switch (input) 
		{
		case 1:
			game();
				break;
		case 0:
			printf("�˳���Ϸ\n");
				break;
		default:
			printf("�������\n");
			break;
		}
	} while (input);
	return 0;
}