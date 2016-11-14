//
// Created by Arya on 2016-11-11.
//
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;
#include "HashTable.h"

void printVec(const vector<string>& vec) {
    for (auto s : vec)
        cout << s << " ";
    cout << endl;
}

void linkedListTest()
{
    auto ll = LinkedList{};

    cout << "Adding Hello" << endl;
    ll.add("Hello");
    ll.printList();

    cout << "Adding Bye" << endl;
    ll.add("Bye");
    ll.printList();

    cout << "Adding Bonjour" << endl;
    ll.add("Bonjour");
    ll.printList();

    cout << "Removing Bonjour" << endl;
    ll.remove("Bonjour");
    ll.printList();

//    cout << "Testing Copy Constructor" << endl;
//    auto ll2 = ll;
//    ll2.printList();
}

int main()
{
    linkedListTest();
    return 0;
}