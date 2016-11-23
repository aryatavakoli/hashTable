#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <memory>
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::unique_ptr;
using std::make_unique;
using std::move;
using std::cout;
using std::endl;
using std::vector;

using Val = string;

//Node Class
class Node {
    friend class LinkedList;
public:
    Node(const Node& n) : str{n.str}, next{}
    {
    }
    Node(Val v, std::unique_ptr<Node> n) : str{v}, next{move(n)}
    {
    }
    Node(Val v) : str{v}
    {
    }

private:
    Val str = 0;
    unique_ptr<Node> next = nullptr;
};

//LinkedList Class
class LinkedList {
    friend class HashTable;
public:
    LinkedList() {}

    LinkedList(const LinkedList &ll);

    ~LinkedList();

    LinkedList &operator=(const LinkedList &ll);

    bool add(const Val &v);

    bool remove(const Val &v);

    bool search(const Val &v) const;

    bool empty() const;

    vector<Val> get() const;

    void printList() const;

private:
    //size of linked list
    int listSize = 0;

    //Unique Pointer to Head
    unique_ptr<Node> head;
};

#endif
