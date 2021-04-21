#include "Hash.h"
#include "Element.h"
#include <iostream>
#include <string>
#include <list>


//HashTable
HashTable::HashTable()
{
    this->buckets = 1;
}

HashTable::HashTable(int buckets)
{
    this->buckets = buckets;
    main_array = new list<Element>[buckets];
}

int HashTable::hashfunction(string id)
{
    // create "unique" key for element

    int sum = 0;
    //int primes[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
    int distribution[12] = {1, 10, 100, 1000, 10000, 10000, 10000, 10000, 1000, 100, 10, 1};

    for (int i = 0; i < id.size(); i++)
    {
        sum += int(id[i])*distribution[i];
    }

    return sum%(this->buckets);
}

void HashTable::insertElement(Element &e)
{
    int position = hashfunction(e.id);
    main_array[position].push_back(e);
}

ostream& operator<< (ostream &os, HashTable &m) // cout << operator
{
	for (int i = 0; i < m.buckets; i++)
	{
        cout << i;
        for (auto e : m.main_array[i])
        {
            cout << " > " << e.id;
        }
        cout << endl;
	}
}

int HashTable::search_id(string id)
{
/* Search for the element using Hash
    Return number of operations*/

    int operations = 0;
    int position = this->hashfunction(id);
    operations ++;
    for (auto e : this->main_array[position])
        {
            if (e.id == id)
            {
            cout << "Element info: " << e << endl;
            break;
            }
            operations ++;
        }
    return operations;
}





