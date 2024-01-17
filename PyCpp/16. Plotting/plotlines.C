<<<<<<< HEAD
#include "TF1.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TRootCanvas.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TGFont.h"
#include "TPad.h"

// Draw a simple x-y plot
void plotlines() {
    auto c = new TCanvas("c1", "Demo example");
    auto gr = new TGraph("plotdata1.txt"); //read in data file
    gr->SetTitle("Demo data");	//title on the plot		
    gr->SetMarkerStyle(20);	//filled circle marker
    gr->Draw("APL");		//plot axis and lines
    c->Print("demo.pdf");	//save PDF of plot
    return 0;
=======
#include "TF1.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TRootCanvas.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TGFont.h"
#include "TPad.h"

// Draw a simple x-y plot
void plotlines() {
    auto c = new TCanvas("c1", "Demo example");
    auto gr = new TGraph("plotdata1.txt"); //read in data file
    gr->SetTitle("Demo data");	//title on the plot		
    gr->SetMarkerStyle(20);	//filled circle marker
    gr->Draw("APL");		//plot axis and lines
    c->Print("demo.pdf");	//save PDF of plot
    return 0;
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
}