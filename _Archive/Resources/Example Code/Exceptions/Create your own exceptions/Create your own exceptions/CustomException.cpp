#include <iostream>
#include <string>
#include <exception>
using namespace std;

// My custom Exception type
class SpecialException : public exception
{
public:
	SpecialException(string message)
	{
		m_errorMessage = message;
	}

	virtual const char* what() const throw()
	{
		return m_errorMessage.c_str();
	}

private:
	string m_errorMessage;
};

// A function that throws the SpecialException
void RiskyFunction(int a)
{
	if (a == 0)
	{
		throw SpecialException("No zeroes allowed!");
	}

	cout << "A = " << a << endl;
}

// Use try/catch in main to detect.
int main()
{
	int num = 10;

	try
	{
		RiskyFunction(num);
	}
	catch (SpecialException ex)
	{
		cout << "ERROR! " << ex.what() << endl;
	}

	num = 0;

	try
	{
		RiskyFunction(num);
	}
	catch (SpecialException ex)
	{
		cout << "ERROR! " << ex.what() << endl;
	}

	return 0;
}