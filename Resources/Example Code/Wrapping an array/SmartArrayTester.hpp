#ifndef _SMART_ARRAY_TESTER_HPP
#define _SMART_ARRAY_TESTER_HPP

#include <string>
using namespace std;

class SmartArrayTester
{
public:
    static bool RunTests();

private:
    static bool TestPush();
    static bool TestGet();
    static bool TestGetSize();
};

#endif
