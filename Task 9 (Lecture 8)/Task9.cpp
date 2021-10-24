#include <thread>
#include <mutex>

#include <vector>

#include <iostream>
#include <iomanip>
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
- Печатать на экран информацию о траектории движения шарика за заданный промежуток времени
*/

const double g = 9.80665;
const double dt = 0.01;
const int print_delay = 100;
const int calc_delay = 50;

//data stored as time, height, velocity
struct state
{
	double t;
	double h;
	double v;
};
vector <state> states(0);

mutex vec_locker;

void modulator(double H, double V)
{
	double h, v, t = dt;
	double t0 = (V + sqrt(V * V + 2 * g * H)) / g;

	do
	{
		if (t >= t0) t = t0;

		h = H + V * t - g * t * t / 2;
		v = V - g * t;
		t += dt;

		vec_locker.lock();
		states.push_back({ t, h, v });
		this_thread::sleep_for(chrono::milliseconds(10));
		vec_locker.unlock();

		//cout << "Whoop!" << endl;
		this_thread::sleep_for(chrono::milliseconds(calc_delay - 10));
	} while (h > 0);
}

void printer()
{
	state tmp;
	do
	{
		this_thread::sleep_for(chrono::milliseconds(print_delay - 10));

		vec_locker.lock();
		tmp = states.back();
		this_thread::sleep_for(chrono::milliseconds(10));
		vec_locker.unlock();

		cout << fixed;
		cout << setprecision(2) << tmp.t << '\t' << tmp.h << '\t' << tmp.v << endl;
	} while (tmp.h > 0);
}

int main()
{
	double v, h;

	cout << "Start height >> ";
	cin >> h;
	cout << "Start velocity >> ";
	cin >> v;

	states.push_back({ 0.0, h, v });

	cout << endl << endl << "Time\tHeight\tVelocity" << endl;
	cout << fixed;
	cout << setprecision(2) << 0.00 << '\t' << h << '\t' << v << endl;

	thread thread_m(modulator, h, v);
	thread thread_p(printer);

	thread_m.join();
	thread_p.join();
}
