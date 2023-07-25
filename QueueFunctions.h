#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node {
	T data;
	Node<T>* nextPtr;
};

template <typename T>
class Queue {
private:
	Node<T>* first;
	Node<T>* last;

public:
	Queue();
	~Queue();
	void enQueue(T d);
	T deQueue();
	T peek();
	bool isEmpty ();
	void countQueue();
	void printQueue();
};

template <typename T>
Queue<T>::Queue() {
	first = nullptr;
	last = nullptr;
}

template <typename T>
void Queue<T>::enQueue(T d) {
	// create node
	Node<T>* newNode = new Node<T>;
	newNode->data = d;
	newNode->nextPtr = nullptr;

	//add to empty queue
	if (first == nullptr) {
		first = newNode;
		last = newNode;
	}
	//add to end of queue
	else {
		last->nextPtr = newNode;
		last = newNode;
	}
}

template <typename T>
T Queue<T>::deQueue() {
	//check if empty 
	T tempData;
	if (first == nullptr) {
		return tempData;
	}
	//Return and remove front of queue
	else {
		Node<T>* delNode = first;
		tempData = first->data;
		first = first->nextPtr;
		delete delNode;
		delNode = nullptr;
		return tempData;
	}
}

template <typename T>
T Queue<T>::peek() {
	//check if empty
	T tempData;
	if (first == nullptr) {
		return tempData;
	}
	//Return front element without deleting
	else {
		tempData = first->data;
		return tempData;
	}
}

template <typename T>
bool Queue<T>::isEmpty() {
	T tempData;
	if (first == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

template <typename T>
Queue<T>::~Queue() {
	//Destructor 
	Node<T>* tempNode = first;
	Node<T>* delNode = first;
	while (tempNode != nullptr) {
		tempNode = tempNode->nextPtr;
		delete delNode;
		delNode = tempNode;
	}
}

template <typename T>
void Queue<T>::countQueue() {
	int count = 0;
	Node<T>* tempNode = first;
	while (tempNode != nullptr) {
		count += 1;
		tempNode = tempNode->nextPtr;
	}
	cout << count;
}

template <typename T>
void Queue<T>::printQueue() {
	Node<T>* tempNode = first;
	while (tempNode != nullptr) {
		cout << tempNode->data << endl;
		tempNode = tempNode->nextPtr;
	}
}