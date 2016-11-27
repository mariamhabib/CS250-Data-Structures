#include "Timer.hpp"

namespace dal
{

chrono::system_clock::time_point Timer::m_startTime;

void Timer::Start()
{
    m_startTime = chrono::system_clock::now();
}

chrono::duration<double> Timer::GetElapsedTime()
{
    return chrono::system_clock::now() - m_startTime;
}


}
