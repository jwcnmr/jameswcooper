#include <sciplot/sciplot.hpp>
using namespace sciplot;

int main(int argc, char** argv) {
   // the bee plotting data
    Vec x = { 7,8,9,10,11,12,13,14,15,16,17 };
    Vec y = { 32,35,29,34,30,24,32,24,23,28,21 };

    // xy pairs descibing the fitted line
    Vec xa = { 7,17 };
    Vec ya = { 33, 22.94 };

    // Create a Plot object
    Plot2D plot;

    // This disables the deletion of the created gnuplot script and data file.
    plot.autoclean(false);

    // Plot the data and the fitted line
    plot.drawCurveWithPoints(x, y).label("bees");
    plot.drawCurveWithPoints(xa, ya).label("fit");

    // Create figure to hold plot
    Figure fig = { {plot} };

    // Create canvas to hold figure
    Canvas canvas = { {fig} };
    canvas.size(800, 500);

    // Show the plot in a pop-up window
    canvas.show();

    // Save the plot to a PDF file
    canvas.save("beedata.pdf");
}
