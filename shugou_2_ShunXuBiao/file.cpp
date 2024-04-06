#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>;
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define Num 10
#define AppendSize 5
typedef int Status;

typedef struct {
	char sno[4];
	char sname[10];
	int sage;
	char sdept[3];
}StuType;
typedef StuType ElemType;

typedef struct {
	int length;
	ElemType* pt;
	int Size;
}List;

Status InitList(List &a) {
	try {
		a.pt = new StuType[Num];
		a.length = 0;
		a.Size = Num;
		return OK;
		throw OVERFLOW;
	}
	catch (int& e) {
		return ERROR;
	}
	
}
Status ListInsert(List &a,const int i,StuType &Stu) {
	if (i < 1 || i > a.length + 1) {
		return ERROR;
	}
	if (a.length + 1 > a.Size) {
		delete [] a.pt;
		a.pt = new StuType[AppendSize + a.Size];
		a.Size += AppendSize;
	}
	for (int j = a.length; j >= i;) {
		a.pt[j] = a.pt[--j];
	}
	a.pt[i - 1] = Stu;
	a.length++;
	return OK;
}
Status ListDelete(List &a, const int pos, StuType Stu) {
	if (pos<1 || pos>a.length) {
		cout << "删除数据的索引错误" << endl;
		return ERROR;
	}
	for (int i = pos - 1; i < a.length - 1;i++) {
		a.pt[i] = a.pt[i+1];
	}
	Stu = a.pt[pos - 1];
	a.length--;
	return OK;
}
int ListLength(const List& L) {
	return L.length;
}
Status GetElem(List &a, const int i, StuType& Stu) {
	if (i > a.length||i<1) {
		cout << "该用户不存在" << endl;
		return ERROR;
	}
	else {
		Stu = a.pt[i - 1];
		return OK;
	}
}
Status PutElem(List &a, const int i, StuType& Stu) {
	if (i > a.length || i < 1) {
		cout << "该用户不存在" << endl;
		return ERROR;
	}
	a.pt[i - 1] = Stu;
	return OK;
}
Status visit(StuType& Stu) {
	cout << "sno:" << Stu.sno << endl;
	cout << "sname:" << Stu.sname << endl;
	cout << "sage:" << Stu.sage << endl;
	cout << "sdept:" << Stu.sdept << endl<< endl;
	return OK;
}
Status ListTraverse(List &a, Status(*FunctionPointer)(StuType& Stu)) {
	for (int i = 0; i < a.length; i++) {
		FunctionPointer(a.pt[i]);
	}
	return OK;
}
Status equal(char a[], char* b) {
	return !strcmp(a, b);
}
int LocateElem(List& a, StuType& Stu, Status(*funPt)(char*, char*)) {
	for (int i = 0; i < a.length; i++) {
		if (funPt(a.pt[i].sno, Stu.sno)) {
			return i + 1;
		}
	}
	cout << "不存在该学号的学生" << endl;
	return 0;
}

void main()
{
	List L;
	ElemType stu, stu_tmp;
	int func, pos;
	if (!InitList(L))
	{
		printf("overflow!\n");
		exit(-1);
	}
	for (int j = 0;; j++)
	{
		printf("Please select the function:\n0--Exit\n1--insert student\n2--delete student\n3--update student name\n4--search student with sno\n5--show all student\n6--count the student\n Please input:");
		scanf_s("%d", &func);
		switch (func)
		{
		case 0:
			exit(1);
			break;
		case 1: //插入学生信息
			printf("sno: ");
			scanf_s("%s", &stu.sno,4);
			printf("sname: ");
			scanf_s("%s", &stu.sname,10);
			printf("sage: ");
			scanf_s("%d", &stu.sage);
			printf("sdept: ");
			scanf_s("%s", &stu.sdept,3);
			ListInsert(L, ListLength(L) + 1, stu);
			break;
		case 2://删除指定学号的学生信息
			printf("input the sno:");
			scanf_s("%s", &stu.sno,4);
			pos = LocateElem(L, stu, equal);
			if (pos > 0)
				ListDelete(L, pos, stu);
			else
				printf("The student is not exist!\n");
			break;
		case 3://更新指定学号的学生姓名
			printf("input the sno of the student to be updated:");
			scanf_s("%s", &stu.sno,4);
			pos = LocateElem(L, stu, equal);
			if (pos > 0)
			{
				printf("input the new name:");
				scanf_s("%s", &stu.sname,10);
				GetElem(L, pos, stu_tmp);
				stu.sage = stu_tmp.sage;
				strcpy_s(stu.sdept, stu_tmp.sdept);
				PutElem(L, pos, stu);
			}
			else
				printf("The student is not exist!\n");
			break;
		case 4://查找指定学号的学生信息
			printf("input the sno:");
			scanf_s("%s", &stu.sno,4);
			pos = LocateElem(L, stu, equal);
			if (pos > 0)
			{
				GetElem(L, pos, stu_tmp);
				printf("%s\t%s\t%d\t%s\n", stu_tmp.sno, stu_tmp.sname, stu_tmp.sage, stu_tmp.sdept);
			}
			else
				printf("The student is not exist!\n");
			break;
		case 5: //输出所有学生信息
			ListTraverse(L, visit);
			break;
		case 6: //输出学生数量
			printf("The student count is %d\n", ListLength(L));
			break;
		}
		cout << endl;
	}
}
