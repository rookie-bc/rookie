#include <stdio.h>
#include <assert.h>
int my_strlen(const char* arr)               //   ����֮��arr��������޷����ı�
{
	assert(arr != NULL);           //��ָ֤�����Ч��     ���Ա���
	int count = 0;
	while (*arr++ != '\0')            //���ж�ԭ��arr�Ƿ����\0   ��++  �ڽ�����
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