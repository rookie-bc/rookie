#pragma once
// ͷ�ļ�������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>   //memset
#include <stdlib.h>


#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

 
enum Option                 //ö��   ��˵���ѡ����ö�
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

//�ṹ�������
struct PeoInfo              //�˵���Ϣ
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
//ͨѶ¼����
struct Contact
{
	struct PeoInfo data[MAX];   //���1000���˵���Ϣ
	int size;                    //��¼��ǰ�Ѿ��ж��ٸ���
};

//����������
void InitContact(struct Contact* ps);						     //��ʼ��ͨѶ¼�ĺ���
	
void AddContact(struct Contact* ps);						     //���Ӻ�����Ϣ�ĺ���

void DelContact(struct Contact* ps);				  	         //ɾ��������Ϣ�ĺ���

void SearchContact(const struct Contact* ps);				     //���Һ�����Ϣ�ĺ���
  
void ModifyContact(struct Contact* ps);                          //�޸ĺ�����Ϣ�ĺ���

void ShowContact(const struct Contact* ps);						 //��ʾͨѶ¼��Ϣ�ĺ���

void SortContact(struct Contact* ps);                            //��ͨѶ¼����ĺ���