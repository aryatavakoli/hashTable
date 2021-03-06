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

HashTable::HashTable(const HashTable &ht)
{
    hashSize = ht.size();
    underlyingCapcity = ht.capacity();
    array = {make_unique<LinkedList[]>(underlyingCapcity)};
    auto all_keys = ht.keys();

    for (auto i = 0; i < all_keys.size() ; ++i)
    {
        add(all_keys[i]);
    }
}

HashTable& HashTable::operator=(const HashTable &ht)
{
    if(this == &ht)
    {
        return *this;
    }

    auto current_keys = keys();

    for (auto j = 0; j < current_keys.size(); j++)
    {
        remove(current_keys[j]);
    }

    auto new_keys = ht.keys();

    for (auto i = 0; i < new_keys.size() ; i++)
    {
        add(new_keys[i]);
    }

    return *this;
}

HashTable::HashTable()
{
    underlyingCapcity = defaultCapacity;
    array = {make_unique<LinkedList[]>(underlyingCapcity)};
    hashSize = 0;
}

HashTable::HashTable(int c)
{
    if(c == 0)
    {
        throw invalid_argument("Invalid number of Items ");
    }

    underlyingCapcity = 2 * c;

    while(!isPrime(underlyingCapcity))
    {
        underlyingCapcity++;
    }

    array = {make_unique<LinkedList[]>(underlyingCapcity)};
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
//    cout << endl;
//    cout << "Coeffiecent of " << key <<" ";
//    for (int j = 0; j < degree ; ++j)
//    {
//        cout << coefficients[j] << ",";
//    }

//    cout << "\n";
    result = hornerRule(coefficients, degree , val);

//    cout << "Hash Value of " << key << " = " << result << endl;

    return result;
}

size_t HashTable::compress(uint32_t hash) const
{
    //(a*hash) + b % N
//    srand(time(NULL));
//    int a = rand() %( underlyingCapcity-1) + 1; // must be > 0 and < N
//    int b = rand() % underlyingCapcity; // must be >= 0 and < N //correct

//    cout << "underlying Capcity  = " << underlyingCapcity << endl;
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;

    return hash % underlyingCapcity ;
}


bool isString(const Val &v)
{
    for (int i = 0; i < v.length() ; i++)
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
        return false;
    }


    size_t index = compress(hash(v));
//    cout<<endl;
//    cout << "Index to add " << v << " = " << index << endl;
    array[index].add(v);

    hashSize++;
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
        return false;
    }

    if(size() == 0 || capacity() == 0)
    {
        throw invalid_argument("Hash is empty");
    }

    size_t index = compress(hash(v));
//    cout<<endl;
//    cout << "Index to remove " << v << " = " << index << endl;
    array[index].remove(v);

    hashSize--;

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

vector<Val> HashTable::keys() const
{
    vector<Val> vec1;
    vector<Val> vec2;
    for (int index = 0; index < underlyingCapcity ; index++)
    {
        vec2 = array[index].get();

        for(auto val: vec2)
        {
            vec1.push_back(val);
        }

    }

    return vec1;
}

float HashTable::loadFactor() const
{
    float maxSize2 = underlyingCapcity;
    float hashSize2 = hashSize;
    return (hashSize2 / maxSize2 ) * 100;

}

HashTable HashTable::setunion(const HashTable &ht) const
{
    auto unionSet = HashTable{};

    auto keys1 = keys();
    auto keys2 = ht.keys();

    for (int i = 0; i < keys1.size(); i++)
    {
        unionSet.add(keys1[i]);
    }

    for (int j = 0; j < keys2.size(); ++j)
    {
        unionSet.add(keys2[j]);
    }

    return  unionSet;
}

// Display the contents of the Hash Table
void HashTable::printTable(const string &label) const
{
    cout << label << endl;
    for ( int i = 0; i < underlyingCapcity; i++ )
    {
        cout << "index " << i << ": ";
        array[i].printList();
    }
}

