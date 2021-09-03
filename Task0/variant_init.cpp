#include <iostream>
using namespace std;

unsigned int variant_all = 2;


int main()
{
	unsigned int number;
	cin >> number;
	cout << number % variant_all + 1;
}
