#include <iostream>

using std::cout;
using std::endl;

class LinkList;
class Node
{
	friend class LinkList;
	private:
		int Data;
		Node *Next;
	public:
		Node() :Data(0), Next(0) {};
		Node(int x) :Data(x), Next(0) {};
};

class LinkList
{
	public:
		LinkList() :first(0), top(-1) {};
		void Push(int);
		int Pop();
		bool Empty();
		void PrintStack();
	private:
		int top;
		Node *first;
};

int main()
{
	LinkList stack;
	stack.Push(10);
	stack.Push(11);
	stack.Pop();
	stack.Push(12);
	stack.PrintStack();

	system("pause");
	return 0;
}

void LinkList::Push(int x)
{
	Node *newnode = new Node(x);
	Node *current = first;
	if (current == 0)
	{
		first = newnode;
		top++;
		return;
	}

	newnode->Next = first;
	first = newnode;
	top++;
}

int LinkList::Pop()
{
	Node *current = first;
	int Data = first->Data;
	first = first->Next;
	top--;
	delete current;
	current = 0;
	return Data;
}

bool LinkList::Empty()
{
	if (top == -1) { return true; }
	else { return false; };
}

void LinkList::PrintStack()
{
	if (Empty() == true)
	{
		cout << "Stack is empty !!" << endl;
		return;
	}

	Node *current = first;
	while (current != 0)
	{
		cout << current->Data << " ";
		current = current->Next;
	}
	cout << endl;
}
