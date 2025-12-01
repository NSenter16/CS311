/**
 * This file tests the implementation of Stack data structure
 * 
 */
#include <cassert>
#include "stack.h"
#include <iostream>


using namespace std;

int main(int argc, char* argv[]) {
    cout << "Create a new stack" << endl;
    Stack <int> stack;
    if (stack.size() != 0) {
    cerr << "Error: stack is not empty!" << endl;
    }
    cout << "push 1,  stack = " << endl;
    stack.push(1);
    stack.displayAll();

    // Test push function
    for(int i = 0; i < 10; i++) {
        stack.push(i);
        cout << "push " << i << ", stack = ";
        stack.displayAll();
    }

    // Test pop function
    for (int i = 0; i < 5; i++) {
        int x;
        stack.pop(x);
        cout << "pop top val = " << x << ", stack = ";
        stack.displayAll();
    }

    // Test copy constructor 
    cout << "Test copy constructor, s2 as a copy of stack" << endl;
    Stack<int> s2 (stack);
    cout << "s2 size = " << s2.size() << endl;
    cout << "s2 = ";
    s2.displayAll();
    if (s2.size() != stack.size()) {
    cerr << "Error: Stack sizes do not match!" << endl;
    }
    if (s2.top() != stack.top()) {
    cerr << "Error: Stack top elements do not match!" << endl;
    }

    cout << "Push to stack does not affect s2" << endl;
    stack.push(10);    // push to stack doesn't change s2
    cout << "After push, stack size = " << stack.size() << endl;
    cout << "stack = ";
    stack.displayAll();
    cout << "s2 = ";
    s2.displayAll();
    if (s2.size() == stack.size()) {
    cerr << "Error: Expected stacks to have different sizes, but they are equal." << endl;
    }
    if (s2.top() == stack.top()) {
    cerr << "Error: Expected different top elements, but both are " << s2.top() << endl;
    }

    // Test assignment operator = 
    cout << "Test assignment operator =, s2 = stack" << endl;
    s2 = stack;
    cout << "After assignment, s2 size = " << s2.size() << endl;
    cout << "s2 = ";
    s2.displayAll();
    if (s2.size() != stack.size()) {
    cerr << "Error: Stack sizes do not match. "
              << "s2 size = " << s2.size() 
              << ", stack size = " << stack.size() << endl;
    }
    if (s2.top() != stack.top()) {
    cerr << "Error: Top elements do not match. "
              << "s2 top = " << s2.top() 
              << ", stack top = " << stack.top() << endl;
    }

    
}
