#include <iostream>
using namespace std;

template<typename DataType>
class List
{
private:
	struct Node
	{
		Node* next;
		DataType val;
	} *head;

public:
	List()
	{
		head = new Node{ nullptr, 0 };
	}

	~List()
	{
		delete[] head;
	}

	void print()
	{
		Node* cur = head;
		while (cur->next != nullptr)
		{
			cout << cur->val << ' ';
			cur = cur->next;
		}
		cout << endl;
	}

	DataType get(int pos)
	{
		Node* cur = head;
		int i = 0;

		while (cur->next != nullptr && i != pos)
		{
			cur = cur->next;
			i++;
		}

		return cur->val;
	}

	void set(int pos, int val)
	{
		Node* cur = head;
		int i = 0;

		while (cur->next != nullptr && i != pos)
		{
			cur = cur->next;
			i++;
		}

		cur->val = val;
	}

	void remove(int pos)
	{
		Node* cur = head;
		int i = 0;

		while (cur->next != nullptr && i != pos)
		{
			cur = cur->next;
			i++;
		}

		if (cur->next != nullptr && cur->next->next != nullptr)
		{
			while (cur->next->next->next != nullptr)
			{
				cur->val = cur->next->val;
				cur = cur->next;
			}

			cur->val = cur->next->val;
			delete cur->next->next;
			cur->next = new Node{ nullptr, 0 };
		}
	}

	void push_back(int val)
	{
		Node* cur = head;
		while (cur->next != nullptr) cur = cur->next;

		cur->val = val;
		cur->next = new Node{ nullptr, 0 };
	}

};



int main()
{
	List<int> ls;

	ls.push_back(1);
	ls.push_back(2);
	ls.push_back(9);
	ls.push_back(3);
	ls.print();
	cout << endl;

	ls.set(2, 4);
	ls.print();

	cout << endl << ls.get(2) << endl << endl;

	ls.remove(2);
	ls.print();
	
}
