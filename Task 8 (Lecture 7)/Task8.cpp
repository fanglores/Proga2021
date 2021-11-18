#include <string>
#include <iostream>
using namespace std;

/*
1. Разработать собственный шаблонный класс для работы с хеш таблицей. Класс должен позволять:
- Добавлять пары ключ, значение
- Позволять искать значение по ключу
- Позволять изменять значение по ключу
- Позволять удалять значение по ключу

Вариант 1
В случае возникновения коллизии (два ключа указывают на одно место в таблице) значения помещаются в односвязный список

2. Написать программу определения частоты слов в тексте. Программа должна:
- Принимать имя текстового файла для анализа в качестве параметра командной строки
- Читать файл
- Выделять слова (слово - последовательность симоволов, отделяемая разделителями пробел, табуляция, точка, запятая и т.д.)
- Инкрементировать счетчик слов, для данного слова, используя в качестве контейнера хеш таблицу, разработанную в задании 1
   - слово - ключ, число упоминаний в тексте - значение
- Выести слова и число вхождений в тексте
*/

template<class K, class V>
struct HashNode
{
	K key;
	V value;

	HashNode(K key, V value)
	{
		this->key = key;
		this->value = value;
	}

};

template<class K, class V>
class HashRow
{
public:	
	V* row;
	K row_key;
	int size;

	HashRow()
	{
		size = 0;
	}

	HashRow(HashNode<K,V> node)
	{
		size = 1;
		row_key = node.key;

		row = new V[1];
		row[0] = node.value;
	}

	void push_back(HashNode<K, V> node)
	{
		if (size == 0) row_key = node.key;
		else if (node.key == row_key)
		{
			V* trow = new V[size + 1];
			memcpy(trow, row, size * sizeof(V));
			trow[size] = node.value;

			row = new V[size + 1];

			memcpy(row, trow, (size + 1) * sizeof(V));
			size++;
		}
		else cout << "[RE] Passed wrong node push back to." << endl;
	}

	void push(HashNode<K, V> node)
	{
		size = 1;
		row_key = node.key;

		row = new V[1];
		row[0] = node.value;
	}

	void push(K k,V* val, int sz)
	{
		size = sz;
		row_key = k;

		row = new V[sz];
		memcpy(row, val, sz * sizeof(V));
	}

	void print()
	{
		for (int i = 0; i < size; i++)
			cout << row[i] << ' ';
	}

	~HashRow()
	{
		delete[] row;
	}

};

template<class K, class V>
class HashTable
{
public:
	HashRow<K, V>* table;
	const int k = 7, mod = 10007;

	int size = 0;

	~HashTable()
	{
		delete[] table;
	}

	int encrypt(V value)
	{
		int sum = 0;
		if (typeid(value) == typeid(string))
		{
			for (int i = 0; i < value.size(); i++)
				sum = sum * k + value[i];
		}
		else cout << "[RE] Unsupported data type." << endl;

		return (sum % mod);
	}

	void insert(V value)
	{
		HashNode<K, V> temp(encrypt(value), value);

		int i;
		for (i = 0; i < size; i++) 
			if (table[i].row_key == temp.key) break;
		
		if (i == size)
		{
			HashRow<K, V>* ttab = new HashRow<K,V>[size + 1];
			for (int j = 0; j < size; j++) 
				ttab[j].push(table[j].row_key, table[j].row, table[j].size);
			ttab[size].push(temp);

			table = new HashRow<K,V>[size + 1];

			for (int j = 0; j < size + 1; j++)
				table[j].push(ttab[j].row_key, ttab[j].row, ttab[j].size);
			
			size++;
		}
		else
		{
			table[i].push_back(temp);
		}
	}

	V get(K key) 
	{
		
	
	}

	void update() {}
	void remove() {}


	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << table[i].row_key << '\t';
			table[i].print();
			cout << endl;
		}
	}
};

template<class K, class V>
void mymemcpy(HashRow<K, V>* ht1, HashRow<K, V>* ht2)
{
	for (int i = 0; i < ht1->size; i++)
	{
		memcpy(ht2[i].row, ht1[i].row, ht1[i].size * sizeof(V));
	}
}

void file_processor()
{



}



int main()
{
	HashTable<int, string> ht;
	ht.insert("abc");
	ht.insert("bcd");
	ht.insert("cde");

	ht.insert("abc");

	ht.print();
}
