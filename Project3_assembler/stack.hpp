//
// File: stack.hpp
//
// Programmer:
// Date:        Spring 2024
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//
#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_

#include <iostream>
#include <new>
#include <cassert>
//#include "../string/string.hpp"

using namespace std;


template<typename T> 
class Node {
public:
	//////////////////////// ADDED ////////////////////////
	Node() : next(0) {};
	Node(const T& x) : data(x), next(0) {};
	
	T data;
	Node<T> *next;
	///////////////////////////////////////////////////////
};


// CLASS INV:
//
template <typename T>
class stack {
public:
              stack     ();
              stack     (const stack<T>&);
              ~stack    ();
    void      swap      (stack<T>&);
    stack<T>& operator= (stack<T>);
    
	bool      empty     () const;
	bool      full      () const;
	T         top       () const;
	T         pop       ();
	void      push      (const T&);

	void print();

private:
	Node<T>   *tos;
};



template <typename T>
stack<T>::stack() {
	tos = 0;
}

template <typename T>
stack<T>::stack(const stack<T>& actual) {
	Node<T> *temp = actual.tos;
    Node<T> *bottom = 0;
    tos = 0;

    while (temp != 0) {
        if (tos == 0) {
            tos = new Node<T>(temp->data);
            bottom = tos;
        } else {
            bottom->next = new Node<T>(temp->data);
            bottom = bottom->next;
        }
        temp = temp->next;
    }
}

template <typename T>
stack<T>::~stack() {
	Node<T> *temp;

	while (tos != 0) {
		temp = tos;
		tos = tos->next;
		delete temp;
	}
}

template <typename T>
void stack<T>::swap(stack<T>& rhs) {
	Node<T> *temp = this->tos;
	this->tos = rhs.tos;
	rhs.tos = temp;
}

template <typename T>
stack<T>& stack<T>::operator= (stack<T> rhs) {
	swap(rhs);
    return *this;
}

template <typename T>
bool stack<T>::empty() const {
	return tos == nullptr;
}

// ****** MODIFIED AS ADDING NOTHROW ****** //
template <typename T>
bool stack<T>::full() const {

	Node<T> *noThrow_temp = new(std::nothrow) Node<T>(); // return no pointer or not
	// noThrow or temp
	
	// no pointer returns true
	// otherwise returns false

	// == 0 ->return true -- return noThrow

	if (noThrow_temp == nullptr) {
		return true;
	} else {
		delete noThrow_temp; // **** if no delete here, then memory leaks happen **** //
		return false;
	}
}

template <typename T>
T stack<T>::top() const {
	assert(!empty());

	return tos->data;
}

template <typename T>
T stack<T>::pop() {
	assert(!empty());

	T data_result = tos->data;
	Node<T>* temp = tos;
	tos = tos->next;
	
	delete temp;
	return data_result;
}

template <typename T>
void stack<T>::push(const T& data) {
	assert(!full());

	if (tos == 0) {
		tos = new Node<T>(data);
	} else {
		// POINTER FOR NODE_TEMP SHOULD BE IN THE FUNCTION STACK. NOT IN HEAP. 
		Node<T>* temp = new Node<T>(data);
		temp->next = tos;
		tos = temp;
	}
}


template <typename T>
void stack<T>::print() {
	Node<T> *temp_tos = tos;
	
	while (temp_tos != nullptr) {
		std::cout << temp_tos->data << std::endl;
		temp_tos = temp_tos->next;
	}
}

#endif
