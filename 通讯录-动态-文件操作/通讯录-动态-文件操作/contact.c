//函数的定义
#include "contact.h"


void InitContact(struct Contact* ps)
{
	//memset(ps->data, 0, sizeof(ps->data));
	//ps->size = 0;//设置通讯录最初只有0个元素      //动态版本
	ps->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (ps->data == NULL)
	{
		return 0;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;

	//LoadContact(ps);
}


void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("增容成功\n");
		}
		else
		{
			printf("增容失败\n");
		}
	}
}

//   静态
//void AddContact(struct Contact* ps)
//{
//	if (ps->size == MAX)
//	{
//		printf("通讯录已满，无法增加！\n");
//	}
//	else
//	{
//		printf("请输入名字：");
//		scanf("%s", ps->data[ps->size].name);   //找到数组data中的某一个元素的名字位置
//		printf("请输入年龄：");
//		scanf("%d", &ps->data[ps->size].age);
//		printf("请输入性别：");
//		scanf("%s", ps->data[ps->size].sex);
//		printf("请输入电话：");
//		scanf("%s", ps->data[ps->size].tele);
//		printf("请输入地址：");
//		scanf("%s", ps->data[ps->size].addr);
//
//		ps->size++;            //放进去一个好友  就加加
//		printf("添加成功！\n");
//	}
//}

//动态
void AddContact(struct Contact* ps)
{
	CheckCapacity(ps);         //检验容量是否需要扩容


	printf("请输入名字：");
	scanf("%s", ps->data[ps->size].name);   //找到数组data中的某一个元素的名字位置
	printf("请输入年龄：");
	scanf("%d", &ps->data[ps->size].age);
	printf("请输入性别：");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话：");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入地址：");
	scanf("%s", ps->data[ps->size].addr);

	ps->size++;            //放进去一个好友  就加加
	printf("添加成功！\n");

}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("您未添加好友!\n");
	}
	else
	{
		printf("%-12s\t%-4s\t%-4s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			printf("%-12s\t%-4d\t%-4s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}


static int FindByName(const struct Contact* ps, char name[MAX_NAME])         //被static修饰只能在改文件下用
{
	int i;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))        //查找某一个名字在通讯录中的位置
		{
			return i;                                   //找到了返回下标
		}
	}
	return -1;               //找不到返回-1
}
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入删除人姓名:");
	scanf("%s", name);
	int pos = FindByName(ps, name);  //找到了名字所在元素的下标    找不到返回-1
	if (pos==-1)
	{
		printf("未找到要删除人的信息！\n");
	}
	else
	{
		int j;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];                     //2.删除   将后一个元素将前一个元素覆盖
		}
		ps->size--;
		printf("删除成功！\n");
	}
}



void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找人的姓名:");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("未找到要查找人的信息！\n");
	}
	else
	{
		printf("%-12s\t%-4s\t%-4s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-12s\t%-4d\t%-4s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}


void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改人的姓名:");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("未找到要修改人的信息！\n");
	}
	else
	{
		printf("请输入名字：");
		scanf("%s", ps->data[pos].name);   
		printf("请输入年龄：");
		scanf("%d", &ps->data[pos].age);
		printf("请输入性别：");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话：");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址：");
		scanf("%s", ps->data[pos].addr);

		printf("修改成功\n");
	}
}



//        排序 
int cmp_peo_by_name(const void* e1, const void* e2)
{
	return strcmp((*(PeoInfo*)e1).name, (*(PeoInfo*)e2).name);
}

void SortContact(struct Contact* ps)
{
	qsort(ps->data->name,ps->size, sizeof(PeoInfo), cmp_peo_by_name);
}



void DestroyContact(Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}

void SaveContact(Contact* ps)
{
	FILE* pf = fopen("Contact.txt", "w");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	int i;
	for (i = 0; i < ps->size; i++)
	{
		fprintf(pf,"%-12s\t%-4d\t%-4s\t%-12s\t%-20s\n",
			ps->data[i].name,
			ps->data[i].age,
			ps->data[i].sex,
			ps->data[i].tele,
			ps->data[i].addr);
	}
	fclose(pf);
	pf = NULL;
	printf("保存成功！");
}
//void LoadContact(Contact* ps)
//{
//	FILE* pf = fopen("Contact.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return;
//	}
//
//}