#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <memory>
#include <string>
#include <vector>

using Val = std::string;

//Node Class
class Node {
    friend class LinkedList;
public:
    Node(const Node& n) : val{n.val}, next{}
    {
    }
    Node(int v, std::unique_ptr<Node> n) : val{v}, next{move(n)}
    {
    }
    Node(int v) : val{v}
    {
    }

private:
    int val = 0;
    std::unique_ptr<Node> next = nullptr;
};

//LinkedList Class
class LinkedList {
public:
    LinkedList() {}

    LinkedList(const LinkedList &ll);

    ~LinkedList();

    LinkedList &operator=(const LinkedList &ll);

    bool add(const Val &v);

    bool remove(const Val &v);

    bool search(const Val &v) const;

    bool empty() const;

    std::vector<Val> get() const;

    void printList() const;

private:
    //size of linked list
    int listSize = 0;

    //Unique Pointer to Head
    unique_ptr<Node> head;

    //Oberserving Pointer to tail
    Node * tail;
};

#endif
