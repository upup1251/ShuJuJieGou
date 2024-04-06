#include <iostream>
using namespace std;
typedef int Statues;
typedef int NodeType;
#define ok 0;
#define error 1;

class Node {
public:
	NodeType data;
	Node* next;
	Node() { data = 0; next = 0; }
	Node(const NodeType data) : data(data) { next = 0; }
};
class Node_ShuangXiang :public Node{
public:
	Node_ShuangXiang* next, * prior;
};

class LianShiBiao {
public:
	virtual Statues DestoryList() = 0;
	virtual Statues ClearList() = 0;
	virtual Statues InsertNode(Node* Node,const int i) = 0;
	virtual Statues DeleteNode(int i) = 0;

	virtual Statues SetCurrentNode(const int i) = 0;
	virtual Node& GetCurrentNode() const= 0;
	virtual int GetLength() const= 0;
	virtual Node& GetHeadNode() const= 0;
	virtual Node& GetLastNode() const= 0;
	virtual Node& GetNode(int i)=0;
	virtual Statues Isempty() = 0;
	virtual Node* MakeNode(const NodeType data) = 0;
	virtual Statues DestoryNode(Node*) = 0;
};

class DangXiangBiao :public LianShiBiao {
public:
	DangXiangBiao() {
		head = MakeNode(0);
		tail = current = head;
		length = 0;

	}
	Statues DestoryList() override;
	Statues ClearList() override;
	Statues InsertNode(Node* Node, const int i) override;
	Statues DeleteNode(int i) override;
	Statues SetCurrentNode(const int i)override;
	Node& GetCurrentNode() const ;
	int GetLength() const override;
	Node& GetHeadNode() const override;
	Node& GetLastNode() const override;
	Node& GetNode(int i) override;
	Statues Isempty() override;
private:
	Node* head,*tail,*current;
	int length;
	Node* MakeNode(const NodeType data)override;
	Statues DestoryNode(Node*) override;
};
Node* DangXiangBiao::MakeNode(const NodeType data) {
	try {
		Node* pt = new Node(data);
		return pt;
	}
	catch (bad_alloc& e) {
		cout << "为节点分配内存失败" << endl;
		return 0;
	}
}
Statues DangXiangBiao::DestoryNode(Node* pt) {
	pt->next = 0;
	delete pt;
	return ok;
}
Statues DangXiangBiao::ClearList() {
	Node* p = head->next;
	while (p) {
		Node* q = p;
		p = p->next;
		delete q;
		q = 0;
	}
	head->next = 0;
	tail = head;
	length = 0;
	return ok;
}
Statues DangXiangBiao::DestoryList() {
	ClearList();
	delete head;
	head = current = tail = 0;
	length = 0;
	return ok;
}
Statues DangXiangBiao::InsertNode(Node* ChaRuZhi,const int i) {
	if (i<1 || i>length + 1) {
		cout << "索引错误" << endl;
		return error;
	}
	else if (i == 1) {
		Node* pt = head;
		head = ChaRuZhi;
		if (length == 0) {
			tail = ChaRuZhi;
		}
		ChaRuZhi->next = pt;
		length++;
		return ok;
	}
	else if (i == length + 1) {
		tail->next = ChaRuZhi;
		tail = ChaRuZhi;
		length++;
		return ok;
	}
	else {
		Node* pt = head;
		for (int j = 2; j < i; j++) {
			pt = pt->next;
		}
		ChaRuZhi->next = pt->next;
		pt->next = ChaRuZhi;
		return ok;
	}
}
Statues DangXiangBiao::DeleteNode(int i) {
	if (i<1 || i>length) {
		cout << "索引错误" << endl;
		throw out_of_range("索引错误");
	}
	else if (i == 1) {
		Node* pt = head->next;
		head->next = 0;
		delete head;
		head = pt;
		length--;
	}
	else if (i == length) {
		Node priorNode = GetNode(length - 1);
		DestoryNode(tail);
		priorNode.next = 0;
		length--;
		tail = &priorNode;
		return ok;
	}
	else {
		Node priorNode = GetNode(i - 1);
		Node* pt = priorNode.next->next;
		DestoryNode(priorNode.next);
		priorNode.next = pt;
		length--;
		return ok;
	}
}
Node& DangXiangBiao::GetNode(int i) {
	try {
		if (i<1 || i>length) {
			throw out_of_range("索引错误");
		}
		Node* pt = head;
		for (int j = 1; j < i; j++)pt = pt->next;
		return *pt;
	}
	catch (out_of_range& e) {
		cout << "捕获到异常" << e.what() << endl << "请重新输入目标元素的位置:" << endl;
		cin >> i;
		return GetNode(i);
	}
}
Statues DangXiangBiao::SetCurrentNode(const int i) {
	current = &GetNode(i);
	return ok;
}
Node& DangXiangBiao::GetCurrentNode()const {
	return *current;
}
int DangXiangBiao::GetLength() const { return length; }
Node& DangXiangBiao::GetHeadNode() const { return *head; }
Node& DangXiangBiao::GetLastNode() const { return *tail; }
Statues DangXiangBiao::Isempty() {
	if (length == 0)return 1;
	else return 0;
}