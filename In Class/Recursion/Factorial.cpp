#include <iostream>
using namespace std;

int Factorial(int n)
{
	// n! = n * (n-1) * (n-2) * ... * 3 * 2 * 1
	for (int i = n-1; i > 0; i--)
	{
		n *= i;
	}
	return n;
}

int Factorial_Rec(int n)
{
	// Terminating Case
	if (n == 0)
	{
		return 1;
	}

	// Recursive Case
	return n * Factorial_Rec(n - 1);
}

int main()
{
	cout << "Iterative 5! = " << Factorial(5) << endl;
	cout << "Recursive 5! = " << Factorial_Rec(5) << endl;

	cin.ignore();
	cin.get();
	return 0;
}