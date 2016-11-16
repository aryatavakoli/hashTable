//
// Created by Arya on 2016-11-06.
//

#include "HashTable.h"

bool HashTable::isPrime( int n )
{
    if (n <= 1)
    {
        return false;
    }

    for ( int i = 2; i*i <=  n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

HashTable::HashTable()
{
    maxSize = defaultCapacity;
    array = {make_unique<LinkedList[]>(maxSize)};
    hashSize = 0;
    underlyingCapcity = 0;
}

HashTable::HashTable(int c)
{
    if(c == 0)
    {
        throw invalid_argument("Invalid number of Items ");
    }

    maxSize = (2 * c)+1;

    if(!isPrime(maxSize))
    {
        throw invalid_argument("Not a Prime Number ");
    }

    array = {make_unique<LinkedList[]>(maxSize)};
    hashSize = 0;
}

uint32_t hornerRule(uint32_t  poly[], auto degree , auto val) //val is going to be 37
{
    auto result = poly[0];  // Initialize result

    // Evaluate value of polynomial using Horner's method
    for (int i = 1; i < degree; i++)
    {
        result = result * val + poly[i];
    }

    return result;
}

uint32_t HashTable::hash(const Val &key)
{
    uint32_t coefficients[key.length()] = {};
    auto  degree = key.length() - 1;
    auto val = 37;
    unsigned int ASCII = 96;
    uint32_t result;

    for (int i = 1; i < key.length(); i++)
    {
        coefficients[i] = tolower(key[i]) - ASCII;
    }

    result = hornerRule(coefficients, degree , val);

    return result;
}

//bool HashTable::search(const Val &v)
//{
////    if(!isalpha(v))
////    {
////        throw invalid_argument("Invalid string");
////    }
//
//    int index = hash( v );
//    auto result = array[index].search(v);
//
//    return result;
//}

bool HashTable::add(const Val &v)
{
//    if(!isalpha(v))
//    {
//        throw invalid_argument("Invalid string");
//    }

//    if(search(v))
//    {
//        throw invalid_argument("String Not Found");
//    }

    int index = hash(v);
    array[index].add( v );

    hashSize++;
    underlyingCapcity++;

    return true;
}

bool HashTable::remove(const Val &v)
{
//    if(!isalpha(v))
//    {
//        throw invalid_argument("Invalid string");
//    }

//    if(search(v))
//    {
//        throw invalid_argument("String Not Found");
//    }

    if(size() == 0)
    {
        throw invalid_argument("Hash is empty");
    }

    if(capacity() == 0)
    {
        throw invalid_argument("Hash is empty");
    }

    int index = hash(v);
    array[index].remove( v );

    hashSize--;
    underlyingCapcity--;

    return true;

}

int HashTable::size() const
{
    return hashSize;
}

int HashTable::capacity() const
{
    return underlyingCapcity;
}

// Display the contents of the Hash Table
void HashTable::printTable(const string &label) const
{
    cout << label << endl;
    for ( int i = 0; i < hashSize; i++ )
    {
        cout << "Bucket " << i + 1 << ": ";
        array[i].printList();
    }
}

// Prints a histogram illustrating the Item distribution.
//void HashTable::printHistogram()
//{
//    cout << "\n\nHash Table Contains ";
//    cout << getNumberOfItems() << " Items total\n";
//    for ( int i = 0; i < length; i++ )
//    {
//        cout << i + 1 << ":\t";
//        for ( int j = 0; j < array[i].getLength(); j++ )
//            cout << " X";
//        cout << "\n";
//    }
//}

