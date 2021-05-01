#ifndef HASH
#define HASH

#include "Element.h"
#include <iostream>
#include <string>
#include <list>

class HashTable
{
public:
    int buckets; //number of buckets/nodes
    list<Element> *main_array; //empty array where buckets will be placed

	HashTable();
	HashTable(int buckets); //creator
	int hashfunction(string id); // creates address for given id
    void insertElement(Element &element); //add obj to address
    int search_id(string id); // find info corresponding to id
    friend ostream& operator<< (ostream &os, const HashTable &m); //print hash
};



#endif // HASH

