#include <iostream>
#include <bitset>
#include <string>
using namespace std;

const int SIZE = 10;

/*Вариант 1
Задание лекция 3 - Software.

Написать программу, которая:
- умеет читать текcтовый файл, который может быть указан ей в качестве аргумента командной строки и содержит 
названия протоколов (одно на строке)
Пример файла:

BinaryProtocol
HexProtocol
HexProtocol

- Реализует классы Protocol, BinaryProtocol, HexProtocol
- Классы BinaryProtocol, HexProtocol являются наследниками Protocol
- Класс Protocol определяет виртуальный метод void send(char* buf, int len), который ничего не делает
- Классы BinaryProtocol, HexProtocol переопределяют виртуальный метод void send(char* buf, int len)
  - void BinaryProtocol::send(char* buf, int len) - печатает на экран содержимое строки buf в виде бинарного кода 
  (т.е. при помощи "0101 0101 0100 1000")
  - void HexProtocol::send(char* buf, int len)    - печатает на экран содержимое строки buf в виде шестнатеричного кода 
  (т.е. так "0xff 0xff")

Дополнительно:

Вариант 1.
- Создать динамический массив указателей (размер равен числу протоколов в файле) на класс Protocol и функцию
для добавления туда указатели на объекты классов, соответствующие протоколам, считанным из файла
- Написать функцию для печати отправки введенного с клавиатуры сообщения при помощи всех протоколов 
void sendAll(Protocol **p, int number_of_prorocols)
*/

class Protocol
{
protected:
	virtual void send(char* buf, int len) = 0;
};

class BinaryProtocol : public Protocol
{
public:
	void send(char* buf, int len)
	{
		for (int i = 0; i < len && buf[i] != '\0'; i++)
		{
			bitset<8> x(buf[i]);
			cout << x << ' ';
		}
	}
};

class HexProtocol : public Protocol
{
public:
	void send(char* buf, int len)
	{
		for (int i = 0; i < len && buf[i] != '\0'; i++)
			cout << "0x" << hex << (int)(buf[i] & 0xff) << ' ';
	}
};

void fileReader()
{
	string fn;

	cout << "Enter filename: ";
	cin >> fn;



}

void sendAll(Protocol** p, int number_of_prorocols)
{
	char ch[SIZE];
	cin >> ch;

	for (int i = 0; i < number_of_prorocols; i++)
	{
		//(p[i])->send(ch, 20);

	}


}


int main()
{
	char ch[SIZE];
	cin >> ch;

	BinaryProtocol bp;
	bp.send(ch, SIZE);

	cout << endl << string(80, '=') << endl;

	HexProtocol hp;
	hp.send(ch, SIZE);

	cout << endl << endl;
}
