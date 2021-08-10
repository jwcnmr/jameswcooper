#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int sq(int a) {
    return a*a;
}
int main() {
    auto start = chrono::steady_clock::now();
    for (int i=0; i < 1000000; i++){
        int ara[] = {2,3,6,8,5,4};
        //vector <int>  v={0};
        int dest[6];
        int k = 0;
        for (auto a: ara) {
            //v.push_back(sq(a));
            dest[k++] = sq(a);
        }
    }
    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in milliseconds: "
    << chrono::duration_cast<chrono::milliseconds>(end - start).count()
    << " ms" << endl;
    return 0;
}
