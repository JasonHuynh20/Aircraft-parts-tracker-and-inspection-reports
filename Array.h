
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template<class T>
class Array {
	template<class V>
	friend ostream& operator<<(ostream&, const Array<V>&);
	public:
		//constructor
		Array();

		//destructor
		~Array();

		//other
		void add(T);
		T get(int index);
		int getSize();
		bool isFull();
		T operator[](int);

	private:
		int size;
		T *elements;

};

//constructor/destructor-----------------------------------------------------
template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	size = 0;
}

template <class T>
Array<T>::~Array(){
	delete [] elements;
}


// functions--------------------------------------------------------------
template <class T>
void Array<T>::add(T t){
	if (size >= MAX_ARR)   return;
  	elements[size++] = t;
}

template <class T>
int Array<T>::getSize(){
	return size;
}

template <class T>
bool Array<T>::isFull(){
	return size >= MAX_ARR;
}

template<class T>
T Array<T>::operator[](int index){
	if (index < 0 || index >= size) {
		cout<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template<class V>
ostream& operator<<(ostream& output, const Array<V>& array){
	output << endl;

	for(int i = 0; i < array.size; i++){
		output << array.elements[i];
	}
  	output<< endl;


  	return output;
}

template <class T>
T Array<T>::get(int index){
	return elements[index];
}

#endif
