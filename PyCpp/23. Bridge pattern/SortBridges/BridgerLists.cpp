//Program to dispay data in two formats using the Bridge pattern

#include "baseincludes.h"
#include "VisList.h"
#include "SortLbVisList.h"
#include "ListBridge.h"
#include "SortGrdVisList.h"
#include "GridBridge.h"


//application starts here
class BridgerApp : public wxApp
{
public:
    virtual bool OnInit();
};


//This is the over all frame, which contains 2 panels
class BridgerFrame : public wxFrame
{
    const int WIDTH = 500;  //arbitrary size
    const int HEIGHT = 300;

    LbVisList* leftList;        //a listbox
    GrdVisList* rightList;      //a grid display

    wxBoxSizer* leftSzr;         //left panel sizer
    wxBoxSizer* rightSzr;         //right panel sizer

    ListBridge* lbridge;        //bridge to list from data
    GridBridge* rbridge;        //bridge to grid from data
    Products* prod;             //the Products class golds the data
   

public:
    BridgerFrame(const wxString& title);
   
};

IMPLEMENT_APP(BridgerApp)

bool BridgerApp::OnInit()
{
    //create the Frame here
    BridgerFrame* gframe = new BridgerFrame(wxT("Simple Bridge"));
    gframe->Show(true);
    return true;
}

//frame constructor
BridgerFrame::BridgerFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition)
{
    SetBackgroundColour(0xefefef);
    SetSize(WIDTH, HEIGHT);         //set window size

    wxBoxSizer* studSzr = new wxBoxSizer(wxHORIZONTAL);
    SetSizer(studSzr);

    //left panel contains the listbox
    wxPanel* leftPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition,
        wxSize(200, 250), wxRAISED_BORDER);

   //right panel will contain the grid
       wxPanel* rightPanel = new wxPanel(this, wxID_ANY, wxPoint(0, 0),
        wxSize(300, 250), wxRAISED_BORDER);

    studSzr->Add(leftPanel);

    leftSzr = new wxBoxSizer(wxHORIZONTAL);
    rightSzr = new wxBoxSizer(wxVERTICAL);
    leftPanel->SetSizer(leftSzr);

    leftSzr->AddSpacer(10);

    //create the listbox
    leftList = new LbVisList(leftPanel, wxSize(150, 160));
    leftSzr->Add(leftList);

    //create right hand grid
    rightList = new GrdVisList(rightPanel, wxSize(350, 160));
    rightSzr->Add(rightList);   
    studSzr->Add(rightPanel);

    //create the products class and read in the data
    prod = new Products("products.txt");
    
    //create left bridge
    lbridge = new ListBridge(leftList);
    lbridge->addData(prod);
    //create right bridge
    rbridge = new GridBridge(rightList);
    rbridge->addData(prod);

}





