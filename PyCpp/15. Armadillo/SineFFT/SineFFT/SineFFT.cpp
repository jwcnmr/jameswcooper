<<<<<<< HEAD
#include <wx/wx.h>
#include "wx/gdicmn.h"
#include "wx/log.h"
#include <vector>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <armadillo>
#include "Mediator.h"
#include "PaintWindow.h"

using std::vector;
using std::ofstream;
using std::ios;
using std::string;
using std::endl;
using std::to_string;
//using namespace arma;

class Builder : public wxApp
{
public:
    const size_t ASIZE = 16384;
    virtual bool OnInit();
    void OnClick(wxCommandEvent& event);
    
    Mediator* medsf;
};

IMPLEMENT_APP(Builder)

bool Builder::OnInit() {
    
    medsf = new Mediator(ASIZE);
    PaintWindow* paintWin = new PaintWindow(wxT("Line plot"), ASIZE, medsf->width(), medsf->height());
    medsf->setPaintWin(paintWin);
    medsf->createWaves();
    paintWin->Show(true);
    
    return true;
}
void Builder::OnClick(wxCommandEvent& event) { 
    medsf->ftClick();
}





=======
#include <wx/wx.h>
#include "wx/gdicmn.h"
#include "wx/log.h"
#include <vector>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <armadillo>
#include "Mediator.h"
#include "PaintWindow.h"

using std::vector;
using std::ofstream;
using std::ios;
using std::string;
using std::endl;
using std::to_string;
//using namespace arma;

class Builder : public wxApp
{
public:
    const size_t ASIZE = 16384;
    virtual bool OnInit();
    void OnClick(wxCommandEvent& event);
    
    Mediator* medsf;
};

IMPLEMENT_APP(Builder)

bool Builder::OnInit() {
    
    medsf = new Mediator(ASIZE);
    PaintWindow* paintWin = new PaintWindow(wxT("Line plot"), ASIZE, medsf->width(), medsf->height());
    medsf->setPaintWin(paintWin);
    medsf->createWaves();
    paintWin->Show(true);
    
    return true;
}
void Builder::OnClick(wxCommandEvent& event) { 
    medsf->ftClick();
}





>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
