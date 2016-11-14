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
    cout << "Creating ll1" << endl;
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

    cout << "Adding Hi" << endl;
    ll.add("Hi");
    ll.printList();

    cout << "Adding Welcome" << endl;
    ll.add("Welcome");
    ll.printList();


    cout << "Removing Hello" << endl;
    ll.remove("Hello");
    ll.printList();

    cout << "Testing Copy Constructor ll2" << endl;
    auto ll2 = ll;
    ll2.printList();

    cout << "Creating ll3" << endl;
    auto ll3 = LinkedList{};

    cout << "Adding Apple" << endl;
    ll3.add("Apple");
    ll3.printList();

    cout << "Adding Carrot" << endl;
    ll3.add("Carrot");
    ll3.printList();

    cout << "Adding Lettuce" << endl;
    ll3.add("Lettuce");
    ll3.printList();

    cout << "Testing Copy Assigment" << endl;
    ll2 = ll3;
    ll2.printList();
}

int main()
{
    linkedListTest();
    return 0;
}