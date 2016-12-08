#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> LoadFile(string filename)
{
	string buffer;
	vector<string> list;

	ifstream input(filename);

	while (getline(input, buffer))
	{
		list.push_back(buffer);
	}

	input.close();
	return list;
}

void OutputVector(const vector<string>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << i << "\t" << arr[i] << endl;
	}
}

int QuickSort_Partition(vector<string>& arr, int low, int high)
{
	string pivot = arr[high];

	int i = low;

	for (int j = low; j <= high - 1; j++) // <= ?
	{
		if (arr[j] <= pivot)
		{
			string temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

			i += 1;
		}
	}

	string temp = arr[i];
	arr[i] = arr[high];
	arr[high] = temp;
	
	return i;
}

void QuickSort(vector<string>& arr, int low, int high)
{
	if (low < high)
	{
		int partition = QuickSort_Partition(arr, low, high);
		QuickSort(arr, low, partition - 1);
		QuickSort(arr, partition + 1, high);
	}
}

int main()
{
	vector<string> unsortedCountries = LoadFile("countrylist_jumbled.txt");
	vector<string> sorted = unsortedCountries;

	QuickSort(sorted, 0, sorted.size() - 1);

	cout << "Sorted: " << endl;
	OutputVector(sorted);

	while (true) { ; }

	return 0;
}
