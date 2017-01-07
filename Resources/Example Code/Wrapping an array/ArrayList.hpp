#ifndef _ARRAY_LIST_HPP
#define _ARRAY_LIST_HPP

#include <string>
using namespace std;

class ArrayList
{
    public:
    ArrayList();
    void Insert( string newData );
    int GetItemCount();

    private:
    string dataList[100];
    int itemCount;
};

#endif
