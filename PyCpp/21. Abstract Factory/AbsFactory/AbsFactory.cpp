#include <wx/wx.h>
#include <wx/wxprec.h>
#include <wx/gdicmn.h>
#include <wx/gbsizer.h>
#include <wx/listbox.h>
#include <wx/button.h>
#include <vector>
#include "Garden.h"

using std::vector;
using std::string;

//The Mediator mediates listbox and button click events
class Mediator {
private:
    vector<Garden*> gardens;
    wxListBox* listbox;
    wxFrame* frame;
    Garden* currentGarden;

    bool show_sun = false;
    bool show_shade = false;
    bool show_border = false;
public:
    Mediator(wxFrame* gframe, wxListBox* glist) {
        listbox = glist;
        frame = gframe;
        //create a list of gardens in a vector
        gardens = vector <Garden*>();
       
        gardens.push_back(new AnnualGarden());
        gardens.push_back(new VeggieGarden());
        gardens.push_back(new PerennialGarden());

        //and put their names in the listbox
        for (int i = 0; i < gardens.size(); i++) {
            Garden* g = gardens[i];
            listbox->Append(g->getName());
        }
    }
    //list box click comes here. It sets the current garden
    void onListClick(wxCommandEvent& event) {
        int index = listbox->GetSelection();
        currentGarden = gardens[index];
        show_shade = false;
        show_sun = false;
        show_border = false;
        frame->Refresh();
    }
    //get a pointer to the current garden
    Garden* getCurrentGarden() {
        return currentGarden;
    }
    //clicks on each of 3 buttons
    //make the plant names visible in that region
    //by setting a flag check for on the paint event
    void sunClick() {
        show_sun = true;
        frame->Refresh();
    }
    void shadeClick() {
        show_shade = true;
        frame->Refresh();
    }
    void borderClick() {
        show_border = true;
        frame->Refresh();
    }
    bool showShade() {
        return show_shade;
    }
    bool showSun() {
        return show_sun;
    }
    bool showBorder() {
        return show_border;
    }
};

/// <summary>
/// abstract base command button class
/// </summary>
class DButton : public wxButton {

    // The Mediator class actually executes the code for all button clicks
protected:
    Mediator* med;

public:
    DButton(wxPanel* panel, int id, const std::string label, Mediator* med) :
        wxButton(panel, id, wxString::wxString(label), wxDefaultPosition,
            wxDefaultSize)
    {
        this->med = med;
        Bind(wxEVT_BUTTON, &DButton::comd, this);
    }

    //abstract method to be completed in derived classes 
    virtual void comd(wxCommandEvent& event) = 0;
};

//clicks on each button go to the Mediator 
// which sets a flag to make that plant name visible
class SunButton :public DButton {
public:
    SunButton(wxPanel* panel, Mediator* med) :
        DButton(panel, wxID_ANY, "Sunny", med) {
    }
    void comd(wxCommandEvent& event) {
        med->sunClick();
    }
};
class ShadeButton :public DButton {
public:
    ShadeButton(wxPanel* panel, Mediator* med) :
        DButton(panel, wxID_ANY, "Shade", med) {

    }
    void comd(wxCommandEvent& event) {
        med->shadeClick();
    }
};
class BorderButton :public DButton {
public:
    BorderButton(wxPanel* panel, Mediator* med) :
        DButton(panel, wxID_ANY, "Border", med) {

    }
    void comd(wxCommandEvent& event) {
        med->borderClick();
    }
};

//application starts here
class GardenApp : public wxApp
{
public:
    virtual bool OnInit();
};

//derived panel so we can create paint event
class PaintPanel : public wxPanel {
private:
    Mediator* med;
public:
    int width, height;
    PaintPanel(wxWindow* parent,
        wxWindowID 	id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL,
        const wxString& name = wxPanelNameStr);// :wxPanel(parent, id, pos, size, style) {}
    void OnPaint(wxPaintEvent& event);  //the paint event handler
    void setMediator(Mediator* med);
};

//This is the over all frame, which contains 3 panels
class GardenFrame : public wxFrame
{
    const int WIDTH = 450;  //arbitrary size
    const int HEIGHT = 350;

