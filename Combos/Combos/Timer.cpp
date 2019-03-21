#include "Timer.h"

Timer::Timer() 
{
	startTime = std::chrono::high_resolution_clock::now();
}

void Timer::Init() 
{

}

std::chrono::duration<float> Timer::GetCurrentTime()
{
	using namespace std;
	auto time = chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = time - startTime;
	return duration;
}