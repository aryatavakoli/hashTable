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

    maxSize = (2 * c);

    while(!isPrime(maxSize))
    {
        maxSize++;
    }

    cout << "Prime Number Greater than 2n = " << maxSize << endl;
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
    auto  degree = key.length();
    auto val = 37;
    uint32_t ASCII = 96;
    uint32_t result;

    for (int i = 0; i < key.length(); i++)
    {
        coefficients[i] = tolower(key[i]) - ASCII;
    }

//    cout << "Coeffiecent of = " << key <<" ";
//    for (int j = 0; j < degree ; ++j)
//    {
//        cout << coefficients[j] << ",";
//    }

    //cout << "\n";
    result = hornerRule(coefficients, degree , val);

    //cout << "Hash Value of " << key << " = " << result << endl;

    return result;
}

size_t HashTable::compress(uint32_t hash) const
{
    if (size() == 0)
    {
        return hash % 1;
    }
    return hash % hashSize;
}


bool isString(const Val &v)
{
    for (int i = 0; i < v.length() ; ++i)
    {
        if(!isalpha(v[i]))
        {
            return false;
        }
    }
    return true;
}

bool HashTable::search(const Val &v)
{
    if(!isString(v))
    {
        throw invalid_argument("Invalid string");
    }

    size_t index = compress(hash(v));
    auto result = array[index].search(v);

    return result;
}

bool HashTable::add(const Val &v)
{
    if(!isString(v))
    {
        throw invalid_argument("Invalid string");
    }

    if(search(v))
    {
        throw invalid_argument("String Not Found");
    }

    size_t index = compress(hash(v));
    array[index].add(v);

    hashSize++;
    underlyingCapcity++;

    return true;
}

bool HashTable::remove(const Val &v)
{
    if(!isString(v))
    {
        throw invalid_argument("Invalid string");
    }

    if(search(v))
    {
        throw invalid_argument("String Not Found");
    }

    if(size() == 0)
    {
        throw invalid_argument("Hash is empty");
    }

    if(capacity() == 0)
    {
        throw invalid_argument("Hash is empty");
    }

    size_t index = compress(hash(v));
    array[index].remove(v);

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

