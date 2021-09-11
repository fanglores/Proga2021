#include <iostream>
using namespace std;

/*
Вариант 2
1. Написать класс для работы со строками

class FooString {
   char* buf;
public:
   FooString(char* tbuf);
   ~FooString();
   void show ();

   bool compare(FooString str);       // Вариант 2  - true – если строки равны
};
2. Для метода по варианту написать модульный тесты, проверяющие его работу
*/

class FooString
{
	char* buf;

public:
	FooString(char*);
	~FooString();
	void show();
	bool compare(FooString);
};

FooString::FooString(char* buf)
{
	this->buf = buf;
}

FooString::~FooString()
{
	//в данной реализации динамического выделения памяти внутри класса нет, поэтому в деструкторе нет необходимости
	//delete buf;
}

void FooString::show()
{
	cout << buf;
}

bool FooString::compare(FooString str)
{
	int i = 0;

	while (buf[i] != '\0' && str.buf[i] != '\0')
	{
		if (buf[i] != str.buf[i]) return false;
		i++;
	}

	if (buf[i] != str.buf[i]) return false;

	return true;
}

void testCompare()
{
	char ch1[100] = "Hello", ch2[100] ="Hello0";
	FooString fs1(ch1), fs2(ch2), fs3(ch1);
	if (fs1.compare(fs2) == false && fs1.compare(fs3) == true) cout << "\nTest successful!\n";
	else cout << "\nFail!\n";
}


int main()
{
	char ch1[100];
	cin >> ch1;

	FooString fs1(ch1);
	fs1.show();

	//testCompare();
}
