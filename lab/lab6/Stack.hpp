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



// Global function ostream
template <typename T>
ostream& operator<<(ostream& os, const Stack<T>& obj){ // print stack
	Stack<T> copy = obj;
	for(int i = 0; i < obj.size() - 1; i++){
		os<<copy--<<endl;
	}
	os<<copy--;
	return os;
}
