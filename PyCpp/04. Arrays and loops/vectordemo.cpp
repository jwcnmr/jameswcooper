#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <double> vdata;  //create a new vecto

    vdata.push_back(42.0);  //add values to the end
    vdata.push_back(63.2);
    vdata.push_back(77.1);

    //better to reserve some space in advance:
    // but then you should not use push_back
    //but put data into the spaces you have already reserved
    //using the index number
    vector <double> vdata2(6);  //create a new vector
    vdata2[0]=42.0;  //add values to the end
    vdata2[1]=63.2;
    vdata2[2]=77.1;
    cout<< "capacity="<< vdata2.capacity() <<endl;
    cout <<"size="<<vdata2.size() <<" max="<<vdata2.max_size()<<endl;

    for (int i=0; i< vdata2.size(); i++) {
        cout << i <<" "<<vdata2[i]<<endl;
    }
    cout <<endl;
    vector <double> vdat1 {42.0, 63.2, 77.1};
    //print out 2nd and 3rd values
    cout <<vdata[1] << " " << vdata[2]<<endl;
    double last = vdata.back(); //get the last value
    cout <<last <<endl;
    vdata.pop_back();           //remove last element

    for (double a: vdata) {
        cout << a <<" ";
    }
    cout << endl;
    //get the iterator pointing to the first element
    vector<double>::iterator it = vdata.begin();
    //and insert a new value just before it
    it = vdata.insert ( it , 200.4 );

    for (double a: vdata) {
        cout << a <<" ";
    }

    return 0;
}
