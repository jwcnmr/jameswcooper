<<<<<<< HEAD
#pragma once
#include <wx/wx.h>
#include "wx/gdicmn.h"
#include "wx/log.h"
#include <armadillo>
#include <vector>

using std::vector;

class PaintWindow : public wxFrame {
private:
    int Width;
    int Height;
    int Asize;
  
    wxPoint* wavePoints;
    wxPoint* peakPoints;
    vector<double> waveData;
   // vec sinedata;
    wxPanel* panel;
    wxPanel* botPanel;
    wxButton* ftButton;
    bool ftFlag;
    
public:
    PaintWindow(const wxString& title, size_t asize, int width, int height);
    void OnPaint(wxPaintEvent& event);
    void setWaves(wxPoint* waves);
    void setPeaks(wxPoint* peaks);
    void OnClick(wxCommandEvent& event);
    void setDataVector(vector<double> sw);
};
=======
#pragma once
#include <wx/wx.h>
#include "wx/gdicmn.h"
#include "wx/log.h"
#include <armadillo>
#include <vector>

using std::vector;

class PaintWindow : public wxFrame {
private:
    int Width;
    int Height;
    int Asize;
  
    wxPoint* wavePoints;
    wxPoint* peakPoints;
    vector<double> waveData;
   // vec sinedata;
    wxPanel* panel;
    wxPanel* botPanel;
    wxButton* ftButton;
    bool ftFlag;
    
public:
    PaintWindow(const wxString& title, size_t asize, int width, int height);
    void OnPaint(wxPaintEvent& event);
    void setWaves(wxPoint* waves);
    void setPeaks(wxPoint* peaks);
    void OnClick(wxCommandEvent& event);
    void setDataVector(vector<double> sw);
};
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
