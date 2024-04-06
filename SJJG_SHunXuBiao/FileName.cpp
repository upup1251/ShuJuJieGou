#include <iostream>
using namespace std;
typedef int Statues;
typedef int ElemType;
#define addtion 5;
#define ok 1;
#define error 0;
struct SqlList {
	ElemType* pt=0;//区分该SqlList是否被初始化
	int length;
	int listsize;
};

Statues InitList(SqlList& L,const int n) {
	try { L.pt = new ElemType[n]; }
	catch (bad_alloc& e) {//标准C++中不会返回空指针，而是抛出异常
		cerr << "分配内存失败" << e.what() << endl;
	}
	L.listsize = n;
	L.length = 0;
	return ok;
}
//上述顺序表声明没有定义具体的数据元素，只能用Elemtypy代替
//函数模板，可以不用提前声明顺序表中的数据类型,调用时需InitList_sql<Anytype>(L,n)
template <class Anytypename>
Statues InitList_sql(SqlList& L,const int n) {
	try { L.pt = new Anytypename[n]; }
	catch (const bad_alloc& e) {
		cerr << "分配内存失败" << e.what() << endl;
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
		cout << "该顺序表未被初始化Init" << endl;
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
		cout << "该顺序表未被初始化Init" << endl;
		return error;
	}
	return ok;
}
Statues EmptyList(SqlList& L) {
	if (L.pt != 0) {
		if (L.length == 0) {
			cout << "该顺序表为空" << endl;
			return ok;
		}
		else {
			cout << "该顺序表不为空" << endl;
		}
	}
	else {
		cout << "该顺序表未被初始化Init" << endl;
		return error;
	}
}
const int ListLength(SqlList& L) {
	if (L.pt == 0) {
		cout << "该顺序表未被初始化Init" << endl;
		return error;
	}
	else return L.length;
}
const ElemType& getElem(SqlList& L, int i) {
	if (i <= 0 || i > L.length) { cout << "索引错误" << endl; return 0; }
	return *(L.pt + i-1 );
}
const ElemType& PriorElem(SqlList& L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if ((i==0)&&(*(L.pt) == e)) {
			cout << "无前驱，对于元素："; 
			return e;
		}
		if (*(L.pt + i) == e) {
			if(i>0)return *(L.pt + i - 1);

		}
	}
	cout << "不存在元素：";
	return e;
}
const ElemType& NextElem(SqlList& L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if ((i == L.length-1) && (*(L.pt+i) == e)) {
			cout << "无后继，对于元素：";
			return e;
		}
		if (*(L.pt + i) == e) {
			return *(L.pt + i + 1);

		}
	}
	cout << "不存在元素：";
	return e;
}
Statues InsertElem(SqlList& L,const int i,const ElemType e) {
	if (i<1 || i>L.length + 1) {
		cout << "索引错误" << endl; return error;
	}
	if (L.length == L.listsize) {
		int new_size = L.listsize + addtion;
		try { 
			ElemType* pr = new ElemType[new_size]; 
			L.pt = pr;
			L.listsize = new_size;
		}
		catch (bad_alloc) { cout << "内存不足并且分配失败" << endl; return error; }
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
		cout << "索引错误" << endl; return error;
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