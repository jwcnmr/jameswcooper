#include <sciplot/sciplot.hpp>
#include <armadillo>
#include <vector>

using namespace sciplot;
//using namespace arma;
using std::vector;
using arma::vec;
using arma::polyfit;



int main(int argc, char** argv)
{
    Vec x = { 7,8,9,10,11,12,13,14,15,16,17 };
    Vec y = { 32,35,29,34,30,24,32,24,23,28,21 };

    // Create a Plot object
    Plot2D plot;

    // This disables the deletion of the created gnuplot script and data file.
    plot.autoclean(false);

    // Plot the data
    plot.drawCurveWithPoints(x, y).label("bees");

    // now compute the line fitting the points
    vec arx(size(x)); vec ary(size(y));
    for (int i = 0; i < x.size(); i++) {
        arx[i] = x[i];
        ary[i] = y[i];
    }
    vec p = arma::polyfit(arx, ary, 1);
    //m is the slope and b is the intercept
    double m = p[0];
    double b = p[1];

    //compute the two y values 
    //for the first and last x points
    Vec xa = { 0, 0 };
    Vec ya = { 0, 0 };

    double y0 = m * x[0] + b;
    double ylast = m * x[size(x) - 1] + b;
    //the two x points
    xa[0] = x[0];
    xa[1] = x[size(x) - 1];
    //the two y points
    ya[0] = y0;
    ya[1] = ylast;
    //draw fitted straight line on graph
    plot.drawCurveWithPoints(xa, ya).label("fit");

    // Create figure to hold plot
    Figure fig = { {plot} };
    // Create canvas to hold figure
    Canvas canvas = { {fig} };
    canvas.size(800, 500);

    // Show the plot in a pop-up window
    canvas.show();

    // Save the plot to a PDF file
    canvas.save("example-missing-data.pdf");
}
