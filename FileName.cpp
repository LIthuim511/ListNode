#include<iostream>
using namespace std;

typedef int ElemType;//�Զ�����������Ԫ��Ϊ����

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
//��ʼ����������ֵ��ʧ�ܷ���nullptr���ɹ�����ͷ����ַ
LNode* InitList()
{
	LNode* head = new LNode;//����ͷ���
	if (head == nullptr)
	{
		return nullptr;//�ڴ治�㣬����ʧ��
	}
	head->next = nullptr;
	return head;
}
//��������
void DestroyList(LNode* head)
{
	LNode* tmp;

	while (head != nullptr)
	{
		tmp = head->next;//trmp������һ���ĵ�ַ
		delete head;//�ͷŵ�ǰ���
		head = tmp;//ָ���ƶ�����һ���
	}
}
//ͷ�巨������ֵ��falseʧ�ܣ�true�ɹ�
bool PushFront(LNode* head, const ElemType& ee)
{
	if (head == nullptr)
	{
		cout << "��������" << endl;
	}
	LNode* tmp = new LNode;//�����½��
	if (tmp == nullptr)
	{
		return false;
	}
	tmp->data = ee;//����ֵ�����½��
	//����nextָ��
	tmp->next = head->next;
	head->next = tmp;

	return true;
}
//β�巨����β������Ԫ�أ�
bool PushBack(LNode* head, const ElemType& ee)
{
	if (head == nullptr)
	{
		cout << "��������" << endl;
	}
	LNode* p = head;//��ͷ��㿪ʼ

	//�ҵ����һ����㣬pָ��β���
	while (p->next != nullptr)
	{
		p = p->next;
	}
	LNode* tmp = new LNode;//�����½��
	if (tmp == nullptr)
	{
		return false;
	}
	tmp->data = ee;//����ֵ�����½��
	//����nextָ��
	tmp->next = nullptr;
	p->next = tmp;

	return true;
}
//��ʾ������ȫ��Ԫ��
void PrintList(const LNode* head)
{
	if (head == nullptr)
	{
		cout << "��������" << endl;
		return;
	}
	LNode* p = head->next;//��һ����㿪ʼ
	cout << "����Ϊ��";
	while (p != nullptr)
	{
		cout << p->data << " ";//���Ԫ��Ϊ�ṹ�壬���д���Ҫ�޸�
		p = p->next;//ָ������ƶ�һ�����
	}
	cout << endl;
}
//�������������ֵ���������
size_t ListLength(LNode* head)//size_t ���ͱ�ʾC���κζ������ܴﵽ����󳤶ȣ������޷�������,һ��Ҫ���������͵ı���������
{
	if (head == nullptr)
	{
		cout << "��������" << endl;
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
	/*��ʹ����ʱ����p��
	if (head == nullptr)return 0;
	return ListLength(head->next) + 1;
	*/
}
//ɾ�������һ�����
int PopFront(LNode* head)
{
	if (head == nullptr)
	{
		cout << "��������" << endl;
		return false;
	}
	if (head->next == nullptr)
	{
		cout << "����Ϊ�գ�û�нڵ�" << endl;
		return false;
	}
	LNode* p = head->next;
	head->next = head->next->next;
	delete p;

	return true;
}
//ɾ���������һ�����
int PopBack(LNode* head)
{
	if (head == nullptr)
	{
		cout << "��������" << endl;
		return false;
	}
	LNode* p = head;
	while (p->next->next != nullptr)
	{
		p = p->next;
	}//�������ҵ������ڶ�����㣨����ͷ��㣩
	delete p->next;
	p->next = nullptr;

	return true;
}
//��������ͷ��������н�㣬������ͷ���
void ClearList(LNode* head)
{
	if (head == nullptr)
	{
		cout << "��������" << endl;
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
	head->next = nullptr;//���ȱ�����д��룬�ͻ�����Ұָ��
}
//����Ԫ��ee�������еĽ���ַ��û�ҵ�����nullptr���ҵ��˷��ؽ���ַ
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
//��ȡ��n���ڵ㣬�ɹ����ؽڵ��ַ��ʧ�ܷ���nullptr����0����ͷ�ڵ㣩
LNode* LocateNode(LNode* head, unsigned int n)
{
	if (head == nullptr)
	{
		cout << "��������" << endl;
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
		cout << "λ��" << n << "���Ϸ��������˱���" << endl;
		return nullptr;
	}
	return p;
}
//��ָ���������Ԫ��ee
bool InsertNextNode(LNode* p, const ElemType& ee)
{
	if (p == nullptr)
	{
		cout << "ָ����㲻����" << endl;
		return false;
	}
	LNode* tmp = new LNode;
	tmp->data = ee;
	tmp->next = p->next;
	p->next = tmp;

	return true;
}
//��ָ�����֮ǰ����Ԫ��ee
bool InsertPriorNode(LNode* p, const ElemType& ee)
{
	if (p == nullptr)
	{
		cout << "ָ����㲻����" << endl;
		return false;
	}
	// ��ָ�����p֮ǰ�������͵�������ķ���
	// 1������һ���µĽ��;
	LNode* tmp = new LNode;
	// 2����pp�������ݺ�ָ�븴�Ƶ��½����
	tmp->data = p->data;
	tmp->next = p->next;
	// 3���Ѵ�����Ԫ�ص����ݴ���p����С�
	p->data = ee;
	p->next = tmp;

	return true;
}
//ɾ��ָ�����
bool DeleteNode(LNode* p)
{
	if (p == nullptr)
	{
		cout << "ָ����㲻����" << endl;
		return false;
	}
	if (p->next != nullptr)//���p���滹�н��
	{
		// ɾ��ָ������˼����: 
		// 1) ��p��̽������ݺ�nextָ�븴�Ƶ�p���;
		LNode* tmp = p->next;
		p->data = tmp->data;
		p->next = tmp->next;
		// 2) ɾ��p���ĺ�̽�㡣
		delete tmp;
	}
	else
	{
		return false;
	}
}
//���������
/*�������Ϊ�գ�����Ҫ����
	�������ֻ��һ����㣬����Ҫ����
	�Ƚ���һ�������������еĽ�����ζԱ�������ֻҪ�бȵ�һ�����������С�ģ��򽻻�λ�á�
	����֮�����µĵ�һ����������������һ������ٴζԱȣ��������С���ٴν������������ơ�
	��һ�����ȷ�����֮�󣬽������ٽ��ڶ��������������еĽ��Աȣ�ֱ�����һ�����Ҳ�Ա����Ϊֹ*/
	//ð�����������򽻻���
void OrderList(LNode* head)
{
	if (head == nullptr)
	{
		cout << "�������ڣ�����Ҫ����" << endl;
		return;
	}
	if (head->next == nullptr)
	{
		cout << "����ֻ��һ����㣬����Ҫ����" << endl;
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
	cout << "����1��ʹ��ͷ�巨" << endl << "����2��ʹ��β�巨 " << endl << "����3����ȡ������" << endl << "����4����ȡԪ��n��������λ�ò��ں󷽲���Ԫ��x" << endl << "����5����ȡ��n���ڵ㲢��ָ�����ǰ����Ԫ��x" << endl << "����6��ɾ��ָ���ڵ㣻" << endl << "����7����������" << endl << "����8���������" << endl << "����9����������" << endl;
	int mod = 0;

	while (1)
	{
		cin >> mod;
		if (mod == 1)
		{
			cout << "ͷ�巨��������Ԫ��" << endl;
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
			cout << "β�巨��������Ԫ��" << endl;
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
			cout << "�����ȣ�" << ListLength(LL) << endl;
		}
		else if (mod == 4)
		{
			cout << "��ȡԪ��n��������λ�ò��ں󷽲���Ԫ��x" << endl;
			int n, x;
			cin >> n >> x;
			InsertNextNode(LocateElem(LL, n), x);

			PrintList(LL);
		}
		else if (mod == 5)
		{
			cout << "��ȡ��n���ڵ㲢��ָ�����ǰ����Ԫ��x" << endl;
			int n, x;
			cin >> n >> x;
			InsertPriorNode(LocateNode(LL, n), x);

			PrintList(LL);
		}
		else if (mod == 6)
		{
			cout << "ɾ�������n�����" << endl;
			int n;
			cin >> n;
			DeleteNode(LocateNode(LL, n));

			PrintList(LL);
		}
		else if (mod == 7)
		{
			cout << "��������(�����򽻻�)" << endl;
			OrderList(LL);

			PrintList(LL);
		}
		else if (mod == 8)
		{
			cout << "�������" << endl;
			ClearList(LL);
			PrintList(LL);
		}
		else if (mod == 9)
		{
			cout << "��������" << endl;
			DestroyList(LL);
		}
		else if (mod == 114514)
		{
			cout << "��ϲ���������ѡ�press 1��ɾ�������һ����㣻press 2��ɾ���������һ�����" << endl;
			int surprise = 0;
			cin >> surprise;
			if (surprise == 1)
			{
				PopFront(LL);

				PrintList(LL);
				cout << "���˳�����ѡ��" << endl;
			}
			else if (surprise == 2)
			{
				PopBack(LL);

				PrintList(LL);
				cout << "���˳�����ѡ��" << endl;
			}

		}
		else
		{
			cout << "����������ѡ�" << endl;
		}

	}


	return 0;
}