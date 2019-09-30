#include <iostream>
#include <vector>

using namespace std;

#define SIZE 8 // 初始大小

typedef struct {
	int data;
	int next;
}Node;

class StaticList {
public:
	void ExCap()
	{
		if (Length == SIZE - 1)
		{
			int OldSize = sl.size();
			int NewSize = sl.size() * 2; // 2倍扩容
			sl.reserve(NewSize * sizeof(Node));
			for (size_t i = OldSize; i < NewSize; ++i)
			{
				Node tmp;
				tmp.next = i + 1;
				sl.push_back(tmp);
			}
			sl[NewSize - 1].next = 0;
			End = NewSize - 1;
			sl[Tail].next = OldSize;
			sl[0].next = OldSize;
		}
		else
			return;
	}

	void Reserve()
	{
		sl.reserve(sizeof(Node) * SIZE); // 设置初始长度为8
		for (size_t i = 0; i < SIZE; ++i)
		{
			Node tmp;
			tmp.next = i + 1;
			sl.push_back(tmp);
		}
		sl[SIZE - 1].next = 0;
		End = SIZE - 1;
	}
	void Init()
	{
		Node tmp;
		tmp.next = 1;
		sl.push_back(tmp);
		
		Tail = 0;
	}
	void Insert(int pos, int num)
	{
		if (pos < 1 || pos > Length)
		{
			cout << "error" << endl;
			return;
		}
		Push(num);
		int pre = Head;
		for (int i = 0; i < pos - 2; ++i)
			pre = sl[pre].next;
		int t = sl[pre].next;
		sl[pre].next = Tail;
		sl[PreTail].next = 0;
		sl[Tail].next = t;
		Tail = PreTail;
		Length++;
	}
	void Push(int num)
	{
		ExCap();
		int pos = sl[0].next;

		sl[pos].data = num;
		sl[0].next = sl[pos].next;
		if (Tail != 0)
			sl[Tail].next = pos;
		PreTail = Tail;
		Tail = pos;
		sl[pos].next = 0;

 		Length++;
	}
	void Erase(int num)
	{
		int pos = Find(num);
		int pre = Head;
		
		for (int i = 0; i < pos - 2; ++i)
		{
			pre = sl[pre].next;
		}
		if (pos == Head)
			Head = sl[Head].next;
		sl[pre].next = sl[sl[pre].next].next;
		sl[pos].next = 0;

		sl[End].next = pos;
		End = pos;

		Length--;
	}
	int Find(int num)
	{
		int begin = Head;

		while (begin != 0)
		{
			if (sl[begin].data != num)
				begin = sl[begin].next;
			else
				return begin;
		}
		return -1;
	}
private:
	int Head = 1;
	int Tail;
	int PreTail;
	int Length = 0;
	int End;
	vector<Node> sl;
};

int main()
{
	StaticList SL;
	SL.Reserve();
	SL.Push(1);
	SL.Push(2);
	SL.Push(3);
	SL.Push(4);
	SL.Push(5);
	SL.Push(6);
	SL.Push(7);

	//SL.Push(8);
	//SL.Push(9);
	//SL.Push(10);

	SL.Insert(2, 10);
	SL.Erase(2);
	SL.Push(100);


	cout << SL.Find(1) << endl;
	cout << SL.Find(2) << endl;
	cout << SL.Find(3) << endl;
	cout << SL.Find(4) << endl;
	cout << SL.Find(5) << endl;

	system("pause");
	return 0;
}