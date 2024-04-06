#include <iostream>
using namespace std;
typedef int Statues;
typedef int ElemType;
#define addtion 5;
#define ok 1;
#define error 0;
struct SqlList {
	ElemType* pt=0;//���ָ�SqlList�Ƿ񱻳�ʼ��
	int length;
	int listsize;
};

Statues InitList(SqlList& L,const int n) {
	try { L.pt = new ElemType[n]; }
	catch (bad_alloc& e) {//��׼C++�в��᷵�ؿ�ָ�룬�����׳��쳣
		cerr << "�����ڴ�ʧ��" << e.what() << endl;
	}
	L.listsize = n;
	L.length = 0;
	return ok;
}
//����˳�������û�ж�����������Ԫ�أ�ֻ����Elemtypy����
//����ģ�壬���Բ�����ǰ����˳����е���������,����ʱ��InitList_sql<Anytype>(L,n)
template <class Anytypename>
Statues InitList_sql(SqlList& L,const int n) {
	try { L.pt = new Anytypename[n]; }
	catch (const bad_alloc& e) {
		cerr << "�����ڴ�ʧ��" << e.what() << endl;
	}
	L.length = 0;
	L.listsize = n;
}
Statues DestroyList(SqlList& L) {
	if (L.pt != 0) {
		delete[] L.pt;
		L.pt = 0;
	}
	else {
		cout << "��˳���δ����ʼ��Init" << endl;
		return error;
	}
	L.length = L.listsize = 0;
	return ok;
}
Statues ClearList(SqlList& L) {
	if (L.pt != 0) {
		L.length = 0;
	}
	else {
		cout << "��˳���δ����ʼ��Init" << endl;
		return error;
	}
	return ok;
}
Statues EmptyList(SqlList& L) {
	if (L.pt != 0) {
		if (L.length == 0) {
			cout << "��˳���Ϊ��" << endl;
			return ok;
		}
		else {
			cout << "��˳���Ϊ��" << endl;
		}
	}
	else {
		cout << "��˳���δ����ʼ��Init" << endl;
		return error;
	}
}
const int ListLength(SqlList& L) {
	if (L.pt == 0) {
		cout << "��˳���δ����ʼ��Init" << endl;
		return error;
	}
	else return L.length;
}
const ElemType& getElem(SqlList& L, int i) {
	if (i <= 0 || i > L.length) { cout << "��������" << endl; return 0; }
	return *(L.pt + i-1 );
}
const ElemType& PriorElem(SqlList& L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if ((i==0)&&(*(L.pt) == e)) {
			cout << "��ǰ��������Ԫ�أ�"; 
			return e;
		}
		if (*(L.pt + i) == e) {
			if(i>0)return *(L.pt + i - 1);

		}
	}
	cout << "������Ԫ�أ�";
	return e;
}
const ElemType& NextElem(SqlList& L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if ((i == L.length-1) && (*(L.pt+i) == e)) {
			cout << "�޺�̣�����Ԫ�أ�";
			return e;
		}
		if (*(L.pt + i) == e) {
			return *(L.pt + i + 1);

		}
	}
	cout << "������Ԫ�أ�";
	return e;
}
Statues InsertElem(SqlList& L,const int i,const ElemType e) {
	if (i<1 || i>L.length + 1) {
		cout << "��������" << endl; return error;
	}
	if (L.length == L.listsize) {
		int new_size = L.listsize + addtion;
		try { 
			ElemType* pr = new ElemType[new_size]; 
			L.pt = pr;
			L.listsize = new_size;
		}
		catch (bad_alloc) { cout << "�ڴ治�㲢�ҷ���ʧ��" << endl; return error; }
	}
	ElemType* pt_cha = L.pt + i - 1;
	ElemType* pt_hou = L.pt + L.length;
	while (pt_hou > pt_cha) {
		*pt_hou = *(pt_hou - 1);
		pt_hou--;
	}
	*pt_cha = e;
	L.length += 1;
	return ok;
}
Statues DeleteElem(SqlList& L, const int i) {
	if (i<1 || i>L.length) {
		cout << "��������" << endl; return error;
	}
	ElemType* pt_shan = L.pt + i - 1;
	while (pt_shan < L.pt + L.length - 1) {
		*pt_shan = *(pt_shan + 1);
		pt_shan++;
	}
	L.length--;
	return ok;
}

int main() {

}