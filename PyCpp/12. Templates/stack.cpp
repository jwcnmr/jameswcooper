#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

//a stack class using values of your choice
template <class T>
class Stack {
private:
    vector<T> values;   //type specified here
public:
    void push(T val){   //push onto stacj
        values.push_back(val);
    }
    //pop a value from the stack
    T pop() {
        if (hasValues()) {
            //save last value
            T popval = values[values.size()-1];
            values.pop_back();  //and rmeove it
            return popval;
        }
        else
            return NULL;
    }
    //return true if there are any values left
    bool hasValues() {
        return ! values.empty();
    }
};

//demonstrate vector using template
int main() {
    Stack<int> stack;   //create stack
    stack.push(20); //push on 3 values
    stack.push(42);
    stack.push(91);

    //pop off one at a time and print them
    do {
        cout <<stack.pop()<<endl;
    } while (stack.hasValues());

    return 0;
}
