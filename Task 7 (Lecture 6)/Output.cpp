#include <iostream>
#include <vector>
using namespace std;

const int N = 10;

void rec_out(vector<int> vc, int n = 0)
{
	try
	{
		vc[n]++;
		cout << n << endl;
		rec_out(vc, n + 1);
	}
	catch (...)
	{
		return;
	}
}

int main()
{
	vector<int> vect(N, 0);

	rec_out(vect);
}
