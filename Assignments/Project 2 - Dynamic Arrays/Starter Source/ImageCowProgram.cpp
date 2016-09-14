#include "ImageCowProgram.hpp"

#include "utils/Menu.hpp"


ImageCowProgram::~ImageCowProgram()
{
    // Free memory
    for ( unsigned int i = 0; i < m_docList.size(); i++ )
    {
        FreeDocument( i );
    }
}

void ImageCowProgram::FreeDocument( int index )
{
    if ( m_docList[index] != nullptr )
    {
        delete m_docList[index];
        m_docList[index] = nullptr;
    }
}

void ImageCowProgram::Start()
{
    MainMenu();
}

void ImageCowProgram::MainMenu()
{
    bool done = false;
    while ( !done )
    {
        dal::Menu::ClearScreen();
        dal::Menu::Header( "ImageCow Document Management System" );
        int choice = dal::Menu::ShowIntMenuWithPrompt({
            "Add Document",
            "Remove Document",
            "Display Documents List",
            "Open Document",
            "Quit"
        });

        if ( choice == 1 )
        {
            AddDocument();
        }
        else if ( choice == 2 )
        {
            RemoveDocument();
        }
        else if ( choice == 3 )
        {
            DisplayDocumentList();
        }
        else if ( choice == 4 )
        {
            OpenDocument();
        }
        else if ( choice == 5 )
        {
            done = true;
        }
    }
}

void ImageCowProgram::AddDocument()
{
    dal::Menu::ClearScreen();
    dal::Menu::Header( "ImageCow - Add Document" );

    string filename;
    string friendlyName;

    cout << "Document Filename: ";
    cin >> filename;
    cin.ignore();

    cout << "Friendly Name: ";
    getline( cin, friendlyName );

    int choice = dal::Menu::ShowIntMenuWithPrompt({
            "Text Document",
            "Web Document",
            "CSV Document"
        });

    if ( choice == 1 )
    {
        AddTextDocument( filename, friendlyName );
    }
    else if ( choice == 2 )
    {
        AddWebDocument( filename, friendlyName );
    }
    else if ( choice == 3 )
    {
        AddCSVDocument( filename, friendlyName );
    }
}

void ImageCowProgram::RemoveDocument()
{
    dal::Menu::ClearScreen();
    dal::Menu::Header( "ImageCow - Remove Document" );

    DisplayNumberedListOfDocuments();

    cout << endl << "Remove which document?" << endl;
    cout << "INDEX: ";
    int index;
    cin >> index;

    if ( index >= 0 && index < m_docList.size() )
    {
        // Remove item at this index
        FreeDocument( index );
        m_docList.erase( m_docList.begin() + index );
    }

    cout << "Document removed" << endl;

    dal::Menu::Pause();
}

void ImageCowProgram::DisplayDocumentList()
{
    dal::Menu::ClearScreen();
    dal::Menu::Header( "ImageCow - Document List" );

    DisplayNumberedListOfDocuments();

    dal::Menu::Pause();
}

void ImageCowProgram::OpenDocument()
{
    dal::Menu::ClearScreen();
    dal::Menu::Header( "ImageCow - Open Document" );

    DisplayNumberedListOfDocuments();

    cout << endl << "Open which document?" << endl;
    cout << "INDEX: ";
    int index;
    cin >> index;

    if ( index >= 0 && index < m_docList.size() )
    {
        string command = "";

        if ( m_docList[index]->GetType() == "text" )
        {
            #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
            command = "notepad " + m_docList[index]->GetFilename();
            #else
            command = "nano " + m_docList[index]->GetFilename();
            #endif
        }
        else if ( m_docList[index]->GetType() == "web" )
        {
            #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
            command = "firefox " + m_docList[index]->GetFilename();
            #else
            command = "firefox " + m_docList[index]->GetFilename();
            #endif
        }
        else if ( m_docList[index]->GetType() == "csv" )
        {
            #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
            command = "excel " + m_docList[index]->GetFilename();
            #else
            command = "libreoffice " + m_docList[index]->GetFilename();
            #endif
        }

        system( command.c_str() );
    }
}

void ImageCowProgram::DisplayNumberedListOfDocuments()
{
    if ( m_docList.size() == 0 )
    {
        cout << "No documents available" << endl;
    }

    for ( unsigned int i = 0; i < m_docList.size(); i++ )
    {
        cout << i << ". \t" << m_docList[i]->GetFriendlyName() << endl;
    }
}

void ImageCowProgram::AddTextDocument( const string& filename, const string& friendlyName )
{
    TextDocument* newDoc = new TextDocument;
    newDoc->SetFriendlyName( friendlyName );

    cout << "Enter contents of document, or type SAVE to stop." << endl;
    string buffer;
    string content = "";
    while ( true )
    {
        cout << ">> ";
        getline( cin, buffer );

        if ( buffer == "SAVE" )
        {
            break;
        }

        content += buffer + "\n";
    }

    newDoc->SetContent( content );
    newDoc->Save( filename + ".txt" );

    m_docList.push_back( newDoc );

    cout << "Added" << endl;
    dal::Menu::Pause();
}

void ImageCowProgram::AddWebDocument( const string& filename, const string& friendlyName )
{
    WebDocument* newDoc = new WebDocument;
    newDoc->SetFriendlyName( friendlyName );

    cout << "Enter HTML markup, or type SAVE to stop." << endl;
    string buffer;
    while ( true )
    {
        cout << ">> ";
        getline( cin, buffer );

        if ( buffer == "SAVE" )
        {
            break;
        }

        newDoc->AddElement( buffer );
    }

    newDoc->Save( filename + ".html" );

    m_docList.push_back( newDoc );

    cout << "Added" << endl;
    dal::Menu::Pause();
}

void ImageCowProgram::AddCSVDocument( const string& filename, const string& friendlyName )
{
    CsvDocument* newDoc = new CsvDocument;
    newDoc->SetFriendlyName( friendlyName );

    cout << "Enter new row with columns separated by commas, or type SAVE to stop." << endl;
    string buffer;
    while ( true )
    {
        cout << ">> ";
        getline( cin, buffer );

        if ( buffer == "SAVE" )
        {
            break;
        }

        newDoc->AddRow( buffer );
    }

    newDoc->Save( filename + ".csv" );

    m_docList.push_back( newDoc );

    cout << "Added" << endl;
    dal::Menu::Pause();
}

