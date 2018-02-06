#include <iostream>
using namespace std;

void CountUp(int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		cout << i << " ";
	}
}

void CountUp_Rec(int start, int end)
{
	cout << start << " ";

	// Terminating Case
	if (start == end)
	{
		return;
	}

	// Recursive Case
	CountUp_Rec(start+1,end);
}

int main()
{
	CountUp(5, 15);

	cout << endl << endl;

	CountUp_Rec(5, 15);


	cin.ignore();
	cin.get();
	return 0;
}