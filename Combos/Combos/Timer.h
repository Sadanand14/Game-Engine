#ifndef TIMER_H_
#define	TIMER_H_
#include <chrono>

class Timer 
{
	std::chrono::high_resolution_clock::time_point startTime;
public:
	Timer();
	void Init();
	std::chrono::duration<float> GetCurrentTime();
};

#endif // !1

