#include <stdio.h>  
#include <stdlib.h>  
#define LIST_INIT_SIZE 100 
#define LISTINCREMENT 10  
#define OK 1  
#define ERROR 0   
#define OVERFLOW -2  
typedef int status;
typedef int ElemType;
typedef struct {
	ElemType *elem;       //存储空间的基地址  
	int length;      //当前长度  
	int listsize;    //当前分配的存储容量  
}SqList;
status InitList(SqList &l)
{
	l.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!l.elem)
	{
		exit(OVERFLOW);
	}
	l.length = 0;//空表长度为零  
	l.listsize = LIST_INIT_SIZE;//初始化储存容量  
	return OK;
}//顺序表的建立

status ListInsert(SqList &l, int i, ElemType e)
{
	if (i<1 || i>l.length + 1)
	{
		return ERROR;
	}
	if (l.length >= l.listsize)
	{
		ElemType *newbase;
		newbase = (ElemType *)realloc(l.elem, (l.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)
		{
			return ERROR;
		}
		l.elem = newbase;
		l.listsize += LISTINCREMENT;
	}
	ElemType *p, *q;
	q = &(l.elem[i - 1]);
	for (p = &(l.elem[l.length - 1]); p >= q; --p)
	{
		*(p + 1) = *p;
	}
	*q = e;
	++l.length;
	return OK;
}//顺序表的插入
status Reverse_Sq(SqList &l) 
{
	int i, n, temp;
	n = l.length;
	for (i = 0; i<n / 2; i++)
	{
		temp = l.elem[n - 1 - i];
		l.elem[n - 1 - i] = l.elem[i];
		l.elem[i] = temp;
	}
	return 0;
}//顺序表的逆置
int main()
{
	SqList List;
	int e;
	int i, j;
	InitList(List);
	for (i = 1; i <= 4; i++)
		ListInsert(List, 1, i);
	printf("在表中插入1-4，打印表：\n");
	for (i = 1; i <= List.length; i++)
		printf("%d  ", List.elem[i - 1]);
	printf("\n");
	printf("将顺序表逆置\n");
	Reverse_Sq(List);
	printf("此时表为:\n");
	for (i = 1; i <= List.length; i++)
		printf("%d  ", List.elem[i - 1]);
	printf("\n");
	system("pause");
	return 0;
}

