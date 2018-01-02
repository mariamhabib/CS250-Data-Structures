#ifndef _INEFFICIENT_HPP
#DEFINE _INEFFICIENT_HPP

int CustomSearch( vector<string>& haystack, const string& needle )
{
	vector<int> indexes;
	vector<int>::iterator found;

	cout << "Search" << endl;
	int counter = 0;
	int index = rand() % haystack.size();
	indexes.push_back(index);
	while (haystack[index] != needle)
	{
		found = find(indexes.begin(), indexes.end(), index);
		while (found != indexes.end())
		{
			found = find(indexes.begin(), indexes.end(), index);
			index = rand() % haystack.size();
		}

		cout << "Indexes checked: " << ( float(indexes.size()) / float(haystack.size()) * 100 ) << "%" << "\t";
		cout << "Total lookups: " << counter << "\t";
		cout << "Total words in list: " << haystack.size() << "\t";
		cout << "Check index: " << index << endl;
		
		indexes.push_back(index);
		counter++;
	}
	cout << "Found at " << index << " in " << counter << " lookups" << endl;
	return index;
}

#ENDIF
