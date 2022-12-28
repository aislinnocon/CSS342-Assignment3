#ifndef LIST342_H_
#define LIST342_H_
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template<typename T>
struct Node
{
	T data;
	// T *data
	Node<T>* next;
};

template<class T>
class List342
{
public:
	// Constructors
	List342<T>();
	List342<T>(const List342<T>& arr2);
	~List342<T>();

	// Actions
	bool BuildList(string file_name);
	bool Remove(T target, T& result);
	bool Peek(T target, T& result) const;
	bool Insert(T* obj); 
	bool isEmpty() const;
	void DeleteList();
	bool Merge(List342<T>& list1);

	// Overloaded Operators
	// +
	List342<T> operator+(const List342<T>& list) const;

	// +=
	List342<T>& operator+=(const List342<T>& list);

	// = 
	List342<T>& operator=(const List342<T>& source);

	// ==
	bool operator==(const List342<T>& list) const;

	// !=
	bool operator!=(const List342<T>& list) const;
	
	// << 
	template <typename W> 
	friend ostream& operator<<(ostream& stream, const List342<W>& list); 

private:
	Node<T>* head_;
};

// Default constructor
template<typename T>
List342<T>::List342() : head_(nullptr)
{
}

// Copy constructor
template<typename T>
List342<T>::List342(const List342& arr2) : head_(nullptr)
{
	*this = arr2;
}

// Deconstructor
template<typename T>
List342<T>::~List342()
{
	DeleteList(); 
}

// Inserts given item into the list
template<typename T>
bool List342<T>::Insert(T* obj) 
{
	Node<T> *temp = new Node<T>; 
    temp->data = *obj;
	temp->next = nullptr; 
	if (head_ == nullptr)
	{
		head_ = temp;
		return true;
	}
	if (*obj < head_->data)
	{
		temp->next = head_;
		head_ = temp;
		return true;
	}
	if (head_->data == *obj)
	{
		delete temp; 
		return false;
	}
	Node<T>* pNode = head_;
	while ((pNode->next != NULL))
	{
		if (pNode->data < *obj && (pNode->next)->data > *obj)
		{	
			temp->next = pNode->next;
			pNode->next = temp;
			return true; 
		}
		else if (pNode->data == *obj || pNode->next->data == *obj)
		{
			return false; 
		}
		pNode = pNode->next;
	}
	temp->next = pNode->next;
	pNode->next = temp;
	return true;
} 

// Removes given item from the list and returns the result after the removal 
template<typename T>
bool List342<T>::Remove(T target, T& result)
{
	Node<T>* temp = head_;
	if (head_ == nullptr)
	{
		return false;
	}
	if (head_->data == target) 
	{
		result = head_->data;
		temp = head_->next;
		delete head_; 
		head_ = temp; 
		return true; 
	}
	while (temp->next != nullptr)
	{
		if (temp->next->data != target)
		{
			temp = temp->next; 
		} 
		else
		{
			break; 
		}	
	}
	if(temp->next == nullptr)
    {
		return false; 
    }
	result = temp->next->data;
	Node<T>* temp_holder = temp->next; 
	temp->next = temp->next->next;
	delete temp_holder;
	return true;
}

// Checks if item is in list and returns the item
template<typename T>
bool List342<T>::Peek(T target, T& result) const
{
	Node<T>* temp = head_;
	if (head_ == nullptr)
	{
		return false;
	}
	if (head_->data == target) 
	{
		result = head_->data;
		temp = head_->next;
		return true; 
	}
	while (temp->next != nullptr)
	{
		if (temp->next->data != target)
		{
			temp = temp->next; 
		} 
		else
		{
			break; 
		}	
	}
	if(temp->next == nullptr)
    {
		return false; 
    }
	result = temp->next->data;
	Node<T>* temp_holder = temp->next; 
	return true;
}

