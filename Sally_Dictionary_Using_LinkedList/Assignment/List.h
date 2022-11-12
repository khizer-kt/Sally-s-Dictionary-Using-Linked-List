//MAIN LINKED LIST 
#include <iostream>
#include "Dictionary.h"
#include <assert.h> //assert
using namespace std;
template <typename T>
class ListNode {   //NODE
public:
    Dictionary data;
    ListNode* next;
};

//PASTE YOUR LINKED LIST CODE HERE
template <typename T>
class SinglyLinkedList
{
public:
	SinglyLinkedList() = default;
	~SinglyLinkedList() //DESTRUCTOR
	{
		Clear();
	}
	SinglyLinkedList(const SinglyLinkedList& source)
	{
		*this = source;
	}
	void operator=(const SinglyLinkedList& points)
	{
		if (this != &points)
		{
			Clear();

			const ListNode* pointsptr = points.start;
			for (int i = 0; pointsptr; i++) // loop until pointsptr becomes null
			{
				Insert(pointsptr->data, i);
				pointsptr = pointsptr->next;
			}
		}
	}
	bool IsEmpty() const
	{
		return !start; // if start hold nothing return true
	}
	int GetLength() const
	{
		int count = 0;
		for (ListNode* var1 = start; var1; var1 = var1->next) // loop until var1 becomes null
		{
			count++;
		}
		return count;
	}
	bool Search(T d) const
	{
		for (ListNode* var1 = start; var1; var1 = var1->next) // loop until var1 becomes null
		{
			if (var1->data == d) return true;
		}
		return false;
	}

	void Insert(T d, int pos = 0)
	{
		assert(pos >= 0 && pos <= GetLength());
		if (pos == 0)
		{
			ListNode* newnode = new ListNode;
			newnode->data = d;
			newnode->next = start;
			start = newnode;
		}
		else
		{
			InsertAfter(d, start, pos - 1); // minus one sice insert after
		}
	}
	void Delete(T d)
	{
		ListNode* var1 = start;
		ListNode* last = NULL;
		while (var1 && var1->data != d) // loop until var1 becomes null
		{
			last = var1;
			var1 = var1->next;
		}

		if (var1) 
		{
			if (last) 
			{
				last->next = var1->next;
				delete var1;
			}
			else 
			{
				start = var1->next;
				delete var1;
			}
		}
	}
	void Clear()
	{
		for (ListNode* var1 = start; var1;) // loop until var1 becomes null
		{
			ListNode* temp = var1;
			var1 = var1->next;
			delete temp;
		}
		start = NULL;
	}

protected:
	typedef ListNode<T> ListNode;

	// Since it will insert after a node, pos acts like pos + 1 (Insertion happens after specified pos)  
	void InsertAfter(T d, ListNode* node, int pos)
	{
		if (pos == 0)
		{
			ListNode* newnode = new ListNode;
			newnode->data = d;
			newnode->next = node->next;
			node->next = newnode;
		}
		else
		{
			InsertAfter(d, node->next, pos - 1);
		}
	}
	ListNode* start = NULL;
};
