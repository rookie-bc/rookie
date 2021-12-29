//�����Ķ���
#include "contact.h"


void InitContact(struct Contact* ps)
{
	//memset(ps->data, 0, sizeof(ps->data));
	//ps->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��      //��̬�汾
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
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
		}
	}
}

//   ��̬
//void AddContact(struct Contact* ps)
//{
//	if (ps->size == MAX)
//	{
//		printf("ͨѶ¼�������޷����ӣ�\n");
//	}
//	else
//	{
//		printf("���������֣�");
//		scanf("%s", ps->data[ps->size].name);   //�ҵ�����data�е�ĳһ��Ԫ�ص�����λ��
//		printf("���������䣺");
//		scanf("%d", &ps->data[ps->size].age);
//		printf("�������Ա�");
//		scanf("%s", ps->data[ps->size].sex);
//		printf("������绰��");
//		scanf("%s", ps->data[ps->size].tele);
//		printf("�������ַ��");
//		scanf("%s", ps->data[ps->size].addr);
//
//		ps->size++;            //�Ž�ȥһ������  �ͼӼ�
//		printf("��ӳɹ���\n");
//	}
//}

//��̬
void AddContact(struct Contact* ps)
{
	CheckCapacity(ps);         //���������Ƿ���Ҫ����


	printf("���������֣�");
	scanf("%s", ps->data[ps->size].name);   //�ҵ�����data�е�ĳһ��Ԫ�ص�����λ��
	printf("���������䣺");
	scanf("%d", &ps->data[ps->size].age);
	printf("�������Ա�");
	scanf("%s", ps->data[ps->size].sex);
	printf("������绰��");
	scanf("%s", ps->data[ps->size].tele);
	printf("�������ַ��");
	scanf("%s", ps->data[ps->size].addr);

	ps->size++;            //�Ž�ȥһ������  �ͼӼ�
	printf("��ӳɹ���\n");

}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("��δ��Ӻ���!\n");
	}
	else
	{
		printf("%-12s\t%-4s\t%-4s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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


static int FindByName(const struct Contact* ps, char name[MAX_NAME])         //��static����ֻ���ڸ��ļ�����
{
	int i;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))        //����ĳһ��������ͨѶ¼�е�λ��
		{
			return i;                                   //�ҵ��˷����±�
		}
	}
	return -1;               //�Ҳ�������-1
}
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������ɾ��������:");
	scanf("%s", name);
	int pos = FindByName(ps, name);  //�ҵ�����������Ԫ�ص��±�    �Ҳ�������-1
	if (pos==-1)
	{
		printf("δ�ҵ�Ҫɾ���˵���Ϣ��\n");
	}
	else
	{
		int j;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];                     //2.ɾ��   ����һ��Ԫ�ؽ�ǰһ��Ԫ�ظ���
		}
		ps->size--;
		printf("ɾ���ɹ���\n");
	}
}



void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�����˵�����:");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("δ�ҵ�Ҫ�����˵���Ϣ��\n");
	}
	else
	{
		printf("%-12s\t%-4s\t%-4s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("������Ҫ�޸��˵�����:");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("δ�ҵ�Ҫ�޸��˵���Ϣ��\n");
	}
	else
	{
		printf("���������֣�");
		scanf("%s", ps->data[pos].name);   
		printf("���������䣺");
		scanf("%d", &ps->data[pos].age);
		printf("�������Ա�");
		scanf("%s", ps->data[pos].sex);
		printf("������绰��");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ��");
		scanf("%s", ps->data[pos].addr);

		printf("�޸ĳɹ�\n");
	}
}



//        ���� 
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
	printf("����ɹ���");
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