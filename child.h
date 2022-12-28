#ifndef CHILD_H_
#define CHILD_H_
#include <iostream>
#include <string>
using namespace std;

class Child 
{
public:
	// Constructors
    Child(); 
	Child(string firstname, string lastname, int age);

	// Overloaded Operators
    // >> 
    friend ostream& operator<<(ostream& stream, const Child& list); 

    // >
    bool operator>(const Child& rhs) const;

    // <
    bool operator<(const Child& rhs) const;

    // +
    Child operator+(const Child& rhs) const;

    // =
    Child& operator=(const Child& rhs);

    // +=
    Child& operator+=(const Child& rhs);

    // == 
    bool operator==(const Child& rhs) const;

    // !=
    bool operator!=(const Child& rhs) const;

private:
    int age_;
    string firstname_;
    string lastname_; 
};
#include "child.cpp"
#endif 