#include <iostream>
#include <string>
using namespace std;

#include "Tree.hpp"

int main()
{
	Tree<int, string> myTree;

	myTree.Add(5, "a");

	myTree.Add(2, "a");
	myTree.Add(8, "a");

	myTree.Add(1, "a");
	myTree.Add(3, "a");


	return 0;
}
