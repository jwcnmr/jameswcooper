#pragma once
#include "PaintWindow.h"
#include <vector>
#include <armadillo>

using std::vector;
using arma::vec;
//using namespace arma;


class Mediator {
private:
    PaintWindow* paintWin;
    const int WIDTH = 1000;
    const int HEIGHT = 600;
    wxPoint* wavePoints;
    wxPoint* peakPoints;
    size_t ASize;
   
    vector<double> waveData;
    vec sinedata;
    bool ftFlag;
    int Width;
    int Height;
public:
    int width();
    int height();
    Mediator(size_t Asize);
    void ftClick();
    void createWaves();
    void setPaintWin(PaintWindow* pw);
   
    wxPoint* getWaves();
    wxPoint* getPeaks(); 
    
};