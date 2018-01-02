#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
using namespace std;

namespace dal
{

class Timer
{
    public:
    static void Start();
    static chrono::duration<double> GetElapsedTime();

    private:
    static chrono::system_clock::time_point m_startTime;
};

}

#endif
