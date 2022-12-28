#include "child.h"


//Consturctors and Desctructor

Child::Child()
{
	age_ = 0;
}

Child::Child(string first_name, string last_name, int a)
{
	first_name_ = first_name;
	last_name_ = last_name;
	age_ = a;
}

Child::Child(string first_name, string last_name)
{
	first_name_ = first_name;
	last_name_ = last_name;
	age_ = 0;
}

string Child::name() const
{
	return (first_name_ + last_name_);
}

int Child::age() const
{
	return age_;
}

void Child::set_first(const string &name)
{
	first_name_ = name;
}

void Child::set_last(const string &name)
{
	last_name_ = name;
}

Child::~Child()
{
}

// Operator Overloads

bool Child::operator==(const Child &c) const
{
	return ((first_name_ == c.first_name_) &&
		(last_name_ == c.last_name_) &&
		(age_ == c.age_));
}

bool Child::operator!=(const Child &c) const
{
	return !(*this == c);
}

bool Child::operator<(const Child &c) const
{
	if (last_name_ == c.last_name_)
	{
		return (first_name_ < c.first_name_);
	}
	else
	{
		return (last_name_ < c.last_name_);
	}
}

bool Child::operator<=(const Child &c) const
{
	if (last_name_ == c.last_name_)
	{
		return (first_name_ <= c.first_name_);
	}
	else
	{
		return (last_name_ <= c.last_name_);
	}
}

bool Child::operator>=(const Child &c) const
{
	if (last_name_ == c.last_name_)
	{
		return (first_name_ >= c.first_name_);
	}
	else
	{
		return (last_name_ >= c.last_name_);
	}
}

bool Child::operator>(const Child &c) const
{
	if (last_name_ == c.last_name_)
	{
		return (first_name_ > c.first_name_);
	}
	else
	{
		return (last_name_ > c.last_name_);
	}
}

ostream& operator<<(ostream &stream, const Child &c)
{
	stream << c.first_name_ << c.last_name_ << c.age_;
	return stream;
}

istream& operator>>(istream &stream, Child &c)
{
	stream >> c.first_name_;
	stream >> c.last_name_;
	stream >> c.age_;
	return stream;
}
