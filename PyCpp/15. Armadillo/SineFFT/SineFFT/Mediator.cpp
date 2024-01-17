<<<<<<< HEAD
#include "Mediator.h"
#include <wx/wx.h>
#include "wx/gdicmn.h"
#include "wx/log.h"

using arma::fft;
using arma::cx_vec;

Mediator::Mediator(size_t A_size) {
    ASize = A_size;
    Width = WIDTH;
    Height = HEIGHT;
    wavePoints = new wxPoint[ASize];
   
    waveData.resize(ASize);
    size_t sz = waveData.size();
    ftFlag = false;
    
    
}
void Mediator::ftClick() {
   
}
void Mediator::setPaintWin(PaintWindow* pw) {
    paintWin = pw;
}

wxPoint* Mediator::getWaves() {
    return wavePoints;
}
wxPoint* Mediator::getPeaks() {
    return peakPoints;
}
int Mediator::width() {
    return Width;
}
int Mediator::height() {
    return Height;
}
void Mediator::createWaves() {
    for (size_t x = 0; x < ASize; x++) {
        double yval = (cos(x / 100.0));// +cos(x / 5.0)); // add cosine waves
        //exponential decay
        yval = exp((float(ASize - x)*2) / float(ASize)) * yval;
        //size_t sz2 = waveData.size();
        waveData[x] = yval;         //save data array
        //Then, we scale these values to the window size and add to the array:
        int y = int(yval * 40) + 300;        // wave height
        int xcoord = int(x * (float(Width) / float(ASize))) + 10; // x coord
        wxPoint pt(xcoord, y);   //display array
        wavePoints[x] = pt;
    }
    paintWin->setWaves(wavePoints);
    paintWin->setDataVector(waveData);
=======
#include "Mediator.h"
#include <wx/wx.h>
#include "wx/gdicmn.h"
#include "wx/log.h"

using arma::fft;
using arma::cx_vec;

Mediator::Mediator(size_t A_size) {
    ASize = A_size;
    Width = WIDTH;
    Height = HEIGHT;
    wavePoints = new wxPoint[ASize];
   
    waveData.resize(ASize);
    size_t sz = waveData.size();
    ftFlag = false;
    
    
}
void Mediator::ftClick() {
   
}
void Mediator::setPaintWin(PaintWindow* pw) {
    paintWin = pw;
}

wxPoint* Mediator::getWaves() {
    return wavePoints;
}
wxPoint* Mediator::getPeaks() {
    return peakPoints;
}
int Mediator::width() {
    return Width;
}
int Mediator::height() {
    return Height;
}
void Mediator::createWaves() {
    for (size_t x = 0; x < ASize; x++) {
        double yval = (cos(x / 100.0));// +cos(x / 5.0)); // add cosine waves
        //exponential decay
        yval = exp((float(ASize - x)*2) / float(ASize)) * yval;
        //size_t sz2 = waveData.size();
        waveData[x] = yval;         //save data array
        //Then, we scale these values to the window size and add to the array:
        int y = int(yval * 40) + 300;        // wave height
        int xcoord = int(x * (float(Width) / float(ASize))) + 10; // x coord
        wxPoint pt(xcoord, y);   //display array
        wavePoints[x] = pt;
    }
    paintWin->setWaves(wavePoints);
    paintWin->setDataVector(waveData);
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
}