#ifndef BOOK_PROGRAM_HPP
#define BOOK_PROGRAM_HPP

#include <vector>
using namespace std;

#include "Page.hpp"

class BookProgram
{
public:
	BookProgram();
	~BookProgram();

	void Run();

private:
	void LoadBook( const string& filename );
	void SaveBook();

	vector<Page> m_pages;
	string m_filename;
};

#endif