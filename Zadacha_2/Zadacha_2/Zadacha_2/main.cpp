#include "Queue.h"
#include "Iterator.h"
#include <iostream>

int main() {
    Queue q(5);
    

    try { q.push(1); }
    catch (const char* msg) { std::cout << msg << std::endl; }
    try { q.push(2); }
    catch (const char* msg) { std::cout << msg << std::endl; }
    try { q.push(3); }
    catch (const char* msg) { std::cout << msg << std::endl; }
    try { q.push(4); }
    catch (const char* msg) { std::cout << msg << std::endl; }
    try { q.push(5); }
    catch (const char* msg) { std::cout << msg << std::endl; }


    cout << "q: ";
    try { q.display(); }
    catch (const char* msg) { std::cout << msg << std::endl; }

    cout << "\n\ntrying to add 6 in q: ";
    try { q.push(6); }
    catch (const char* msg) { std::cout << msg << std::endl; }

    cout << "q: ";
    try { q.display(); }
    catch (const char* msg) { std::cout << msg << std::endl; }
    

    try { q.pop(); }
    catch (const char* msg) { std::cout << msg << std::endl; }

    cout << endl << "\ndeleted element. q: " << endl;
    try { q.display(); }
    catch (const char* msg) { std::cout << msg << std::endl; }

    try { q.push(7); }
    catch (const char* msg) { std::cout << msg << std::endl; }

    cout << endl << "\nadded 7. q: " << endl;
    try { q.display(); }
    catch (const char* msg) { std::cout << msg << std::endl; }
    cout << endl << "\nhead element: " << q.getHeadElement() << endl;

    cout << "\n\ntrying to add 8 in q: ";
    try { q.push(8); }
    catch (const char* msg) { std::cout << msg << std::endl; }

    cout << "\nnow q is empty: ";
    try { q.makeEmpty(); }
    catch (const char* msg) { std::cout << msg << std::endl; }
    try { q.display(); }
    catch (const char* msg) { std::cout << msg << std::endl; }

    cout << "\nsize of q: " << q.size() << endl;


    cout << "q: ";
    try { q.display(); }
    catch (const char* msg) { std::cout << msg << std::endl; }



    Queue q_copy(5);

    try { q_copy.push(1); }
    catch (const char* msg) { std::cout << msg << std::endl; }
    try { q_copy.push(2); }
    catch (const char* msg) { std::cout << msg << std::endl; }
    try { q_copy.push(3); }
    catch (const char* msg) { std::cout << msg << std::endl; }
    try { q_copy.push(4); }
    catch (const char* msg) { std::cout << msg << std::endl; }
    try { q_copy.push(5); }
    catch (const char* msg) { std::cout << msg << std::endl; }

    cout << "q_copy: ";
    try { q_copy.display(); }
    catch (const char* msg) { std::cout << msg << std::endl; }

    Iterator i(q_copy);

    cout << "\n\n" << i.start() << endl;

    while (!i.finish())
    {
        i.next();
        cout << "\n" << i.getValue() << endl;
    }

    //for (i.start(); !i.finish(); i.next()) {
        //cout << "\n" << i.getValue() << endl;
    //}

    return 0;
}