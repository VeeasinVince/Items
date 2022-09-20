//Made by Khush Naidu
#pragma once
/* ==============================================================================================
                                     <DESCRIPTION>

 The class "CarTable" is home to the functions that revolve around unit 3: Hash. It is where the functions of insert, search and delete are created for the hash table. It also calculates the statistics of the hash table and also saves hash table data to a file. It also has the provision for a rehash incase the load factor exceeds 75%.

 CarTable.h is the header file where the constructor as well as function definitions are declared.
 =================================================================================================
 */

#include "Car.h"
#include "CarLinkedList.h"
#include <iostream>
struct HashArray
{
    int noItem = 0;//number of items in the linked list (each bucket)
    CarLinkedList* node = nullptr; //node for the linked list
    Car *CarData = nullptr; //data pointer
    int exists = 0;
};

class CarTable
{
private:
    HashArray* hashtableptr ; //hash table that will be dynamically allocated
    int hashSize;//hash size
    int count;//number of elements inside
    int noCols;//total number of collisions
    int longestlinkedlist;
    int numberoflongest;


public:
    CarTable(int n) //constructor that dynamically allocated hash table and initializes variables
    {
        count = 0;
        hashSize = n;
        hashtableptr = new HashArray[hashSize];
        noCols = 0;
        longestlinkedlist=0;
        numberoflongest=0;
    }
    ~CarTable() //destructor
    {
        delete [] hashtableptr;
    }

    //FUNCTION DEFINITIONS:

    int getCount() const    { return count; }
    int getSize() const { return hashSize; }
    double getLoadFactor() const {return 100.0 * count / hashSize; }
    bool isEmpty() const    { return count == 0; }
    bool isFull()  const    { return count == hashSize; }
    int _hash(string key);
    void insert(Car* itemIn);
    bool search( Car *&itemOut, string key);
    void remove(Car* itemOut, string target);
    int getLongestlinkedlist() const;
    int getNumberoflongest() const;
    int getNoCols(){return noCols;}
    void findstats();
    void Savehashtofile(std::ofstream &file);
    void rehash();
    bool isPrime(int n);
    void resizeinsert(HashArray *point,Car *target);

};




