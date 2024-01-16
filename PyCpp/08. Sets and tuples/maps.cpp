#include <iostream>
#include <string>
#include <map>
#include <iterator>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::pair;
using std::iterator;

int main() {
    map<string, string> dbanswer;
    dbanswer.insert(pair<string, string>("frname", "Sally"));
    dbanswer.insert(pair<string, string>("lname", "Splurge"));
    dbanswer.insert(pair<string, string>("score", "98"));
    string keyScore = "score";
    auto it = dbanswer.find(keyScore);
    if (it != dbanswer.end()){
        cout << dbanswer["score"] << endl;
    }
    for (auto it = dbanswer.begin(); it != dbanswer.end(); ++it) {
        cout << it->first <<" "<<it->second <<endl;
    }
    // or manually
    string keys[] = {"frname", "lname", "score"};
    for(int i=0; i<3; i++){
        cout <<keys[i] << ": " << dbanswer[keys[i]] << endl;
    }
    map<string,string> states;
    states["AR"] = "Arkansas";
    states["AK"] = "Alaska";
    states["CA"] = "California";
    states["CT"] = "Connecticut";
    states["MO"] = "Missouri";
    states["KS"] = "Kansas";

    cout << "CT: "<<states["CT"]<<endl;

    return 0;
}
