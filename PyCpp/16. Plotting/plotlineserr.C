#include "TF1.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TRootCanvas.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TGFont.h"
#include "TPad.h"

// Draw a simple x-y plot
void plotlineserr() {
    auto c = new TCanvas("c1", "Demo example");
    auto gr = new TGraphErrors("plotdataerr1.txt"); //read in data file
    gr->SetTitle("Demo error data");	//title on the plot		
    gr->SetMarkerStyle(1);	//filled circle marker
    gr->Draw("APL");		//plot axis and lines
    c->Print("demo.pdf");	//save PDF of plot
    return 0;
