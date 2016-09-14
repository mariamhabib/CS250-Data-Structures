#ifndef _DOCUMENT
#define _DOCUMENT

#include <string>
#include <fstream>
#include <vector>
using namespace std;

// Document Interface
class IDocument
{
public:
    virtual ~IDocument() { }

    string GetFriendlyName() { return m_friendlyName; }
    void SetFriendlyName( const string& value ) { m_friendlyName = value; }

    string GetFilename() { return m_filename; }
    string GetType() { return m_type; }

    virtual void Load( const string& filename ) = 0;
    virtual void Save( const string& filename ) = 0;
    virtual void GetInput() = 0;
    virtual ofstream& Display( ofstream& out ) = 0;

protected:
    string m_friendlyName;
    string m_filename;
    string m_type;
};

// Implementations of Documents

class TextDocument : public IDocument
{
public:
    TextDocument();
    virtual ~TextDocument() { }

    virtual void Load( const string& filename );
    virtual void Save( const string& filename );
    virtual ofstream& Display( ofstream& out );
    virtual void GetInput();

    void SetContent( const string& content );

private:
    string m_content;
};

struct Element
{
    string html;
};

class WebDocument : public IDocument
{
public:
    WebDocument();
    virtual ~WebDocument() { }

    virtual void Load( const string& filename );
    virtual void Save( const string& filename );
    virtual ofstream& Display( ofstream& out );
    virtual void GetInput();

    void AddElement( const string& element );

private:
    void OutputHeader( ofstream& out );
    void OutputFooter( ofstream& out );

    vector<Element> m_elements;
};

class CsvDocument : public IDocument
{
public:
    CsvDocument();
    virtual ~CsvDocument() { }

    virtual void Load( const string& filename );
    virtual void Save( const string& filename );
    virtual ofstream& Display( ofstream& out );
    virtual void GetInput();

    void AddRow( const string& row );

private:
    vector<string> m_rows;
};

#endif
