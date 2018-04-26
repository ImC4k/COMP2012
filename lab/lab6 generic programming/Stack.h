#ifndef STACK_H
#define STACK_H

using namespace std;
const int STACK_CAPACITY = 64;

template <typename T>
class Stack{
public:
	Stack() {};
	~Stack() {};

	/****** START YOUR DELARATION FOR PART 1 HERE ******/

	// ACCESSOR member functions:
	bool empty() const;    // Check if the stack is empty
	bool full() const;	   // Check if the stack is full
	int size() const;	   // Give the number of data currently stored

	// TODO: Overload operator "~" to retrieve the top item from the stack
	T operator~() const;
	// TODO: Overload operator "==" to check the equality of stack objects
	bool operator==(const Stack<T>& another);
	// TODO: Overload operator "<<" to show the items stored in the stack object

	// MUTATOR member functions:

	// TODO: Overload operator "+=" to add a new item to the top
	Stack<T>& operator+=(T item);
	// TODO: Overload operator "--" to remove the top item from the stack
	//       and return the new top item (** SYNTAX: Stack<int> A; --stack; **)
	T operator--(int);
	// TODO: Overload operator "--" to return the top item and remove it
	//       from the stack (** SYNTAX: Stack<int> A; stack--; **)
	T& operator--();
	/******* END YOUR DELARATION FOR PART 1 HERE *******/

private:
	T data[STACK_CAPACITY];   // Use an array to store the data
	int top_index {-1};		    // Start from 0; -1 when empty
};

/****** START YOUR IMPLEMENTATION FOR PART 1 HERE ******/

#include "Stack.hpp"

/******* END YOUR IMPLEMENTATION FOR PART 1 HERE *******/
#endif
