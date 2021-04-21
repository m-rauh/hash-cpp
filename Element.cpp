#include "Hash.h"
#include <iostream>
#include <string>
#include <list>


//Element
Element::Element()
{
}

Element::Element(string id, string info1, string info2) //constructor
{
    this->id = id;
    this->info1 = info1;
    this->info2 = info2;
}

ostream& operator<< (ostream &os, Element &m) // cout << operator
{
    os << m.id << '\t' << m.info1 << '\t' << m.info2;
    return os;
}

