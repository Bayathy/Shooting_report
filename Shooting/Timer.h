#pragma once
#pragma once
#include <chrono>

class Timer
{
	std::chrono::system_clock::time_point start;

public:
	Timer();
	virtual ~Timer();

	void reset();
	double get();
};

