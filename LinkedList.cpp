//
// Created by Arya on 2016-11-06.
//
#include "LinkedList.h"
LinkedList::LinkedList() 
{
	head = nullptr;
	length = 0;
}

LinkedList::LinkedList(const LinkedList &ll)
{
	head = nullptr;
    count = 0;
    //initialize all member variables
    Node * temp = ll.head.get();

    while(temp != nullptr)
    {
        // and add them using insert_back()
        add(temp->str);
        temp = temp->next.get();
    }
}

LinkedList::~LinkedList()
{
	Node * temp = ll.head.get();
	while (temp != nullptr)
    {
        remove(temp->str);
        temp = temp->next.get();
    }
}

LinkedList::LinkedList &operator=(const LinkedList &ll)
{
	Node * temp = ll.head.get();
	while (temp != nullptr)
    {
        remove(temp->str);
        temp = temp->next.get();
    }

    //initialize all member variables
    temp = ll.head.get();

    //copy all the nodes from the source
    while(temp != nullptr)
    {
        // and add them using insert_back()
        add(temp->str);
        temp = temp->next.get();
    }

  return *this;
}

LinkedList::empty()
{
	if(listSize == 0)
	{
		return True
	}
	return False
}

 bool add(const Val &v)
 {
 	//Create New Node
	unique_ptr<Node> new_Node {make_unique<Node>(v)};

    //check if empty
	if (empty())
	{
        //front = back = new_Node;
        head -> next = move(newItem);
        listSize++;
        return True;
    }

	else
	{
		temp = head.get();

		while(temp != nullptr)
		{
        	temp = temp->next.get();
		}

		new_Node->next = move(temp);
        temp = move(new_Node);
	}

	listSize++;
	return True;
 }