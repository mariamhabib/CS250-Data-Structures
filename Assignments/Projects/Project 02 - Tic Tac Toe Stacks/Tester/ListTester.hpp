#ifndef LISTTESTER_HPP
#define LISTTESTER_HPP

#include "DoublyLinkedList.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

struct TestListItem;

class ListTester
{
    public:
    ListTester();

    void Menu();

    int TestPushFront();
    int TestPushBack();

    int TestPopFront();
    int TestPopBack();

    int TestGetFront();
    int TestGetBack();

    int TestItemCount();

    int TestAllItems();

    private:
    vector<TestListItem> tests;
    int totalTestCount;
};

struct TestListItem
{
    string name;
    function<int()> callFunction;

    TestListItem() { }

    TestListItem( const string& name, function<int()> callFunction )
    {
        this->name = name;
        this->callFunction = callFunction;
    }
};

#endif
