//Made by Khush Naidu

/* ==============================================================================================
                                    <DESCRIPTION>

CarTable.cpp is where the hashtable is dynamically allocated and functions such as insert, search, delete,
 save to file, statistics and rehash are implemented.
=================================================================================================
*/

#pragma once
#include "CarTable.h"
#include <iostream>
using namespace std;


//=====================================================
//               HASH FUNCTION
//=====================================================


int CarTable::_hash(string key)
{
    int sum = 0;
    for (int i = 0; key[i]; i++)
        sum += key[i];
    return sum % hashSize;
}

//=====================================================
//               INSERT FUNCTION
//=====================================================

void CarTable::insert(Car* itemIn)
{
    int key;
    key = _hash(itemIn->getEngineNumber()); //hashing to store key value
    int sno=getLoadFactor();
    if(getLoadFactor()>75.0)
    {
       rehash();
    }
    if(hashtableptr[key].exists == 0)
    {
        hashtableptr[key].CarData = itemIn; //storing car data in hash table bucket
        count++;
        hashtableptr[key].exists = 1;
        hashtableptr[key].noItem++; //number of items in bucket increased
    }
    else //in case of collision
    {
        noCols++;
        hashtableptr[key].node->insertNode(itemIn,hashtableptr[key].node); //insert item in linked list
        if (hashtableptr[key].noItem >= 1)
        {
            hashtableptr[key].noItem++;
        }
        count++;
    }
}

//=====================================================
//               DELETE FUNCTION
//=====================================================

void CarTable::remove(Car* itemOut,string target)
{
    int key;
    Car *empty = new Car;
    key =_hash(target);
    if(hashtableptr[key].CarData->getEngineNumber() == target) //delete if found in hash table
    {
        hashtableptr[key].CarData = empty;
        hashtableptr[key].noItem--; //decreasing length of bucket
        count--;
        hashtableptr[key].exists--;
    }
    else
    {
        bool returned = hashtableptr[key].node->deleteNode(target, itemOut,hashtableptr[key].node); //delete if found in bucket linked list
        count--;
        hashtableptr[key].noItem--; //decreasing length of bucket
    }
}

//=====================================================
//               SEARCH FUNCTION
//=====================================================

bool CarTable::search(Car* &itemOut, string key)
{
    int num;
    num = _hash(key);
    if(hashtableptr[num].CarData->getEngineNumber() == key) //if key is found in hash table without collision
    {
        itemOut = hashtableptr[num].CarData; //stores car info
        return true;
    }
    else //else, if there is a colliosion
    {
        bool found = hashtableptr[num].node->searchNode(key,itemOut,hashtableptr[num].node); //search for car in linked list
        return found;
    }
    return false;
}

//=====================================================
//           GETTER FUNCTIONS FOR STATS
//=====================================================

int CarTable::getLongestlinkedlist() const //returns the longest linked list formed due to collision
{
    return longestlinkedlist;
}

int CarTable::getNumberoflongest() const // returns number of longest linked lists
{
    return numberoflongest;
}

//=====================================================
//               STATISTICS FUNCTION
//=====================================================

void CarTable::findstats() {
    longestlinkedlist = 0;
    numberoflongest = 0;
    for (int i = 0; i < hashSize; i++)
    {
        if (hashtableptr[i].noItem != 0)
        {
            if (longestlinkedlist < hashtableptr[i].noItem)
            {
                longestlinkedlist = hashtableptr[i].noItem; // new longest linked list is stored
                numberoflongest = 0;

                if (longestlinkedlist == hashtableptr[i].noItem) //if length is same as longest
                {
                    numberoflongest++; //increase the number of longest linked lists
                }
            }
        }
    }
    longestlinkedlist--;

}

//========================================================
//               SAVE TO FILE FUNCTION
//========================================================

void CarTable:: Savehashtofile(std::ofstream &fin)
{
    for (int i = 0; i < hashSize; i++)
    {
        if (hashtableptr[i].noItem != 0)
        {
            if(hashtableptr[i].exists == 1)
            {
                fin<<hashtableptr[i].CarData;
            }
            if(hashtableptr[i].noItem > 1)
            {
                hashtableptr[i].node->Savehashtofile(fin,hashtableptr[i].node);
            }
        }
    }
}

//========================================================
//                   REHASH FUNCTION
//========================================================

void CarTable::rehash()
{
    noCols=0;
    findstats();
    int max=longestlinkedlist;
    int oldsize=hashSize;
    hashSize = hashSize * 2; //double the size of the previous hash table
    while(!isPrime(hashSize)) //increase the new  size until it is a prime number
    {
        hashSize++;
    }
    HashArray *newhasharray=new HashArray[hashSize];
    for(int i=0;i<oldsize;i++)
    {
        if(hashtableptr[i].noItem != 0) {

            if (hashtableptr[i].exists == 1) {
                resizeinsert(newhasharray, hashtableptr[i].CarData);
            }
            if(hashtableptr[i].noItem>1)
            {
                newhasharray->node->collisionrehash(newhasharray->node,hashtableptr->node);
            }
        }
    }

    delete [] hashtableptr;
    hashtableptr=newhasharray;

}

//========================================================
//         FUNCTION TO CHECK IF NUMBER IS PRIME
//========================================================

bool CarTable::isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
//===========================================================
//         Insert function which helps to rehash
//===========================================================

void CarTable:: resizeinsert(HashArray *point,Car *target)
{
    int key;
    key = _hash(target->getEngineNumber()); //hashing to store key value
    if(point[key].exists == 0)
    {
        point[key].CarData = target; //storing car data in hash table bucket
        point[key].exists = 1;
        point[key].noItem++; //number of items in bucket increased
    }
    else //in case of collision
    {
        noCols++;
        point[key].node->collisionrehash(point->node,hashtableptr->node); //insert item in linked list
        if (point[key].noItem >= 1)
        {
            point[key].noItem++;
        }
    }
}

