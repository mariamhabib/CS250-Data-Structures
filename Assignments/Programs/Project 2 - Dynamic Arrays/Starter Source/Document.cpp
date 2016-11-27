#include "Document.hpp"

#include <iostream>
#include <fstream>
using namespace std;

TextDocument::TextDocument()
{
    m_type = "text";
}

void TextDocument::Load( const string& filename )
{
    cout << "Text document load" << endl;
}

void TextDocument::Save( const string& filename )
{
    cout << "Text document save at " << filename << endl;
    m_filename = filename;

    ofstream output( filename.c_str() );
    output << m_content;
    output.close();
}

ofstream& TextDocument::Display( ofstream& out )
{
    out << m_content;
    return out;
}

void TextDocument::SetContent( const string& content )
{
    m_content = content;
}

void TextDocument::GetInput()
{
    cout << "Enter content for the document, or QUIT to quit:" << endl;

    string text = "";
    cin.ignore();
    getline( cin, text );

    while ( text != "QUIT" )
    {
        m_content += text + "\n";
        getline( cin, text );
    }
}



WebDocument::WebDocument()
{
    m_type = "web";
}

void WebDocument::Load( const string& filename )
{
    cout << "Web document load" << endl;
}

void WebDocument::Save( const string& filename )
{
    cout << "Web document save at " << filename << endl;
    m_filename = filename;

    ofstream output( filename.c_str() );

    OutputHeader( output );

    for ( int i = 0; i < m_elements.size(); i++ )
    {
        output << m_elements[i].html << endl;
    }

    OutputFooter( output );

    output.close();
}

ofstream& WebDocument::Display( ofstream& out )
{
    for ( int i = 0; i < m_elements.size(); i++ )
    {
        out << m_elements[i].html << endl;
    }
    return out;
}

void WebDocument::AddElement( const string& element )
{
    Element e;
    e.html = element;
    m_elements.push_back( e );
}

void WebDocument::OutputHeader( ofstream& out )
{
    out << "<!DOCTYPE html>" << endl;
    out << "<html><head><title>My Page</title></head><body>" << endl;
}

void WebDocument::OutputFooter( ofstream& out )
{
    out << "</body></html>" << endl;
}

void WebDocument::GetInput()
{
    cout << "Enter an html element for the document, or QUIT to quit:" << endl;

    string text = "";
    cin.ignore();
    getline( cin, text );

    while ( text != "QUIT" )
    {
        Element e;
        e.html = text;

        m_elements.push_back( e );

        getline( cin, text );
    }
}




CsvDocument::CsvDocument()
{
    m_type = "csv";
}

void CsvDocument::Load( const string& filename )
{
    cout << "Csv document load" << endl;
}

void CsvDocument::Save( const string& filename )
{
    cout << "Csv document save at " << filename << endl;
    m_filename = filename;

    ofstream output( filename.c_str() );

    for ( int i = 0; i < m_rows.size(); i++ )
    {
        output << m_rows[i] << endl;
    }
    output.close();
}

void CsvDocument::AddRow( const string& row )
{
    m_rows.push_back( row );
}

ofstream& CsvDocument::Display( ofstream& out )
{
    for ( int i = 0; i < m_rows.size(); i++ )
    {
        out << m_rows[i] << endl;;
    }
    return out;
}

void CsvDocument::GetInput()
{
    cout << "Enter each row for the spreadsheet, or QUIT to quit:" << endl;

    string text = "";
    cin.ignore();
    getline( cin, text );

    while ( text != "QUIT" )
    {
        m_rows.push_back( text );
        getline( cin, text );
    }
}
