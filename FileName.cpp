#include<iostream>
using namespace std;

typedef int ElemType;//自定义链表数据元素为整数

struct LNode
{
	ElemType data;
	LNode* next;
};
/*typedef struct LNode
{
	ElemType data;
	LNode* next;
}*Pointer;*/
//初始化链表，返回值：失败返回nullptr，成功返回头结点地址
LNode* InitList()
{
	LNode* head = new LNode;//分配头结点
	if (head == nullptr)
	{
		return nullptr;//内存不足，返回失败
	}
	head->next = nullptr;
	return head;
}
//销毁链表
void DestroyList(LNode* head)
{
	LNode* tmp;

	while (head != nullptr)
	{
		tmp = head->next;//trmp保存下一结点的地址
		delete head;//释放当前结点
		head = tmp;//指针移动到下一结点
	}
}
//头插法，返回值：false失败，true成功
bool PushFront(LNode* head, const ElemType& ee)
{
	if (head == nullptr)
	{
		cout << "链表不存在" << endl;
	}
	LNode* tmp = new LNode;//分配新结点
	if (tmp == nullptr)
	{
		return false;
	}
	tmp->data = ee;//输入值存入新结点
	//处理next指针
	tmp->next = head->next;
	head->next = tmp;

	return true;
}
//尾插法（在尾部插入元素）
bool PushBack(LNode* head, const ElemType& ee)
{
	if (head == nullptr)
	{
		cout << "链表不存在" << endl;
	}
	LNode* p = head;//从头结点开始

	//找到最后一个结点，p指向尾结点
	while (p->next != nullptr)
	{
		p = p->next;
	}
	LNode* tmp = new LNode;//分配新结点
	if (tmp == nullptr)
	{
		return false;
	}
	tmp->data = ee;//输入值存入新结点
	//处理next指针
	tmp->next = nullptr;
	p->next = tmp;

	return true;
}
//显示链表中全部元素
void PrintList(const LNode* head)
{
	if (head == nullptr)
	{
		cout << "链表不存在" << endl;
		return;
	}
	LNode* p = head->next;//第一个结点开始
	cout << "链表为：";
	while (p != nullptr)
	{
		cout << p->data << " ";//如果元素为结构体，这行代码要修改
		p = p->next;//指针向后移动一个结点
	}
	cout << endl;
}
//求链表表长，返回值：表结点个数
size_t ListLength(LNode* head)//size_t 类型表示C中任何对象所能达到的最大长度，它是无符号整数,一定要给这种类型的变量赋正数
{
	if (head == nullptr)
	{
		cout << "链表不存在" << endl;
		return 0;
	}
	LNode* p = head->next;
	size_t length = 0;
	while (p != nullptr)
	{
		length++;
		p = p->next;
	}
	return length;
	/*不使用临时变量p：
	if (head == nullptr)return 0;
	return ListLength(head->next) + 1;
	*/
}
//删除链表第一个结点
int PopFront(LNode* head)
{
	if (head == nullptr)
	{
		cout << "链表不存在" << endl;
		return false;
	}
	if (head->next == nullptr)
	{
		cout << "链表为空，没有节点" << endl;
		return false;
	}
	LNode* p = head->next;
	head->next = head->next->next;
	delete p;

	return true;
}
//删除链表最后一个结点
int PopBack(LNode* head)
{
	if (head == nullptr)
	{
		cout << "链表不存在" << endl;
		return false;
	}
	LNode* p = head;
	while (p->next->next != nullptr)
	{
		p = p->next;
	}//遍历，找到倒数第二个结点（包括头结点）
	delete p->next;
	p->next = nullptr;

	return true;
}
//清空链表，释放链表所有结点，不包括头结点
void ClearList(LNode* head)
{
	if (head == nullptr)
	{
		cout << "链表不存在" << endl;
		return;
	}
	LNode* tmp1;
	LNode* tmp2 = head->next;
	while (tmp2 != nullptr)
	{
		tmp1 = tmp2;
		tmp2 = tmp1->next;
		delete tmp1;
	}
	head->next = nullptr;//如果缺少这行代码，就会留下野指针
}
//查找元素ee在链表中的结点地址，没找到返回nullptr，找到了返回结点地址
LNode* LocateElem(const LNode* head, const ElemType& ee)
{

	LNode* p = head->next;
	while (p != nullptr)
	{
		if (p->data == ee)
		{
			return p;
		}
		p = p->next;
	}
	return p;
}
//获取第n个节点，成功返回节点地址，失败返回nullptr（第0个是头节点）
LNode* LocateNode(LNode* head, unsigned int n)
{
	if (head == nullptr)
	{
		cout << "链表不存在" << endl;
		return nullptr;
	}
	unsigned int ii = 0;
	LNode* p = head;
	while (p != nullptr && (ii < n))
	{
		p = p->next;
		ii++;
	}
	if (p == nullptr)
	{
		cout << "位置" << n << "不合法，超过了表长。" << endl;
		return nullptr;
	}
	return p;
}
//在指定结点后插入元素ee
bool InsertNextNode(LNode* p, const ElemType& ee)
{
	if (p == nullptr)
	{
		cout << "指定结点不存在" << endl;
		return false;
	}
	LNode* tmp = new LNode;
	tmp->data = ee;
	tmp->next = p->next;
	p->next = tmp;

	return true;
}
//在指定结点之前插入元素ee
bool InsertPriorNode(LNode* p, const ElemType& ee)
{
	if (p == nullptr)
	{
		cout << "指定结点不存在" << endl;
		return false;
	}
	// 在指定结点p之前插入采用偷梁换柱的方法
	// 1、分配一个新的结点;
	LNode* tmp = new LNode;
	// 2、把pp结点的数据和指针复制到新结点中
	tmp->data = p->data;
	tmp->next = p->next;
	// 3、把待插入元素的数据存入p结点中。
	p->data = ee;
	p->next = tmp;

	return true;
}
//删除指定结点
bool DeleteNode(LNode* p)
{
	if (p == nullptr)
	{
		cout << "指定结点不存在" << endl;
		return false;
	}
	if (p->next != nullptr)//如果p后面还有结点
	{
		// 删除指定结点的思想是: 
		// 1) 把p后继结点的数据和next指针复制到p结点;
		LNode* tmp = p->next;
		p->data = tmp->data;
		p->next = tmp->next;
		// 2) 删除p结点的后继结点。
		delete tmp;
	}
	else
	{
		return false;
	}
}
//链表的排序
/*如果链表为空，不需要排序。
	如果链表只有一个结点，不需要排序。
	先将第一个结点与后面所有的结点依次对比数据域，只要有比第一个结点数据域小的，则交换位置。
	交换之后，拿新的第一个结点的数据域与下一个结点再次对比，如果比他小，再次交换，依次类推。
	第一个结点确定完毕之后，接下来再将第二个结点与后面所有的结点对比，直到最后一个结点也对比完毕为止*/
	//冒泡排序（数据域交换）
