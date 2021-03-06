/**

Rate: to achieve simple frame rate control using C++ 11 standard library

By ZHENG Fan fzheng@link.cuhk.edu.hk

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Rate.h"
#include <ctime>
#include <thread>

using namespace std;
using namespace std::chrono;

void print_time_now();

int main(int argc, char** argv)
{
	using namespace utl;
	int counter = 0;
	auto tp_start = system_clock::now();
	int iteration = 300;

	int fps = 30;
	Rate rate(fps);
	for (int i = 0; i < iteration; i++)
	{
		counter++;
		if (counter == fps)
		{
			cout << "Time now: ";
			print_time_now();
			counter = 0;
		}
		if (i == 100)
			std::this_thread::sleep_for(seconds(2));
		rate.sleep();
	}

	auto tp_end = system_clock::now();

	auto duration = chrono::duration_cast<chrono::milliseconds>(tp_end - tp_start).count();

	cout << "After " << iteration << " iterations, " << duration / 1e3 << " seconds has passed." << endl;
	cout << "Press Enter to exit...";

	cin.get();

	return 0;
}

void print_time_now()
{
	auto tp = system_clock::now();
	std::time_t tt = system_clock::to_time_t(tp);
	cout << ctime(&tt) << endl;
}
