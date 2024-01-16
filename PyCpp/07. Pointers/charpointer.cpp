#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main() {

    char greeting[6] ={"hello"}; //C string is an array
    cout <<greeting<<endl;
    char* p1 = greeting;
    for (int i=0; i<5; i++) {
        cout <<*p1++;
    }
    cout <<endl;
    //a standard C string
   const char* p ="here is a string";
   cout << p <<endl;        //print out C string
   //print out a character at a time
   for (size_t i =0; i<strlen(p); i++){
       cout << p[i];
   }
   cout <<endl;

   //a C++ string
   string cpstring("This is a C++ string");
   cout <<cpstring <<endl;
   //get the C string within
   const char* cpp = cpstring.c_str();

   for (size_t i=0; i< strlen(cpp); i++) {
      cout << cpp[i];
   }
   cout <<endl;

   //get a mutable version of that C-string
   char* vcpp = cpstring.data();
   vcpp[2] = 'u';       //change one character
   cout <<vcpp <<endl;

   return 0;
}
