//
// Created by Arya on 2016-11-06.
//
#include "LinkedList.h"
//LinkedList::LinkedList()
//{
//	head = nullptr;
//    listSize = 0;
//}

LinkedList::LinkedList(const LinkedList &ll)
{
	head = nullptr;
    listSize = 0;
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
	Node * temp = head.get();
	while (temp != nullptr)
    {
        remove(temp->str);
        temp = temp->next.get();
    }
}

LinkedList& LinkedList::operator=(const LinkedList &ll)
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

bool LinkedList::empty() const
{
    return listSize == 0;
}

vector<Val> LinkedList::get() const
{
    vector<Val> stringSet;

    auto obs = head.get();
    while(obs != nullptr)
    {
        stringSet.push_back(obs->str);
        obs = obs->next.get();
    }
    return stringSet;
}

bool LinkedList::add(const Val &v)
{
 	//Create New Node
	unique_ptr<Node> new_Node {make_unique<Node>(v)};

    //check if empty
	if (empty())
	{
        //front = back = new_Node;
        head = move(new_Node);
        head->next = nullptr;
        listSize++;
        return true;
    }

	else
	{
        Node * current = head.get();
		auto obs = head.get();


		while(obs != nullptr)
		{
            current = obs;
        	obs = current->next.get();
		}

        current->next = move(new_Node);
	}

	listSize++;
    return true;
}

bool LinkedList::remove(const Val &v)
{
    if ( empty())
    {
        return false;
    }

    if(!search(v))
    {
        return  false;
    }

    Node * previouselement = head.get();
    Node * currentelement = head.get();

    while(currentelement!=nullptr)
    {
        if (currentelement->str == v)
        {
            previouselement->next = move(currentelement->next);
            listSize--;
            return true;
        }
        previouselement = currentelement;
        currentelement = currentelement->next.get();
    }
    return false;
}

bool LinkedList::search(const Val &v) const
{
    auto obs = head.get();
    while(obs != nullptr)
    {
        if(obs->str == v)
        {
            return true;
        }
        obs = obs->next.get();
    }
    return false;
}

void LinkedList::printList() const
{
    auto obs = head.get();
    cout << ( "front->" ) ;
    while ( obs != nullptr )
    {
        if ( obs -> next == nullptr )
        {
            cout << " " <<( obs -> str ) << " " ;
        }
        else
        {
            cout << " " <<( obs -> str ) << " " ;
            cout<< ("->");
        }
        obs = obs->next.get();
    }
    cout << "<-back\n" ;
    cout << ( "\n" ) ;
}