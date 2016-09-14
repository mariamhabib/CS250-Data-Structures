#ifndef IMAGECOWPROGRAM_HPP
#define IMAGECOWPROGRAM_HPP

#include "Document.hpp"

#include "DocList.hpp"

#include <vector>
using namespace std;

class ImageCowProgram
{
    public:
    ~ImageCowProgram();

    void Start();

    private:
    void MainMenu();
    void AddDocument();
    void RemoveDocument();
    void DisplayDocumentList();
    void OpenDocument();

    //void FreeDocument( int index ); // Not needed anymore

    void DisplayNumberedListOfDocuments();

    void AddTextDocument( const string& filename, const string& friendlyName );
    void AddWebDocument( const string& filename, const string& friendlyName );
    void AddCSVDocument( const string& filename, const string& friendlyName );

//    vector<IDocument*> m_docList;
    DocList m_docList;
};

#endif
