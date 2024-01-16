
#include <wx/wx.h>
#include "wx/gdicmn.h"
#include "wx/log.h"
#include "PaintWindow.h"
#include <armadillo>

using arma::vec;
using arma::fft;
using arma::cx_vec;

PaintWindow::PaintWindow(const wxString& title, size_t asize, int width, int height)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition) {
    ftFlag = false;
    Width = width; Height = height; Asize = asize;
      
    panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(Width, Height - 100));
    wxBoxSizer* vbs = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(vbs);
    vbs->Add(panel);

    botPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(Width, 100));
    wxBoxSizer* hbs = new wxBoxSizer(wxHORIZONTAL);
    botPanel->SetSizer(hbs);

    ftButton = new wxButton(botPanel, wxID_ANY, wxT("FFT"));
    ftButton->Bind(wxEVT_BUTTON, &PaintWindow::OnClick, this);
    hbs->AddSpacer(400);
    hbs->Add(ftButton, 0, wxALIGN_CENTER, 10);
    vbs->Add(botPanel);

    SetBackgroundColour(0xefefef);
    SetSize(Width, Height);
    panel->Bind(wxEVT_PAINT, &PaintWindow::OnPaint, this);
    this->Centre();
}
void PaintWindow::setWaves(wxPoint* waves) {
    wavePoints = waves;
}
void PaintWindow::setPeaks(wxPoint* peaks) {
    peakPoints = peaks;
   
}
void PaintWindow::setDataVector(vector<double> sw) {
    waveData = sw;

}
void PaintWindow::OnClick(wxCommandEvent& event) {
    vec sinedata = vec(waveData);
    cx_vec spec = fft(sinedata);
    ftFlag = true;
    size_t peakCount = spec.size()/2;
    peakPoints = new wxPoint[peakCount];
    double yval = 0;
    for (size_t x = 0; x < peakCount; x++) {
        yval = spec[x].real()/50;
        int y = Height - int(yval/2)- 300;        // wave height
        int xcoord = int(x * (float(Width) / float(peakCount))) + 10; // x coord
        wxPoint pt(xcoord, y);   //display array
        peakPoints[x] = pt;
    }
    ftFlag = true;
    Refresh();

}
void PaintWindow::OnPaint(wxPaintEvent& event) {
    wxPaintDC dc(panel);
    if (ftFlag) {
        
        dc.DrawLines(Asize/2, peakPoints);
    }
    else
        dc.DrawLines(Asize, wavePoints);
}
