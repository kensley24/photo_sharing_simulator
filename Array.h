
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include "defs.h"

using namespace std;

template <class T>
class Array {

	public:
		//constructor
		Array();

		//destructor
		~Array();

		//other
		void add(T& a);
		bool remove(T& t);

		//T& get(int index);

		T& operator[](int index);
		const T& operator[](int index) const;
		Array<T>& operator+=(T& a);
		Array<T>& operator-=(T& a);

		void clear();

		int size() const;
		int getSize() const;
		bool isFull() const;

	private:
		int numElements;
		T* elements;

};

template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARRAY];
	numElements = 0;
}

template <class T>
Array<T>::~Array(){
	delete[] elements;
}

template <class T>
void Array<T>::add(T& a){
	if (numElements >= MAX_ARRAY)   return;
	//T* pointerA = new T(a);
  elements[numElements++] = a;
}

template <class T>
bool Array<T>::remove(T& t){
	int index = 0;
	while (index < numElements){
		if (t == elements[index]){
			--numElements;
			break;
		}
		++index;
	}
	T copy = elements[index];

	while (index < numElements){
		elements[index] = elements[index + 1];
		++index;
	}

	if(index == numElements){
		return false;
	}
	delete copy;

	return true;
}

template <class T>
int Array<T>::getSize() const{
	return numElements;
}

template <class T>
int Array<T>::size() const{
	return numElements;
}

template <class T>
bool Array<T>::isFull() const{
	return numElements >= MAX_ARRAY;
}

template <class T>
T& Array<T>::operator[](int index){
	if (index < 0 || index >= numElements) {
		cout<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}


template <class T>
const T& Array<T>::operator[](int index) const{
	if (index < 0 || index >= numElements) {
		cout<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}


template <class T>
Array<T>& Array<T>::operator+=(T& a){
	add(a);
	return *this;
}

template <class T>
Array<T>& Array<T>::operator-=(T& a){
	remove(a);
	return *this;
}

template <class T>
void Array<T>::clear(){
	//this might cause an issue idk
	/*
	for(int i = 0; i < numElements; i++){
		elements[i] = nullptr;
	}
	*/
	numElements = 0;
}

#endif
