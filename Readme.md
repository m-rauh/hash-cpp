## Hash implementation for C++

This is a simple hash. The sole porpouse of this program is learn and practice the basics of Hash Function and Hash Tables.
We used C++ only as a learning languague, we did not aim to any particular implementation.

### Implementation

We first imported a examaple database and transform it into an array with objects.
Then we recreated the array in a vector with linked list, as in:

```cpp
list<Element> *main_array;
main_array = new list<Element>[SIZE];
```

Then we used a hashfunction to determinated the position of a given object in the new array. This hash function is not optimal and it's supposed to be only an example :

```cpp
int HashTable::hashfunction(string id)
{
    // create "unique" key for element

    int sum = 0;
    int distribution[12] = {1, 10, 100, 1000, 10000, 10000, 10000, 10000, 1000, 100, 10, 1};

    for (int i = 0; i < id.size(); i++)
    {
        sum += int(id[i])*distribution[i];
    }

    return sum%(this->buckets); //where buckets is the size of your hash
}
```

Finally we inserted every item into the array:

```cpp
void HashTable::insertElement(Element &e)
{
    int position = hashfunction(e.id);
    main_array[position].push_back(e);
}
```

As we are using linked list and push_back to insert a new item, collision will be automaticly handled and place in the same position.

Later, if you want to get all of the itens stored in the same positions, just search using:

```cpp
int HashTable::search_id(string id)
{
/* Search for the element using Hash
    Return number of operations*/

    int operations = 0;
    int position = this->hashfunction(id);
    operations ++;
    for (Element e : this->main_array[position])
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
```

#### Hash.h 
``` cpp
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
  HashTable(int buckets); //create hash
  int hashfunction(string id); // creates address for given id
  void insertElement(Element &element); //add obj to address
  int search_id(string id); // find info corresponding to id
};

ostream& operator<< (ostream &os, HashTable &m); //print hash


#endif // HASH
```
