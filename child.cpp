#ifndef CHILD_CPP_
#define CHILD_CPP_
#include <iostream>
#include <string>
// #include "child.h"
using namespace std; 

Child::Child()
{
	lastname_ = "";
	firstname_ = "";
	age_ = 0;
}

Child::Child(string firstname, string lastname, int age) : firstname_(firstname), lastname_(lastname), age_(age) 
{
}

// > overloaded operator
bool Child::operator>(const Child& rhs) const
{
	if (lastname_.compare(rhs.lastname_) > 0)
	{
		return true;
	}
	else if (lastname_.compare(rhs.lastname_) < 0)
	{
		return false; 
	}
	if (firstname_.compare(rhs.firstname_) > 0)
	{
		return true;
	}
	else if (firstname_.compare(rhs.firstname_) < 0)
	{
		return false; 
	}
	if (age_ > rhs.age_)
	{ 
		return true;
	}
	else if (rhs.age_ > age_)
	{
		return false;
	}
	
	return false; 	
}

// < overloaded operator
bool Child::operator<(const Child& rhs) const
{
	if (lastname_.compare(rhs.lastname_) < 0)
	{
		return true;
	}
	else if (lastname_.compare(rhs.lastname_) > 0)
	{
		return false; 
	}
	if (firstname_.compare(rhs.firstname_) < 0)
	{
		return true;
	}
	else if (firstname_.compare(rhs.firstname_) > 0)
	{
		return false; 
	}
	if (age_ < rhs.age_)
	{ 
		return true;
	}
	else if (rhs.age_ < age_)
	{
		return false;
	}
	return false; 	
}

// == overloaded operator
bool Child::operator==(const Child& rhs) const
{
	return((firstname_ == rhs.firstname_) && (lastname_ == rhs.lastname_) && (age_ == rhs.age_));
}

// != overloaded operator
bool Child::operator!=(const Child& rhs) const
{
	return((firstname_ != rhs.firstname_) || (lastname_ != rhs.lastname_) || (age_ != rhs.age_));
}

// += overloaded operator
Child& Child::operator+=(const Child& rhs)
{
	lastname_ = lastname_ + rhs.lastname_;
	firstname_ = firstname_ + rhs.firstname_;
	age_ = age_ + rhs.age_; 
	return *this;
}

// + overloaded operator
Child Child::operator+(const Child& rhs) const
{
	Child result = *this;
	result += rhs;
	return result;
}

// = overloaded operator
Child& Child::operator=(const Child& rhs)
{
	lastname_ = rhs.lastname_;
	firstname_ = rhs.firstname_;
	age_ = rhs.age_;
	return *this;
}

// >> overloaded operator
ostream& operator<<(ostream& stream, const Child& child)
{	
	stream << child.firstname_ << child.lastname_ << child.age_; 
	return stream;
}
#endif
 