# Algoritm Efficiency Lab

## Introduction

## Turn-in

Upload your **.cpp**, **.hpp** (or **.h**) files.

## Group Work Policy

* Group work and/or collaboration is allowed for this assignment.
* You are allowed to research on the internet.
* You are allowed to ask the instructor for help.

---

# Starting Off

Use this code to begin with:


      #include <iostream>
      #include <string>
      #include <cstdlib>
      #include <ctime>
      using namespace std;

      void InitArray( int arrayOfData[], int arraySize )
      {
          cout << "Initializing..." << endl;
          for ( int i = 0; i < arraySize; i++ )
          {
              arrayOfData[ i ] = rand() % arraySize;
          }
      }

      bool FindValue( const int arrayOfData[], int arraySize, int findMe )
      {
          cout << "Searching..." << endl;
          for ( int i = 0; i < arraySize; i++ )
          {
              if ( arrayOfData[i] == findMe )
              {
                  return true;
              }
          }
          return false;
      }

      int main()
      {
        srand( time( NULL ) );

          int arraySize = 1000000;
          int arrayOfData[ 1000000 ];
          InitArray( arrayOfData, arraySize );

          int searchFor = rand() % arraySize;
          cout << "Found value " << searchFor << "? " << FindValue( arrayOfData, arraySize, searchFor ) << endl;

          return 0;
      }

You will also want to download the Timer files:

**Timer.hpp**

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


**Timer.cpp**

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



---

# Instructions

Work in progress.
