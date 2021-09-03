#include <iostream>
#include <string>
using namespace std;

/*
Вариант 1.
Номер варианта – остаток от деления суммы всех букв фамилии на число вариантов.
*/
unsigned int variant_all = 2;

unsigned int var(string s)
{
	int sum = 0;
	for (int i = 0; i < s.size(); i++) sum += int(s[i]);

	return (sum % variant_all + 1);
}

int main()
{
	cout << "Enter your Name and Surname\n>>";

	string name, sname;
	cin >> name >> sname;

	cout << "Your variant is " << var(sname);
}