// Merges two items together and creates a singular item from the two combined items
template<typename T>
bool List342<T>::Merge(List342<T>& list1)
{
	if (head_ == list1.head_)
	{
		return false; 
	} 
	*this += list1;
	list1.DeleteList();
	return true;
} 

// Checks if the list is empty
template<typename T>
bool List342<T>::isEmpty() const
{
	return head_ == nullptr; 
} 

// Deletes list
template<typename T>
void List342<T>::DeleteList()
{
	Node<T>* temp = head_; 
	while(temp != nullptr)
	{
		Node<T>* holder = temp;
		temp = temp->next; 
		delete holder; 
	}
	head_ = nullptr; 
}

// Builds a list from an inputted file 
template <typename T>
bool List342<T>::BuildList(string file_name)
{
	ifstream in_file;
	in_file.open(file_name);
	while (!in_file.eof())
	{
		T holder; 
		in_file >> holder;
		T *ptr = &holder;
		this->Insert(ptr);	
	}
	in_file.close();
	return true;
}

// << overloaded operator and prints out result when called
template<typename W>
ostream& operator<<(ostream& stream, const List342<W>& list)
{
	Node<W>* p_node = list.head_;
	while (p_node != nullptr)	
	{
		stream << p_node->data;
		p_node = p_node->next;
	}
	return stream;
}

// = overloaded operator (sets two lists equal to one another)
template<typename T>
List342<T>& List342<T>::operator=(const List342<T>& list)
{
	Node<T> *start;  
	Node<T> *end; 
	if (this == &list)
	{
		return *this;
	}
	if (list.head_ == nullptr)
	{
		this->DeleteList(); 
		return *this;
	}
	end = new Node<T>;
	end->data = (list.head_)->data;
	end->next = (list.head_)->next; 
	this->DeleteList(); 
	head_ = end; 
	start = (list.head_)->next;
	while (start != nullptr)
	{
		end->next = new Node<T>;
		end->next->data = start->data;
		end->next->next = start->next; 
		end = end->next;
		start = start->next;
	}
	return *this;
}

// += overloaded operator (adds list onto another list without altering the list which is inputted)
template<typename T>
List342<T>& List342<T>::operator+=(const List342<T>& list)
{
    Node<T> *temp = nullptr; 
	temp = list.head_;
    while (temp != nullptr)
    {
		T x = temp->data;
		T *ptr = &x;
		this->Insert(ptr); 
		temp = temp->next;
    } 
    return *this;
}

// + overloaded operator
template<typename T>
List342<T> List342<T>::operator+(const List342<T>& list) const
{
	List342 holder; 
    Node<T> *right = nullptr; // better syntax for preventing memory leak then setting New node
	Node<T> *left = nullptr; 
	right = list.head_;
	left = head_; 
    while (right != nullptr)
    {
		T x = right->data;
		T *ptr = &x;
		holder.Insert(ptr); 
		right = right->next;
    }
	while (left != nullptr)
    {
		T x = left->data;
		T *ptr = &x;
		holder.Insert(ptr); 
		left = left->next;
    }
    return holder;
}

// == overloaded operator
template<typename T>
bool List342<T>::operator==(const List342<T>& list) const
{
	Node<T> *lhs;
	Node<T> *rhs; 
	if ((this->isEmpty() && !list.isEmpty()) || (!this->isEmpty() && list.isEmpty()))
	{
		return false; 
	}
	if (head_->data != list.head_->data)
	{
		return false;
	}
	lhs = head_; 
	lhs->next = head_->next; 
	rhs = list.head_;
	rhs->next = head_->next;
	while (rhs != nullptr && lhs != nullptr)
	{
		if (rhs->data != lhs->data)
		{
			return false; 
		}
		rhs = rhs->next;
		lhs = lhs->next; 
	}
	if (lhs == nullptr && rhs == nullptr)
	{
		return true; 
	}
	return false;
}

// != overloaded operator
template<typename T>
bool List342<T>::operator!=(const List342<T>& list) const
{
	return !(*this == list);
}
#endif
