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
	int guess = 0;      //接受猜的数字
	ret = rand()%100;
	while (1)
	{
		printf("请猜数字");
		scanf_s("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		if (guess < ret)
		{
			printf("猜小了\n");
		}
		if (guess == ret)
		{
			printf("恭喜你，回答正确！\n");
			break;
		}
	}

}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));                //生成随机数
	do 
	{
		menu();
		printf("请选择:");
		scanf_s("%d", &input);
		switch (input) 
		{
		case 1:
			game();
				break;
		case 0:
			printf("退出游戏\n");
				break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
	return 0;
}