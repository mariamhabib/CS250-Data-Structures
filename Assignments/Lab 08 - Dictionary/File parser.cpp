/* One way to implement this */

Dictionary LoadDictionary()
{
	Dictionary dict;

	ifstream input("Dictionary.txt");

	cout << "Loading dictionary... ";

	string english, esperanto, line;
	while (getline(input, line))
	{
		if (line == "") { continue; }
		int eqsign = line.find("=");
		english = line.substr(0, eqsign - 1);
		esperanto = line.substr(eqsign + 2, line.size());

		dict.Insert(english, esperanto); 
	}

	cout << "done" << endl;

	input.close();

	return dict;
}
