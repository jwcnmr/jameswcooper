#include <iostream>

using std::cout;
using std::endl;

double meanValue(const double x[], size_t size) {
    double sum = 0;
    for (size_t i=0; i <size; i++) {
        sum += x[i];
    }
    //x[0] = -1;  //read only variable
    return sum / size;  //calculate average
}

int main() {
    double xdata[] = {12,15.2,122,43};
    double meanval = meanValue(xdata, sizeof(xdata)/sizeof(xdata[0]));
    cout << "avg = "<<meanval<<endl;
    return 0;
}
