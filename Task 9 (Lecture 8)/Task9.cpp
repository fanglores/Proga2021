#include <thread>
#include <vector>
#include <iostream>
#include <ctime>
#include <mutex>
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

mutex vec_locker;

void modulator(double m, double h, double v, double dt = 0.01)
{
	double t = 0.0;

	while(h > 0)
	{



		vec_locker.lock();
		states.push_back({ t, h, v });
		this_thread::sleep_for(chrono::milliseconds(10));
		vec_locker.unlock();
	}
}

void printer()
{
	while (true)
	{
		this_thread::sleep_for(chrono::milliseconds(90));

		vec_locker.lock();
		state tmp = states.back();
		this_thread::sleep_for(chrono::milliseconds(10));
		vec_locker.unlock();

		cout << tmp.t << ' ' << tmp.h << ' ' << tmp.v << endl;
	}
}

int main()
{
	double m, v, h;

	cout << "Mass >> ";
	cin >> m;
	cout << "Start height >> ";
	cin >> h;
	cout << "Start velocity >> ";
	cin >> v;

	states.push_back( {0.0, h, v} );
	
	cout << endl << endl << "Time\tHeight\tVelocity" << endl;

	thread thread_m(modulator, m, h, v);
	thread thread_p(printer);

	thread_m.join();
	thread_p.detach();
}