    wxListBox* gardenList;
    wxBoxSizer* pnlSzr;
    Mediator* med;

public:
    GardenFrame(const wxString& title);
    void onClick(wxCommandEvent& event);
    wxPoint* pt;
};

IMPLEMENT_APP(GardenApp)

bool GardenApp::OnInit()
{
    //create the Frame here
    GardenFrame* gframe = new GardenFrame(wxT("Garden planner"));
    gframe->Show(true);
    return true;
}

//frame constructor
GardenFrame::GardenFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition)
{
    SetBackgroundColour(0xefefef);
    SetSize(WIDTH, HEIGHT);         //set window size

    wxGridBagSizer* gbs = new wxGridBagSizer(6, 8);
    SetSizer(gbs);

    //left panel contains the listbox
    wxPanel* leftPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition,
        wxSize(200, 250), wxRAISED_BORDER);
    
    //right panel is derived from wxPanel so we can add an onPaint method
    PaintPanel* rightPanel = new PaintPanel(this, wxID_ANY, wxPoint(0, 0),
        wxSize(200, 250), wxRAISED_BORDER);
    
    gbs->Add(leftPanel, wxGBPosition(0, 0), wxGBSpan(3, 3));

    pnlSzr = new wxBoxSizer(wxHORIZONTAL);
    leftPanel->SetSizer(pnlSzr);

    pnlSzr->AddSpacer(10);

    //create the listbox
    gardenList = new wxListBox(leftPanel, wxID_ANY,
        wxDefaultPosition, wxSize(150, 160), 0, NULL, 0L,
        wxDefaultValidator, wxString(""));
    pnlSzr->Add(gardenList);

    //connect the click event to the listbox
    gardenList->Bind(wxEVT_LISTBOX, &GardenFrame::onClick, this);

    //right panel is where you draw the garden
    gbs->Add(rightPanel, wxGBPosition(0, 3), wxGBSpan(4, 5));
    
    //The bottom panel contains 3 buttons
    wxPanel* botPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition,
        wxSize(WIDTH, 100), wxRAISED_BORDER);
    gbs->Add(botPanel, wxGBPosition(4, 0), wxGBSpan(2, 8));
    wxBoxSizer* bxs = new wxBoxSizer(wxHORIZONTAL);
    botPanel->SetSizer(bxs);
    med = new Mediator(this, gardenList);
    bxs->AddSpacer(50);
    bxs->Add(new SunButton(botPanel, med));
    bxs->AddSpacer(50);
    bxs->Add(new ShadeButton(botPanel, med));
    bxs->AddSpacer(50);
    bxs->Add(new BorderButton(botPanel, med));

    //tell the right panel where the Mediato is.
    rightPanel->setMediator(med);

}
//tells the Mediator the listbox has been clicked
void GardenFrame::onClick(wxCommandEvent& event) {
    med->onListClick(event);
}
void PaintPanel::setMediator(Mediator* md) {
    med = md;
}

//PaintPanel is the right panel where the painting occurs
void PaintPanel::OnPaint(wxPaintEvent& event) {
    wxPaintDC dc(this);

    dc.SetBrush(wxColor(200, 200, 200));      //fill color=gray      
    dc.DrawCircle(wxPoint(40, 40), 40);       //draw the shade circle  

    //paint the names of the plants if their flag is set in the Mediator
    Garden* gd = med->getCurrentGarden();
    //coordinates obtained by trial and error
    if (med->showSun()) dc.DrawText(wxString(gd->sunny()->name()), wxPoint(100, 120));  //sunny
    if (med->showShade()) dc.DrawText(wxString(gd->shade()->name()), wxPoint(15, 35));
    if (med->showBorder())dc.DrawText(wxString(gd->border()->name()), wxPoint(65, 200));
}
//connect the paint event to the paint panel
PaintPanel::PaintPanel(wxWindow* parent,
    wxWindowID 	id, const wxPoint& pos,
    const wxSize& size, long style,
    const wxString& name) :wxPanel(parent, id, pos, size, style) {
    Bind(wxEVT_PAINT, &PaintPanel::OnPaint, this);
}


