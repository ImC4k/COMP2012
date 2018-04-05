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
template <typename T>
bool Stack<T>::empty() const{ // emptiness
	return top_index == -1;
}

template <typename T>
bool Stack<T>::full() const{ // fullness
	return top_index == STACK_CAPACITY - 1;
}

template <typename T>
int Stack<T>::size() const{ // check size
	return top_index + 1;
}

template <typename T>
T Stack<T>::operator~() const{ // read top, no need to pop
	if(empty()){
		cerr<<"[ERROR] Stack is empty, returning a garbage value"<<endl;
		return T();
	}
	else{
		return data[top_index];
	}
}

template <typename T>
bool Stack<T>::operator==(const Stack<T>& another){ // check equality
	if(this->top_index != another.top_index){
		return false;
	}
	for(int i = 0; i <= top_index; i++){
		if(this->data[i] != another.data[i]){
			return false;
		}
	}
	return true;
}

template <typename T>
ostream& operator<<(ostream& os, const Stack<T>& obj){ // print stack
	Stack<T> copy = obj;
	for(int i = 0; i < obj.size() - 1; i++){
		os<<copy--<<endl;
	}
	os<<copy--;
	return os;
}

template <typename T>
Stack<T>& Stack<T>::operator+=(T item){ // push
	if(top_index >= STACK_CAPACITY - 1){
		cerr<<"[ERROR] Stack is full, can't add new value"<<endl;
		return *this;
	}
	data[++top_index] = item;
	return *this;
}

template <typename T>
T Stack<T>::operator--(int){ // traditional pop
	if(top_index == -1){
		cerr<<"[ERROR] Stack is empty, returning a garbage value"<<endl;
		return data[top_index];
	}
	return data[top_index--];
}

template <typename T>
T& Stack<T>::operator--(){ // move stack pointer and pop (pop second)
	if(top_index == -1 || top_index == 0){
		cerr<<"[ERROR] Stack is empty, returning a garbage value"<<endl;
		if(top_index == -1) return data[top_index];
	}
	return data[--top_index];
}



/******* END YOUR IMPLEMENTATION FOR PART 1 HERE *******/
#endif
