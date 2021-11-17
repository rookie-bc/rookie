#include <stdio.h>
#include <assert.h>
int my_strlen(const char* arr)               //   修饰之后arr里的数据无法被改变
{
	assert(arr != NULL);           //保证指针的有效性     断言保护
	int count = 0;
	while (*arr++ != '\0')            //先判断原先arr是否等于\0   在++  在解引用
	{
		//arr++;
		count++;
	}
	return count;
}
int main()
{
	char arr[] = "abcdef";
	int len = my_strlen(arr);
	printf("%d", len);
	return 0;
}