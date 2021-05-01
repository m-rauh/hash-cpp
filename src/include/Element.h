#ifndef ELEMENT
#define ELEMENT

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Element
{
public:
    string id, info1, info2;
    Element();
    Element(string id, string info1, string info2);
};

ostream& operator<< (ostream &os, Element &m); //print element


#endif // ELEMENT
