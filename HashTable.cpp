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
    auto degree = key.length();
    auto val = 37;
    unsigned int ASCII = 96;
    uint32_t result;

    for (int i = 0; i < key.length(); i++)
    {
        coefficients[i] = tolower(key[i]) - ASCII;
    }
    cout << endl;
    cout << "Coeffiecent of " << key <<" ";
    for (int j = 0; j < degree ; ++j)
    {
        cout << coefficients[j] << ",";
    }

    cout << "\n";
    result = hornerRule(coefficients, degree , val);

    cout << "Hash Value of " << key << " = " << result << endl;

    return result;
}

size_t HashTable::compress(uint32_t hash) const
{
    if(size() == 0)
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
    cout << "Index to remove " << v << " = " << index << endl;
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
        throw invalid_argument("String Already Exists");
    }

    if(size() == 0 || capacity() == 0)
    {
        hashSize++;
    }

    size_t index = compress(hash(v));
    cout<<endl;
    cout << "Index to add " << v << " = " << index << endl;
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

    if(!search(v))
    {
        throw invalid_argument("String Does Not Exist");
    }

    if(size() == 0 || capacity() == 0)
    {
        throw invalid_argument("Hash is empty");
    }

    size_t index = compress(hash(v));
    cout<<endl;
    cout << "Index to remove " << v << " = " << index << endl;
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

float HashTable::loadFactor() const
{
    float maxSize2 = maxSize;
    float hashSize2 = underlyingCapcity;
    return (hashSize2 / maxSize2 ) * 100;

}

// Display the contents of the Hash Table
void HashTable::printTable(const string &label) const
{
    cout << label << endl;
    for ( int i = 0; i < hashSize; i++ )
    {
        cout << "index " << i << ": ";
        array[i].printList();
    }
}

