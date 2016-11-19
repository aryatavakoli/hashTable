#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <cstdint>
#include <stdexcept>
#include <cctype>
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <cstddef>

#include "LinkedList.h"

using std::string;
using std::unique_ptr;
using std::make_unique;
using std::move;
using std::cout;
using std::endl;
using std::vector;
using std::invalid_argument;
using std::uint32_t;
using std::size_t;
using std::tolower;
using std::isalpha;
using std::size_t;

class HashTable {
public:
    HashTable();

    HashTable(int c);

    HashTable(const HashTable &ht);

    ~HashTable() = default;

    HashTable &operator=(const HashTable &ht);

    bool add(const Val &v);

    bool remove(const Val &v);

    bool search(const Val &v);

    int size() const;

    int capacity() const;

    vector<Val> keys() const;

    float loadFactor() const;

    HashTable setunion(const HashTable &ht) const;

    static uint32_t hash(const Val &key);

    size_t compress(uint32_t hash) const;

    constexpr static int defaultCapacity{101};

    void printTable(const string &label) const;

private:
    // Add your member variables and any private member functions here
    bool isPrime( int n );
    int hashSize = 0;
    int underlyingCapcity = 0;
    int maxSize = {defaultCapacity};
    unique_ptr<LinkedList[]> array;
};

#endif
