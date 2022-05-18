#include <iostream>
#include "CircularBuffer.h"
#include "Iterator.h"
using namespace std;

int main()
{
    int n = 0;
    CircularBuffer<int> q(4);
    q.display();

    for (int i = 1; i <= 4; i++) {
        try { q.push(i); }
        catch (const char* msg) { std::cout << msg << std::endl; }
    }
    q.display();


    for (int i = 5; i <= 7; i++) {
        try { q.pop(); }
        catch (const char* msg) { std::cout << msg << std::endl; }
        q.display();
        try { q.push(i); }
        catch (const char* msg) { std::cout << msg << std::endl; }
        q.display();
    }


    try { q.push(9); }
    catch (const char* msg) { std::cout << msg << std::endl; }
    cout << "\ntried to add 9:" << endl;
    q.display();

    cout << "head element: " << q.getHeadElement() << endl;

    q.makeEmpty();
    cout << "\nnow q is empty" << endl;
    q.display();

    try { q.push(1); }
    catch (const char* msg) { std::cout << msg << std::endl; }
    try { q.push(2); }
    catch (const char* msg) { std::cout << msg << std::endl; }
    try { q.push(3); }
    catch (const char* msg) { std::cout << msg << std::endl; }
    try { q.push(4); }
    catch (const char* msg) { std::cout << msg << std::endl; }
    q.display();


    Iterator<int> p(q);
    cout << "\nIterator:" << endl;
    for (p.start(); !p.finish(); p.next()) {
        cout << p.getValue() << endl;
    }

    q.display();
}