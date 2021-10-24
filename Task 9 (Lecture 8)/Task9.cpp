#include <thread>
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;

/*
1. Разработать программу, которая включает два потока один поток моделирует полет шарика, второй отображает
в текстовом виде положение шарика на экране с заданной частотой.

Информация о траектории полета (координаты и метка времени) должны заносится в std::vector

Масса, начальная скорость и положение шарика должны задаваться в качестве параметров командной строки.

Вариант 1
Моделируем полет брошенного в вертикально вверх со скоростью v шарика массой m.
При соударении с землей шарик прилипает к поверхности.
Программа должна иметь функции:
- Вычисления положения (h) и параметров движения шарика (v, a) через заданный промежуток времени
- Позволять записывать параметы движения шарика и метку времении в односвязный спискок
- Печатать на экран информацию о траектории движения шарика за заданный промежуток времени
*/

//data stored as time, height, velocity
struct state
{
	double t;
	double h;
	double v;
};
vector <state> states(0);

double M;

void modulator()
{

}

void printer()
{


}

int main()
{
	double v, h;
	cout << "Mass >> ";
	cin >> M;
	cout << "Start height >> ";
	cin >> h;
	cout << "Start velocity >> ";
	cin >> v;

	states.push_back( {0.0, h, v} );
	delete & v, h;
	

	thread thread_m(modulator);
	thread thread_p(printer);

	thread_m.join();
	thread_p.detach();
}
