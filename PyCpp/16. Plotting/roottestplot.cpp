<<<<<<< HEAD
#include "TF1.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TRootCanvas.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TGFont.h"
#include "TPad.h"

int main(int argc, char** argv) {
	TApplication app("app", &argc, argv);
	
	//the bee data
	double x[11] = { 2007,2008,2009,2010,2011,2012,2013,2014,2015,2016,2017 };
	double y[11] = { 32, 35, 29, 34, 30, 24, 32, 24, 23, 28, 21 };
	
	//create bee population die-off graph
	TGraph* gr1 = new TGraph(11, x, y);
	
	gr1->SetLineColor(kBlue + 1);
	gr1->SetTitle("Bee population die-off");
	gr1->Draw("AL*");
	
	// create the line that fits the data
	double xfit[2] = { 2007,2017 };
	double yfit[2] = { 33, 22.9 };
	TGraph* gr2 = new TGraph(2, xfit, yfit);
	gr2->SetLineColor(kOrange );
	gr2->SetMarkerStyle(21);
	gr2->SetMarkerColor(kOrange );
	gr2->Draw("LP");
	
	// create the legend
	TLegend* legend = new TLegend(0.2, 0.1, "", "brNDC");
	legend->AddEntry(gr1, "bee data");
	legend->AddEntry(gr2, "bee fit");
	legend->Draw();
	
	app.Run();	//run the plotting window
	return 0;
}
=======
#include "TF1.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TRootCanvas.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TGFont.h"
#include "TPad.h"

int main(int argc, char** argv) {
	TApplication app("app", &argc, argv);
	
	//the bee data
	double x[11] = { 2007,2008,2009,2010,2011,2012,2013,2014,2015,2016,2017 };
	double y[11] = { 32, 35, 29, 34, 30, 24, 32, 24, 23, 28, 21 };
	
	//create bee population die-off graph
	TGraph* gr1 = new TGraph(11, x, y);
	
	gr1->SetLineColor(kBlue + 1);
	gr1->SetTitle("Bee population die-off");
	gr1->Draw("AL*");
	
	// create the line that fits the data
	double xfit[2] = { 2007,2017 };
	double yfit[2] = { 33, 22.9 };
	TGraph* gr2 = new TGraph(2, xfit, yfit);
	gr2->SetLineColor(kOrange );
	gr2->SetMarkerStyle(21);
	gr2->SetMarkerColor(kOrange );
	gr2->Draw("LP");
	
	// create the legend
	TLegend* legend = new TLegend(0.2, 0.1, "", "brNDC");
	legend->AddEntry(gr1, "bee data");
	legend->AddEntry(gr2, "bee fit");
	legend->Draw();
	
	app.Run();	//run the plotting window
	return 0;
}
>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31
