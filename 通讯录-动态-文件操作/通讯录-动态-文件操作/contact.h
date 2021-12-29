#pragma once
// 头文件的引用
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>   //memset
#include <stdlib.h>
#include <errno.h>


//#define MAX 1000          //静态版本下的


#define DEFAULT_SZ 3
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

 
enum Option                 //枚举   令菜单的选项更好读
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

//结构体的声明
typedef struct PeoInfo              //人的信息
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;
//通讯录类型
typedef struct Contact
{
	struct PeoInfo* data;        //存放好友信息的空间   需要动态开辟
	int size;                    //记录当前已经有多少个人
	int capacity;                //记录通讯录的容量
}Contact;

//函数的声明
void InitContact(struct Contact* ps);						     //初始化通讯录的函数
	
void AddContact(struct Contact* ps);						     //增加好友信息的函数

void DelContact(struct Contact* ps);				  	         //删除好友信息的函数

void SearchContact(const struct Contact* ps);				     //查找好友信息的函数
  
void ModifyContact(struct Contact* ps);                          //修改好友信息的函数

void ShowContact(const struct Contact* ps);						 //显示通讯录信息的函数

void SortContact(struct Contact* ps);                            //将通讯录排序的函数

void DestroyContact(Contact* ps);                                //释放动态内存的函数

void SaveContact(Contact* ps);                                   //保存到文件的函数

//void LoadContact(Contact* ps);                                   //加载文件中数据的函数