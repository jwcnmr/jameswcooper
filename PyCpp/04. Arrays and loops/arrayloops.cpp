#include <iostream>
using namespace std;

int main() {
   int x[] = {2, 4, 5, 7, 9};   //create an array of integers
   std::cout << x[3] <<" "<< std::size(x)<<endl;           //print out 4th member

   int y[10];
   int aval = 12;
   // fill array with numbers starting at 12
   // and incrementing by 2
   for (int i=0; i<10; i++){
       y[i] = aval;
       aval += 2;
   }
   //print out final array
   for (int i=0; i<10; i++) {
       cout << y[i] <<" ";
   }
   cout <<endl;
   for (int z: y) {
       cout << z <<" ";
   }
   cout << endl;
   double tval[10];
   int i=0;
   for(double tmp =42; tmp < 142; tmp +=10.0) {
       tval[i++] = tmp;
   }
   for (double a: tval) {
       cout << a <<" ";
   }
   cout << endl;

   i = 0;
   while (i < size(tval)) {
       cout << tval[i++] << " ";
   }
   cout <<endl;
   i=0;
   do {
       cout << tval[i++] << " ";
   } while (i < size(tval));
cout <<endl;
//Two dimensional arrays
double coords[3][4] {
    {3.4, 3.4, 5.5, 2.1},
    {2.2, 1.9, 1.2, 1.0},
    {2.7, 3.4, 4.4, 4.7}
};
for (int j=0; j<3; j++) {
    cout<< coords[j][2] << " ";
}
   return 0;
}
