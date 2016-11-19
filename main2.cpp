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

void hashTest()
{
    cout << "Creating HashTable ht1..."<< endl;
    HashTable ht1 {9};
    ht1.add("bat"); // add
    ht1.add("cat");
    ht1.add("rhinoceros");
    ht1.add("ocelot");
    ht1.add("elephant");
    ht1.add("hippopotamus");
    ht1.add("giraffe");
    ht1.add("camel");
    ht1.add("lion");
    ht1.add("panther");
    ht1.add("bear");
    ht1.add("wolf");


    cout<<endl;
    cout << "Size of HashTable = " << ht1.size() << endl;
    cout<<endl;

    cout << "Size of Underlying Capicty = " << ht1.capacity() << endl;
    cout<<endl;

    ht1.printTable("Table before Remove");

    cout << "Removing bat..."<< endl;
    ht1.remove("bat"); // remove
    cout<<endl;
    cout << "Removing cat..."<< endl;
    ht1.remove("cat");
    cout<<endl;
    cout << "Removing hippopotamus..."<< endl;
    ht1.remove("hippopotamus");
    cout << "profit?..."<< endl;

    ht1.printTable("Table After Remove");

}



int main()
{
    linkedListTest();
    hashTest();
    return 0;
}