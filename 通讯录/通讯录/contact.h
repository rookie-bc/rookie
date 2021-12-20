#pragma once
// 头文件的引用
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>   //memset
#include <stdlib.h>


#define MAX 1000
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
	SORT
};

//结构体的声明
struct PeoInfo              //人的信息
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
//通讯录类型
struct Contact
{
	struct PeoInfo data[MAX];   //存放1000个人的信息
	int size;                    //记录当前已经有多少个人
};

//函数的声明
void InitContact(struct Contact* ps);						     //初始化通讯录的函数
	
void AddContact(struct Contact* ps);						     //增加好友信息的函数

void DelContact(struct Contact* ps);				  	         //删除好友信息的函数

void SearchContact(const struct Contact* ps);				     //查找好友信息的函数
  
void ModifyContact(struct Contact* ps);                          //修改好友信息的函数

void ShowContact(const struct Contact* ps);						 //显示通讯录信息的函数

void SortContact(struct Contact* ps);                            //将通讯录排序的函数