#pragma once
// ͷ�ļ�������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>   //memset
#include <stdlib.h>
#include <errno.h>


//#define MAX 1000          //��̬�汾�µ�


#define DEFAULT_SZ 3
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
	SORT,
	SAVE
};

//�ṹ�������
typedef struct PeoInfo              //�˵���Ϣ
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;
//ͨѶ¼����
typedef struct Contact
{
	struct PeoInfo* data;        //��ź�����Ϣ�Ŀռ�   ��Ҫ��̬����
	int size;                    //��¼��ǰ�Ѿ��ж��ٸ���
	int capacity;                //��¼ͨѶ¼������
}Contact;

//����������
void InitContact(struct Contact* ps);						     //��ʼ��ͨѶ¼�ĺ���
	
void AddContact(struct Contact* ps);						     //���Ӻ�����Ϣ�ĺ���

void DelContact(struct Contact* ps);				  	         //ɾ��������Ϣ�ĺ���

void SearchContact(const struct Contact* ps);				     //���Һ�����Ϣ�ĺ���
  
void ModifyContact(struct Contact* ps);                          //�޸ĺ�����Ϣ�ĺ���

void ShowContact(const struct Contact* ps);						 //��ʾͨѶ¼��Ϣ�ĺ���

void SortContact(struct Contact* ps);                            //��ͨѶ¼����ĺ���

void DestroyContact(Contact* ps);                                //�ͷŶ�̬�ڴ�ĺ���

void SaveContact(Contact* ps);                                   //���浽�ļ��ĺ���

//void LoadContact(Contact* ps);                                   //�����ļ������ݵĺ���