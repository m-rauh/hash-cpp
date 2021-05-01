#include "include/Hash.h"
#include "include/Element.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


const int SIZE = 20000;
const int HASH_SIZE = 5000;
const int COLLUMNS = 3;
const int SEARCHS = 3;
using namespace std;

int main(int argc, char **argv){

	// import data file
    string matrix[SIZE][COLLUMNS];

    fstream file;
    file.open("example_data.csv");
    string line;
    int i = 0;

    while (getline( file, line,'\n')){
        istringstream templine(line);
        string data;
        int j = 0;
        while (getline(templine, data,'\t') && j < COLLUMNS) { //get data
            matrix[i][j] = data; // save data
            j++;
        }
        i++;
    }
    file.close();
    const int DATA_SIZE = i;

	// put data in obj
	Element elements[DATA_SIZE];

	for (i = 1; i < DATA_SIZE; i++) { //first line is heading
        Element e(matrix[i][0], matrix[i][1], matrix[i][2]); //create element
        elements[i-1] = e;
	}

	// reorganize into HashTable
	HashTable my_hash(HASH_SIZE); // twice as buckets as itens
	for (i = 0; i < DATA_SIZE - 1; i++){
        my_hash.insertElement(elements[i]);
	}
	// DONE HASH

    //cout << my_hash; // for printing

    /* Searching n random elements in a normal array and hash array */
    string search_elements[5];

    cout << "\n" << "Searching Elements: " << endl;
    for (i = 0 ; i < SEARCHS; i++){
        search_elements[i] = elements[rand() % DATA_SIZE].id;
        cout << search_elements[i];
        if (i != SEARCHS - 1) cout << ", ";
        else cout << ";";
    }

	// retrieve info from array - time
    clock_t begin_time = clock();

    cout << endl << endl;
    cout << "Array search" << endl;
    cout << "------------------" << endl;
    int operations = 0;
    int all = 0;
	for (i = 0; i < DATA_SIZE; i++){
        for (int j =0 ; j < SEARCHS ; j++ ){
            if(search_elements[j] == elements[i].id){
                cout << "Element info: " << elements[i] << endl;
                all ++;
                break;
            }
            operations ++;
        }
        if (all == SEARCHS) break;
        operations ++;
	}
    cout << endl;
	cout << "Number of operations: " << operations << endl;
    cout << "Time Elapsed: " << float(clock() - begin_time)/CLOCKS_PER_SEC;
    cout << endl;

	// retrieve info from Hash - time
    begin_time = clock();

    cout << endl;
    cout << "Hash search" << endl;
    cout << "------------------" << endl;
    operations = 0;
    for (i = 0; i < SEARCHS; i++){
    operations += my_hash.search_id(search_elements[i]);
    }

    cout << endl;
	cout << "Number of operations: " << operations << endl;
    cout << "Time Elapsed: " << float(clock() - begin_time)/CLOCKS_PER_SEC;
	cout << endl << endl<< endl;


	return 0;
}
