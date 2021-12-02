#include "Timer.h"

using namespace std::chrono;

Timer::Timer()
{
	reset();
}

Timer::~Timer()
{
}

void Timer::reset()
{
	start = system_clock::now();
}

double Timer::get()
{
	auto end = system_clock::now();

	return duration_cast<milliseconds>(end - start).count() / 1000.0;
}