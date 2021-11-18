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

	HashNode()
	{
		key = -1;
		value = -1;
	}

	HashNode(K key, V value)
	{
		this->key = key;
		this->value = value;
	}

};

template<class K, class V>
struct HashRow
{
	int size;
	HashNode<K, V>* row;

	HashRow()
	{
		size = 0;
	}

	HashRow(HashNode<K,V> node)
	{
		size = 1;
		row = new HashNode<K, V>(node.key, node.value);
	}

	push_back(HashNode<K, V> node)
	{
		HashNode<K,V>* trow = new HashNode<K, V>[size + 1];
		memcpy(trow, row, size * sizeof(HashNode<K, V>));
		trow[size] = node;

		row = new HashNode<K, V>[size + 1];
		
		memcpy(row, trow, (size + 1) * sizeof(HashNode<K,V>));
		size++;
	}

	~HashRow()
	{
		delete[] row;
	}
};

template<class K, class V>
class HashTable
{
private:
	HashRow<K, V>* table;
	int size = 0;
	const int k = 7, mod = 13;

public:

	~HashTable()
	{
		delete[] table;
	}

	K encrypt(V value)
	{
		int sum = 0;
		if (typeid(value) == typeid(string))
		{
			for (int i = 0; i < value.size(); i++)
				sum = sum * k + value[i];
		}
		else if (typeid(value) == typeid(char) || typeid(value) == typeid(int))
		{
			sum = value * k;
		}
		else cout << "[RE] Unsupported data type." << endl;

		return (sum % mod);
	}

	void insert(V value)
	{
		HashNode<K, V> temp(encrypt(value), value);

		int i;
		for (i = 0; i < size; i++) 
			if (table[i].row[0].key == temp.key) break;
		
		if (i == size)
		{
			HashRow<K, V>* ttab = new HashRow<K,V>[size + 1];
			memcpy(ttab, table, size * sizeof(HashRow<K,V>));
			ttab[size] = temp;
			
			table = new HashRow<K,V>[size + 1];

			memcpy(table, ttab, (size + 1) * sizeof(HashRow<K,V>));
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
			cout << table[i].row[0].key << '\t';
			for (int j = 0; j < table[i].size; j++)
			{
				cout << table[i].row[j].value << ' ';
			}
			cout << endl;
		}
	}
};

void file_processor()
{



}

int main()
{
	HashTable<int, string> ht;
	ht.insert("abc");
	ht.insert("bcd");
	ht.insert("cde");

	ht.print();
}
