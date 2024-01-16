#include "baseincludes.h"
#include "Mediator.h"
#include "DButton.h"


//application starts here
class StudentApp : public wxApp
{
public:
    virtual bool OnInit();
};


//This is the over all frame, which contains 3 panels
class StudentFrame : public wxFrame
{
    const int WIDTH = 550;  //arbitrary size
    const int HEIGHT = 300;

    wxListBox* studentList;
    wxListBox* advList;
   
    wxBoxSizer* pnlSzr;
    wxBoxSizer* midSzr;
    wxBoxSizer* advSzr;
    Mediator* med;
    MoveButton* mvb;
    RestoreButton* rsb;
    ClearButton* clrb;

public:
    StudentFrame(const wxString& title);
    void onClick(wxCommandEvent& event);
    void advClick(wxCommandEvent& event);
    wxPoint* pt;
};

IMPLEMENT_APP(StudentApp)

bool StudentApp::OnInit()
{
    //create the Frame here
    StudentFrame* gframe = new StudentFrame(wxT("Garden planner"));
    gframe->Show(true);
    return true;
}

//frame constructor
StudentFrame::StudentFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition)
{
    SetBackgroundColour(0xefefef);
    SetSize(WIDTH, HEIGHT);         //set window size

    wxBoxSizer* studSzr = new wxBoxSizer(wxHORIZONTAL);
    SetSizer(studSzr);

    //left panel contains the listbox
    wxPanel* leftPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition,
        wxSize(200, 250), wxRAISED_BORDER);

    wxPanel* midPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition,
        wxSize(125, 250), wxRAISED_BORDER);

    //right panel is derived from wxPanel so we can add an onPaint method
    wxPanel* rightPanel = new wxPanel(this, wxID_ANY, wxPoint(0, 0),
        wxSize(200, 250), wxRAISED_BORDER);

    studSzr->Add(leftPanel);

    pnlSzr = new wxBoxSizer(wxHORIZONTAL);
    advSzr = new wxBoxSizer(wxVERTICAL);
    leftPanel->SetSizer(pnlSzr);

    pnlSzr->AddSpacer(10);

    //create the listbox
    studentList = new wxListBox(leftPanel, wxID_ANY,
        wxDefaultPosition, wxSize(150, 160), 0, NULL, 0L,
        wxDefaultValidator, wxString(""));
    pnlSzr->Add(studentList);

    //create right hand listbox
    advList = new wxListBox(rightPanel, wxID_ANY,
        wxDefaultPosition, wxSize(150, 160), 0, NULL, 0L,
        wxDefaultValidator, wxString(""));
    advSzr->Add(advList);


    //connect the click event to the listboxes
    studentList->Bind(wxEVT_LISTBOX, &StudentFrame::onClick, this);
   
    //middle panel

    studSzr->Add(midPanel);
    studSzr->Add(rightPanel);
    advList->Bind(wxEVT_LISTBOX, &StudentFrame::advClick, this);

    //The middle panel contains 2 buttons
    wxBoxSizer* bxs = new wxBoxSizer(wxVERTICAL);
    midPanel->SetSizer(bxs);
    med = new Mediator(this, studentList, advList);
    bxs->AddSpacer(10);
    mvb = new MoveButton(midPanel, med);
    bxs->Add(mvb);
    bxs->AddSpacer(20);
    rsb = new RestoreButton(midPanel, med);
    bxs->Add(rsb);
    bxs->AddSpacer(20);
    clrb = new ClearButton(midPanel, med);
    bxs->Add(clrb);
    med->setButtons(mvb, rsb, clrb);

   
}
//tells the Mediator the listbox has been clicked
void StudentFrame::onClick(wxCommandEvent& event) {
    med->onListClick(event);
}
//The right hand  listbox has been clicked.
void StudentFrame::advClick(wxCommandEvent& event) {
    med->advListClick(event);
}