void OrderList(LNode* head)
{
	if (head == nullptr)
	{
		cout << "链表不存在，不需要排序" << endl;
		return;
	}
	if (head->next == nullptr)
	{
		cout << "链表只有一个结点，不需要排序" << endl;
		return;
	}
	int i = 0, j = 0;
	LNode* po = head;
	LNode* p, * p1;
	size_t length = ListLength(head);
	for (i = 0; i < length - 1; i++)
	{
		po = head->next;
		for (j = 0; j < length - i - 1; j++)
		{
			p = po;
			p1 = po->next;
			if (p->data > p1->data)
			{
				ElemType temp = p->data;
				p->data = p1->data;
				p1->data = temp;
			}
			po = po->next;
		}
	}
}
int main()
{
	LNode* LL = InitList();
	cout << "输入1：使用头插法" << endl << "输入2：使用尾插法 " << endl << "输入3，获取链表长度" << endl << "输入4：获取元素n在链表中位置并在后方插入元素x" << endl << "输入5：获取第n个节点并在指定结点前插入元素x" << endl << "输入6：删除指定节点；" << endl << "输入7：链表排序" << endl << "输入8：清空链表" << endl << "输入9：销毁链表" << endl;
	int mod = 0;

	while (1)
	{
		cin >> mod;
		if (mod == 1)
		{
			cout << "头插法插入所需元素" << endl;
			int n;
			while (cin >> n)
			{
				PushFront(LL, n);
				if (cin.get() == '\n') break;
			}

			PrintList(LL);
		}
		else if (mod == 2)
		{
			cout << "尾插法插入所需元素" << endl;
			int n;
			while (cin >> n)
			{
				PushBack(LL, n);
				if (cin.get() == '\n') break;
			}

			PrintList(LL);
		}
		else if (mod == 3)
		{
			cout << "链表长度：" << ListLength(LL) << endl;
		}
		else if (mod == 4)
		{
			cout << "获取元素n在链表中位置并在后方插入元素x" << endl;
			int n, x;
			cin >> n >> x;
			InsertNextNode(LocateElem(LL, n), x);

			PrintList(LL);
		}
		else if (mod == 5)
		{
			cout << "获取第n个节点并在指定结点前插入元素x" << endl;
			int n, x;
			cin >> n >> x;
			InsertPriorNode(LocateNode(LL, n), x);

			PrintList(LL);
		}
		else if (mod == 6)
		{
			cout << "删除链表第n个结点" << endl;
			int n;
			cin >> n;
			DeleteNode(LocateNode(LL, n));

			PrintList(LL);
		}
		else if (mod == 7)
		{
			cout << "链表排序：(数据域交换)" << endl;
			OrderList(LL);

			PrintList(LL);
		}
		else if (mod == 8)
		{
			cout << "清空链表" << endl;
			ClearList(LL);
			PrintList(LL);
		}
		else if (mod == 9)
		{
			cout << "销毁链表" << endl;
			DestroyList(LL);
		}
		else if (mod == 114514)
		{
			cout << "恭喜你进入隐藏选项！press 1：删除链表第一个结点；press 2：删除链表最后一个结点" << endl;
			int surprise = 0;
			cin >> surprise;
			if (surprise == 1)
			{
				PopFront(LL);

				PrintList(LL);
				cout << "已退出隐藏选项" << endl;
			}
			else if (surprise == 2)
			{
				PopBack(LL);

				PrintList(LL);
				cout << "已退出隐藏选项" << endl;
			}

		}
		else
		{
			cout << "请输入正常选项！" << endl;
		}

	}


	return 0;
}