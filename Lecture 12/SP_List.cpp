#include <iostream>
using namespace std;

/*
Написать программу, содержащую:

Вариант 1.
 0. Определение типа для узла двусвязного списка (ссылка вперёд и назад), содержащего целочисленные данные
 1. функцию, добавляющую элемент в начало двусвязного списка (получаете указатель на голову списка, 
 возвращает указатель на новую голову.)
 2. Определяющую число элементов списка (получаете указатель на голову списка)
*/


struct List
{
	weak_ptr<List> prev;
	shared_ptr<List> next;
	int value;

	List() {}
	List(int v) : value{ v } {}
};

void push_back(shared_ptr<List> &h, int v)
{
	if (h)
	{
		shared_ptr<List> cur(h);

		while (cur->next != nullptr) cur = cur->next;
		
		shared_ptr<List> temp(new List(v));
		temp->prev = cur;

		cur->next = temp;
		cur = move(temp);

	}
	else
		h = make_shared<List>(v);
}

void push_front(shared_ptr<List> &h, int v)
{
	if (h)
	{
		shared_ptr<List> temp(new List(v));
		temp->next = h;
		
		h->prev = temp;
		h = move(temp);
	}
	else
		h = make_shared<List>(v);
}

void print(const shared_ptr<List> &h)
{
	if (h)
	{
		shared_ptr<List> cur(h);
		while (cur->next != nullptr)
		{
			cout << cur->value << ' ';
			cur = cur->next;
		}

		cout << cur->value << ' ';
	}
}

int count(const shared_ptr<List> &h)
{
	if (h)
	{
		List* tmp = h.get();
		int c = 0;

		while (tmp->next != nullptr)
		{
			c++;
			tmp = tmp->next.get();
		}

		return c + 1;
	}
	else return 0;
}

int main()
{
	shared_ptr<List> head;
	push_back(head, 1);
	push_back(head, 2);
	push_back(head, 3);
	push_front(head, 1);
	push_front(head, 2);
	push_front(head, 3);

	print(head);

	cout << endl << count(head);
}
